/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il client invia una stringa e un codice di operazione (0, 1, 2, 3). 
Il server, in base al codice ricevuto, restituisce:

→ la stringa invertita
→ il numero di vocali contenute
→ la stringa contenente solo caratteri alfabetici
→ la stringa originale con tutte le vocali rimosse
*/
// SERVER

#include <ctype.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SERVERPORT 1450
#define DIM 100

int contaVocali(char *s){
    int count = 0;
    for(int i = 0; s[i]; i++){
        char c = tolower(s[i]);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            count++;
    }
    return count;
}

void inverti(char *s){
    int i = 0, j = strlen(s)-1;
    while(i < j){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++; j--;
    }
}

void soloAlfabetici(char *s){
    int j = 0;
    for(int i = 0; s[i]; i++){
        if(isalpha(s[i]))
            s[j++] = s[i];
    }
    s[j] = '\0';
}

void rimuoviVocali(char *s){
    int j = 0;
    for(int i = 0; s[i]; i++){
        char c = tolower(s[i]);
        if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'))
            s[j++] = s[i];
    }
    s[j] = '\0';
}

int main(int argc, char **argv){

    struct sockaddr_in servizio, remoto;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    char str[DIM];
    int codice;
    int socketfd, soa, fromlen = sizeof(servizio);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, fromlen);
    listen(socketfd, 10);

    for(;;){
        printf("Server in ascolto...\n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&remoto, &fromlen);

        read(soa, &codice, sizeof(codice));
        read(soa, str, sizeof(str));

        switch(codice){
            case 0:
                inverti(str);
                break;
            case 1:
                sprintf(str, "Numero vocali: %d", contaVocali(str));
                break;
            case 2:
                soloAlfabetici(str);
                break;
            case 3:
                rimuoviVocali(str);
                break;
            default:
                sprintf(str, "Errore: codice non valido");
        }

        write(soa, str, sizeof(str));
        close(soa);
    }

    return 0;
}

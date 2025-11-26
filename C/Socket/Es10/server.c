/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e, 
dopo aver effettuato i controlli opportuni, rispedisce al client quattro valori interi:
il numero di lettere,
il numero di cifre,
il numero di spazi,
il numero di caratteri speciali presenti nella stringa.*/
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

    void conta(char str[], int *lettere, int *cifre, int *spazi, int *caratteri_speciali){
        for(int i = 0; i < strlen(str); i++){
            if(isalpha(str[i])){
                (*lettere)++;
            }else if(isdigit(str[i])){
                (*cifre)++;
            }else if(str[i] == ' '){
                (*spazi)++;
            }else{
                (*caratteri_speciali)++;
            }
        }
    }


int main(){

    struct sockaddr_in servizio, remoto;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl (INADDR_ANY);
    servizio.sin_port = htons (SERVERPORT);

    char str[DIM], risposta[DIM];
    int socketfd,soa, fromlen = sizeof(servizio), lettere = 0, cifre = 0, spazi = 0, caratteri_speciali = 0;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, fromlen);
    listen(socketfd, 10);

    for(;;){
        printf("Server in ascolto...\n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&remoto, &fromlen);
        read(soa, str, sizeof(str));

        conta(str, &lettere, &cifre, &spazi, &caratteri_speciali);
        sprintf(risposta, "Lettere: %d, Cifre: %d, Spazi: %d, Caratteri speciali: %d", lettere, cifre, spazi, caratteri_speciali);
        
        write(soa, risposta, sizeof(risposta));
   
        close(soa);
    }

    return 0;
}
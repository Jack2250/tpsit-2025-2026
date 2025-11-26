/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e, 
dopo i controlli necessari, restituisce al client la stringa da cui sono stati rimossi tutti i caratteri duplicati consecutivi.
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

void rimuoviDuplicati(char *str){
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] != str[i+1]){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main(int argc, char **argv){

    struct sockaddr_in servizio, remoto;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    char str[DIM];
    int socketfd, soa, fromlen = sizeof(servizio);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, fromlen);
    listen(socketfd, 10);

    for(;;){
        printf("Server in ascolto...\n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&remoto, &fromlen);
        read(soa, str, sizeof(str));

        rimuoviDuplicati(str);

        write(soa, str, sizeof(str));

        close(soa);
    }

    return 0;
}

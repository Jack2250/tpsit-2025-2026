/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il client invia una stringa e un codice di operazione (0, 1, 2, 3). 
Il server, in base al codice ricevuto, restituisce:

→ la stringa invertita
→ il numero di vocali contenute
→ la stringa contenente solo caratteri alfabetici
→ la stringa originale con tutte le vocali rimosse
*/

// CLIENT 
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

int main(int argc, char **argv){

    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    char str[DIM];
    int codice, socketfd;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    printf("Inserisci una stringa: ");
    scanf("%s", str);
    
    printf("Inserisci codice operazione (0-3): ");
    scanf("%d", &codice);

    write(socketfd, &codice, sizeof(codice));
    write(socketfd, str, sizeof(str));

    read(socketfd, str, sizeof(str));

    printf("Risultato dal server: %s\n", str);

    close(socketfd);
    return 0;
}


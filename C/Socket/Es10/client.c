/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e, 
dopo aver effettuato i controlli opportuni, rispedisce al client quattro valori interi:
il numero di lettere,
il numero di cifre,
il numero di spazi,
il numero di caratteri speciali presenti nella stringa.*/
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

int main(){

    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    char str[DIM];
    int socketfd;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    printf("Inserisci una stringa: ");
    scanf("%[^\n]", str);

    write(socketfd, str, sizeof(str));
    read(socketfd, str, sizeof(str));

    printf("Stringa ricevuta dal server: %s\n", str);

    close(socketfd);
    return 0;
}
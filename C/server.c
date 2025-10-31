#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#define SERVERPORT 1450

int main(int agrc, char ** argv){
    //1.Dichiarazione necessaria definizione della struttura
    struct sockaddr_in server;

    //Socket file descriptor (che è variabile di tipo intero)
    int socketfd; //Identificatore della socket
    char str1[] = "ciao", str2[30]; //Dati della socket
    int soa;
    //Settaggio del socket locale

    //Valorizzazione dei membri della struttura
    server.sin_family = AF_INET; //Dominio
    server.sin_addr.s_addr = htonl(INADDR_ANY); //Converte l'indirizzo in binario
    server.sin_port = htons(SERVERPORT); //Porta

    //Creo la socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    //Leghiamo l'indirizzo al transport end-point
    bind(socketfd, (struct sockaddr *)&server,sizeof(server)); 
    listen(socketfd, 10); //Può attendere fino a 10 clienti

    while(1){
        printf("Server in ascolto....\n");
        fflush(stdout); //Pulisco la socket o il canale di comunicazione
        soa = accept(socketfd, (struct sockaddr *)&server,sizeof(server));

    }

    return 0;
}

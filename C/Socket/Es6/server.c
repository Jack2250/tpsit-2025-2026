/*Esercizio 6
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input un
vettore di numeri e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al
Client il conteggio dei numeri pari e dei numeri dispari contenuti nel vettore.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define SERVERPORT 1450
#define DIM 20

int contaPari(int vet[]){
    int count = 0;
    for(int i = 0, i < sizeof(vet); i++){
        if((vet[i] % 2) == 0){
            count ++;
        }
    }
    return count;
}

int contaDispari(int vet[]){
    int count = 0;
    for(int i = 0, i < sizeof(vet); i++){
        if((vet[i] % 2) == 1){
            count ++;
        }
    }
    return count;
}


int main()
{
    struct sockaddr_in = servizio;
    int socketfd, fromlen = sizeof(servizio), vet [DIM];
    char risposta[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    
    if((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Chiamata fallita alla system call socket");
        exit(0);
    }
    
    if((bind(socketfd, (struct sockaddr*)&servizio, &fromlen)) == -1){
        printf("Chiamata fallita alla system call bind");
        exit(0);
    }
    
    if((listen(socketfd, 10)) == -1){
        printf("Chiamata fallita alla system call listen");
        exit(0);
    }
    
    for(;;){
        printf("Server in ascolto");
        
        if((soa = accept(socketfd, (struct sockaddr*)&servizio, &fromlen)) == -1){
            printf("Chiamata fallita alla system call accept");
            exit(0);
        }
        
        read(soa, vet, sizeof(vet));

        
        int controllo = 
        
        
        

        close(soa);
    }
    
    
    return 0;   
}
//SERVER
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

//Server: Socket, bind, listen, accept

int main()
{
    
    struct sockaddr_in servizio; 
    int socketfd, soa;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    
    if((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Chiamata fallita");
        exit(1);
    }
    
    if(bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) == -1){
        printf("Chiamata fallita");
        exit(1);
    }
    
    if(listen(socketfd, 10) == -1){
        printf("Chiamata fallita");
        exit(1);
    }
    
    for(;;){
        printf("Server in ascolto...\n");
        
        if((soa = accept(socketfd, (struct sockaddr*)&servizio, sizeof(servizio))) == -1){
            printf("Chiamata fallita");
            exit(1);
        }
        
        
        close (soa);
    }
    
    return 0;
}

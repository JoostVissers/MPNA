/* 
 * File:   main.c
 * Author: Joost
 *
 * Created on March 19, 2014, 10:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*
 * 
 */
int main(int argc, char** argv) {

    if(argc < 2){
        perror("Opdracht mis parameters");
        exit(EXIT_FAILURE);
    }
    
    int portNr;
    if((portNr = atoi(argv[1])) == 0){
        perror("Opgegeven portnummer: ");
        exit(EXIT_FAILURE);        
    }

    int sockfd;

    if((sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0){
        perror("fout bij socket");
        exit(EXIT_FAILURE);
    }

    int conrtn;

    struct sockaddr_in socketAddr;

    if(inet_aton("127.0.0.1",&socketAddr.sin_addr) == 0){
        perror("Fout bij inet_aton");
        exit(EXIT_FAILURE);
    }

    socketAddr.sin_family = AF_INET;
    socketAddr.sin_port = htons(portNr); //7

    if((conrtn = connect(sockfd,(struct sockaddr*)&socketAddr,sizeof(socketAddr)) < 0 )){
        perror("Fout bij connect");
        exit(EXIT_FAILURE);
    }

    

    char sendBuffer[] = "Hallo";

    if(send(sockfd, sendBuffer, sizeof(sendBuffer),MSG_CONFIRM ) < 0){
        perror("Send ");
        exit(EXIT_FAILURE);
    }

    //sleep(20);

    char recvBuffer[200] = {};

    if(recv(sockfd, recvBuffer, sizeof(recvBuffer),MSG_CONFIRM ) < 0){
        perror("Recieve ");
        exit(EXIT_FAILURE);
    }

    printf("%s\n",recvBuffer);

    return (EXIT_SUCCESS);
}


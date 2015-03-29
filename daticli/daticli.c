/* 
 * File:   main.c
 * Author: Joost
 *
 * Created on March 13, 2014, 3:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*
 * 
 */
int main(int argc, char** argv) {

    //day time service ( port 13 ) tcp of udp
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
    socketAddr.sin_port = htons(13);
   
    if((conrtn = connect(sockfd,(struct sockaddr*)&socketAddr,sizeof(socketAddr)) < 0 )){
        perror("Fout bij connect");
        exit(EXIT_FAILURE);
    }
    
    char buffertje[200] = {};
    
    recv(sockfd, buffertje, sizeof(buffertje),MSG_DONTWAIT );

    printf("%s\n",buffertje);

    return (EXIT_SUCCESS);
}


/* 
 * File:   ghbname.c
 * Author: Joost Vissers
 * v: 1
 * 
 * Created on March 6, 2014, 10:30 AM
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

/*
 *
 */
int main(int argc, char** argv) {

    char ip[] = {"8.8.8.8"};

    struct hostent *host;
    struct in_addr adress;

    if((inet_aton(ip,&adress)) == 0){
        herror("fout: ");
        exit(EXIT_FAILURE);
    }

    if((host = gethostbyaddr(&adress,sizeof(adress),AF_INET)) == NULL){
        herror("fout: ");
        exit(EXIT_FAILURE);
    }
    else{
        
        printf("Hostname: %s\nIp adress: %s\n",(host->h_name),(inet_ntoa(adress)));
    }

    exit(EXIT_SUCCESS);
}
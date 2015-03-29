/* 
 * File:   tcpsrv4.c
 * Author: Joost Vissers
 *
 * Created on March 24, 2014, 6:49 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>


void *threadClient(void * arg);

/*
 *
 */
int main(int argc, char** argv) {

    if (argc < 2) {
        perror("Opdracht mis parameters");
        exit(EXIT_FAILURE);
    }

    int portNr;
    if ((portNr = atoi(argv[1])) == 0) {
        perror("Opgegeven portnummer: ");
        exit(EXIT_FAILURE);
    }

    int listenSockFD;

    if ((listenSockFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Listen sock : ");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in srvAdress; //= malloc(sizeof (struct sockaddr_in));

    srvAdress.sin_addr.s_addr = INADDR_ANY;
    srvAdress.sin_family = AF_INET;
    srvAdress.sin_port = htons(portNr);

    if (bind(listenSockFD, ((struct sockaddr*) &srvAdress), sizeof (struct sockaddr)) < 0) {
        perror("Bind: ");
        exit(EXIT_FAILURE);
    }

    int backLog = 20;

    if (listen(listenSockFD, backLog) < 0) {
        perror("Listen ");
        exit(EXIT_FAILURE);
    }

    for (;;) {

        struct sockaddr_in clientInfo;

        socklen_t size = sizeof (struct sockaddr_in);

        int clientSock;

        //printf("ListenSockFD: %i\n",listenSockFD);

        if ((clientSock = accept(listenSockFD, ((struct sockaddr*) &clientInfo), &size)) < 0) {
            perror("Accept ");
            exit(EXIT_FAILURE);
        }

        printf("\nConnection accepted with client\nIP %s\nPort %i\n", inet_ntoa(clientInfo.sin_addr), ntohs(clientInfo.sin_port));

        pthread_t thread;

        if ((pthread_create(&thread, NULL, threadClient, &clientSock) != 0)) {
            perror("pthread_create \n");
            exit(EXIT_FAILURE);
        }

        if (pthread_detach(thread) != 0) {
            perror("pthread_detach ");
            exit(EXIT_FAILURE);
        }

    }

    //free(srvAdress);

    return (EXIT_SUCCESS);
}

void *threadClient(void * arg) {

    int clientSockFD = *((int*) (arg));

    char buffer[8192] = {};

    int bytesRecv = 0;
    int bytesSent = 0;

    int procesrecv = 0;
    int processent = 0;

    int teller = 0;

    while ((bytesRecv = read(clientSockFD, buffer, sizeof (buffer))) != 0) {

        procesrecv = procesrecv + bytesRecv;
        if (bytesRecv == -1) {
            perror("Recieve ");
            exit(EXIT_FAILURE);
        }
        printf("bytes recv %i\n", bytesRecv);
        if ((bytesSent = write(clientSockFD, buffer, bytesRecv)) == -1) {
            perror("Send ");
            exit(EXIT_FAILURE);
        }
        printf("bytes sent %i\n", bytesSent);
        processent = processent + bytesSent;

        teller++;
    }

    printf("Bytes recieved: %i\nBytes sent: %i\nMessage: %s\n", bytesRecv, bytesSent, buffer);

    if (close(clientSockFD) < 0) {
        perror("Close thread ");
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);
}



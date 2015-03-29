/* 
 * File:   udpsrv.c
 * Author: Carel
 *
 * Created on March 24, 2014, 9:21 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

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

    if ((listenSockFD = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("Listen sock : ");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in srvAdress; // = malloc(sizeof (struct sockaddr_in));

    srvAdress.sin_addr.s_addr = INADDR_ANY;
    srvAdress.sin_family = AF_INET;
    srvAdress.sin_port = htons(portNr);

    //vullen zeros

    if (bind(listenSockFD, ((struct sockaddr*) &srvAdress), sizeof (struct sockaddr)) < 0) {
        perror("Bind: ");
        exit(EXIT_FAILURE);
    }

    for (;;) {

        struct sockaddr_in clientInfo;

        socklen_t size = sizeof (struct sockaddr_in);

        //printf("ListenSockFD: %i\n",listenSockFD);

        char buffer[8192] = {};

        int bytesRecv = 0;
        int bytesSent = 0;

        int procesrecv = 0;
        int processent = 0;

        int teller = 0;

        while ((bytesRecv = recvfrom(listenSockFD, &buffer, sizeof (buffer), MSG_WAITALL, ((struct sockaddr*) &clientInfo), &size)) != 0) {
            procesrecv = procesrecv + bytesRecv;
            if (bytesRecv == -1) {
                perror("Recieve ");
                exit(EXIT_FAILURE);
            }
            //printf("bytes recv %i\n",bytesRecv);
            if ((bytesSent = sendto(listenSockFD, &buffer, bytesRecv, MSG_WAITALL, ((struct sockaddr*) &clientInfo), size)) == -1) {
                perror("Send ");
                exit(EXIT_FAILURE);
            }
            processent = processent + bytesSent;

            teller++;
        }

        printf("\nConnection accepted with client\nIP %s\nPort %i\n", inet_ntoa(clientInfo.sin_addr), ntohs(clientInfo.sin_port)); //inet_ntoa(clientStuff->sin_addr)
        printf("Bytes recieved: %i\nBytes sent: %i\nMessage: %s\n", bytesRecv, bytesSent, buffer);
        /*
                if (close(clientSock) < 0) {
                    perror("Close ");
                    exit(EXIT_FAILURE);
                }*/

    }

    //free(srvAdress);

    return (EXIT_SUCCESS);
}

/*
 * File:   tcpsrv3.c
 * Author: Joost
 *
 * Created on March 22, 2014, 12:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

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

    struct sockaddr_in *srvAdress = malloc(sizeof (struct sockaddr_in)); //freeenene

    //memset(&srvAdress,NULL ,sizeof(srvAdress));

    if ((inet_aton("127.0.0.1", &srvAdress->sin_addr)) == 0) {
        perror("Geen geldig adress : ");
        exit(EXIT_FAILURE);
    }
    srvAdress->sin_family = AF_INET;
    srvAdress->sin_port = htons(portNr);

    if (bind(listenSockFD, ((struct sockaddr*) srvAdress), sizeof (struct sockaddr)) < 0) {
        perror("Bind: ");
        exit(EXIT_FAILURE);
    }

    int backLog = 1;

    if (listen(listenSockFD, backLog) < 0) {
        perror("Listen ");
        exit(EXIT_FAILURE);
    }

    int maxFD = listenSockFD;
    int maxI = -1;
    int i;
    int clientsReady;
    int clientList[FD_SETSIZE]; //1024
    fd_set readSet;
    fd_set allSet;

    int clientSockFD; //descriptor
    struct sockaddr_in clientInfo;
    char buffer[500] = {};
    int bytesRecv;
    int bytesSent;

    for (i = 0; i < FD_SETSIZE; i++) {
        clientList[i] = -1;
    }

    FD_ZERO(&allSet);
    FD_SET(listenSockFD, &allSet);
    socklen_t size = sizeof (struct sockaddr_in);


    for (;;) {
        readSet = allSet; /* structure assignment */

        if ((clientsReady = select((maxFD + 1), &readSet, NULL, NULL, NULL)) < 0) {
            perror("Select ");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(listenSockFD, &readSet)) { /* new client connection */
            if ((clientSockFD = accept(listenSockFD, ((struct sockaddr*) &clientInfo), &size)) < 0) {
                perror("Accept ");
                exit(EXIT_FAILURE);
            }

            for (i = 0; i < FD_SETSIZE; i++) {
                if (clientList[i] < 0) {
                    clientList[i] = clientSockFD; /* save descriptor */
                    break;
                }
            }
            if (i == FD_SETSIZE) {
                perror("too many clients");
            }
            FD_SET(clientSockFD, &allSet); /* add new descriptor to set */
            if (clientSockFD > maxFD) {
                maxFD = clientSockFD; /* for select */
            }
            if (i > maxI) {
                maxI = i; /* max index in client[] array */
            }

            if (--clientsReady <= 0) {
                continue; /* no more readable descriptors */
            }
        }
        for (i = 0; i <= maxI; i++) {

            //printf("i = %i\n",i);
            if (clientList[i] < 0) {
                continue;
            }
            if (FD_ISSET(clientList[i], &readSet)) {

                if ((bytesRecv = read(clientList[i], &buffer, sizeof (buffer))) < 0) {
                    perror("Recieve ");
                    exit(EXIT_FAILURE);
                } else if (bytesRecv == 0) {
                    if (close(clientList[i]) < 0) {
                        perror("Close ");
                        exit(EXIT_FAILURE);
                    }
                    FD_CLR(clientList[i], &allSet);
                    clientList[i] = -1;
                } else {
                    if ((bytesSent = write(clientList[i], &buffer, bytesRecv)) < 0) {
                        perror("Send ");
                        exit(EXIT_FAILURE);
                    }
                    printf("\nConnection accepted with client\nIP %s\nPort %i\n", inet_ntoa(clientInfo.sin_addr), ntohs(clientInfo.sin_port)); //inet_ntoa(clientStuff->sin_addr)
                    printf("Bytes recieved: %i\nBytes sent: %i\nMessage: %s\n", bytesRecv, bytesSent, buffer);

                }
                if (--clientsReady <= 0) {
                    break;
                }
            }
        }
    }

    free(srvAdress);

    return (EXIT_SUCCESS);
}





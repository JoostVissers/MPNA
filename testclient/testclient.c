/* 
 * File:   testclient.c
 * Author: Joost Vissers
 *
 * Created on March 29, 2014, 11:57 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <wait.h>
#include <time.h>

/*
 *
 */
int main(int argc, char** argv) {

    if (argc < 7) {
        printf("Opdracht mis parameters\n");
        exit(EXIT_FAILURE);
    }

    char ipadress[30] = {}; //
    strcpy(ipadress, argv[1]);
    int portNr; //
    int nClients;
    int nRequests;
    int nBytes;

    if ((portNr = atoi(argv[2])) == 0) {
        perror("Opgegeven portnummer: ");
        exit(EXIT_FAILURE);
    }

    if ((nClients = atoi(argv[4])) == 0) {
        perror("nClients: ");
        exit(EXIT_FAILURE);
    }

    if ((nRequests = atoi(argv[5])) == 0) {
        perror("nRequests: ");
        exit(EXIT_FAILURE);
    }

    if ((nBytes = atoi(argv[6])) == 0) {
        perror("nBytes: ");
        exit(EXIT_FAILURE);
    }

    int conrtn;

    struct sockaddr_in socketAddr;

    if (inet_aton(ipadress, &socketAddr.sin_addr) == 0) {
        perror("Fout bij inet_aton");
        exit(EXIT_FAILURE);
    }

    socketAddr.sin_family = AF_INET;
    socketAddr.sin_port = htons(portNr); //7

    int i;

    for (i = 0; i < nClients - 1; ++i) {
        int p = fork();
        if (p == 0) {
            //p is child, dus break uit for
            break;
        }
        if (p < 0) {
            perror("Fork ");
            exit(EXIT_FAILURE);
        }
    }

    int sockfd;

    if (strcmp(argv[3], "TCP") == 0) {
        if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
            perror("fout bij socket TCP");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(argv[3], "UDP") == 0) {
        if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
            perror("fout bij socket UDP");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Protocol niet correct ingevoerd: kies TCP of UDP\n");
        exit(EXIT_FAILURE);
    }

    if ((conrtn = connect(sockfd, (struct sockaddr*) &socketAddr, sizeof (socketAddr)) < 0)) {
        perror("Fout bij connect");
        exit(EXIT_FAILURE);
    }

    time_t timeStart;
    
    time(&timeStart);

    //printf("Time start %i\n",(int)timeStart);

    int j;
    for (j = 0; j < nRequests; j++) {

        char sendBuffer[nBytes]; //= "Hallo";

        bzero(&sendBuffer,sizeof(sendBuffer));
        int herp;
        if ((herp = send(sockfd, sendBuffer, sizeof (sendBuffer), 0)) == -1) {
            perror("Send ");
            exit(EXIT_FAILURE);
        }

        //sleep(1);

        char recvBuffer[nBytes];
        int derp;
        if ( (derp = recv(sockfd, recvBuffer, sizeof (sendBuffer), MSG_WAITALL)) == -1) {
            perror("Recieve ");
            exit(EXIT_FAILURE);
        }

        //printf("%s\n", recvBuffer);
    }

    close(sockfd);
    time_t timeEnd;
    time(&timeEnd);

    //printf("Time end %i\n",(int)timeEnd);

    double diff_t = difftime(timeEnd, timeStart);

    printf("Einde client process\nVerstreken tijd %f\n",diff_t);

    return (EXIT_SUCCESS);
}



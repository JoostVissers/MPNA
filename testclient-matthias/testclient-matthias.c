/*
 * File:   testclient.c
 * Author: Matthias Meerhof
 *
 * Created on March 31, 2014, 4:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <linux/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

/*
 *
 */

int main(int argc, char **argv) {

    if (argc != 7) {
        printf("Aantal meegegeven argumenten: %d", argc);
        fprintf(stderr, "Onvoldoende of ongeldige argumenten meegegeven - testclient <ip-adres> <port#> <protocol> <#_clients> <#_requests> <#_bytes>\n");
        exit(EXIT_FAILURE);
    }



    int sock;
    int n;
    struct sockaddr_in addr;

    int i;
    int iPid;
    for (i = 0; i < atoi(argv[4]) - 1; i++) {
        iPid = fork();
        if (iPid == 0) {
            break;
        } else if (iPid == -1) {
            perror("Error bij fork()");
            exit(0);
        }
    }


    if (strcmp(argv[3], "TCP") == 0) {
        if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
            perror("Error bij het maken van socket");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(argv[3], "UDP") == 0) {
        if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
            perror("Error bij het maken van socket");
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Ongeldig of onbruikbaar protocol meegegeven");
        exit(EXIT_FAILURE);
    }

    bzero(&addr, sizeof (addr));
    inet_aton(argv[1], &addr.sin_addr);
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_family = AF_INET;



    if ((connect(sock, (struct sockaddr *) &addr, sizeof (addr))) == -1) {
        perror("Error bij connect");
        exit(0);
    }

    time_t start = time(NULL);

    int requests = atoi(argv[5]);
    char input[atoi(argv[6])];
    bzero(&input, sizeof (input));
    do {
        int m;
        if ((m = write(sock, input, sizeof (input))) > 0) {
            if (m < 0) {
                perror("Error bij write");
                exit(0);
            }
        }
        char output[atoi(argv[6])];
        if ((n = read(sock, output, sizeof (input))) > 0) {

        } else {
            perror("read error");
        }
        requests--;
    } while (requests > 0);

    double einde = difftime(time(NULL), start);

    printf("Tijdsduur: %f\n", einde);

    if (close(sock) == -1) {
        perror("Error bij close(sock)");
    }
    return (EXIT_SUCCESS);
}

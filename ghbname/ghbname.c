/* 
 * File:   ghbname.c
 * Author: Joost Vissers
 * v: 1
 *
 * Created on March 6, 2014, 9:56 AM
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
    
    char hostname[] = {"www.nu.nl"};

    struct hostent *host;
    struct in_addr adress;
    
    if((host = gethostbyname(hostname)) == 0){
        herror("fout: ");
        exit(EXIT_FAILURE);
    }
    else{
        adress.s_addr = (host->h_addr_list[0]);
        printf("Real hostname: %s\nIp adress: %s\n",(host->h_name),(inet_ntoa(adress)));
    }

    

    

    return (EXIT_SUCCESS);
}


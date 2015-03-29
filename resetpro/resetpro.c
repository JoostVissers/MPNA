/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 26, 2014, 1:42 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <time.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <string.h>
#include <netinet/in.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int fd;
    struct ifreq interface;
    char ifName[20] = {};

    fd = socket(AF_INET,SOCK_PACKET,IPPROTO_TCP);

    if(fd != -1){
        if(argc < 2){
            strcpy(ifName,"eth2");
            strcpy(interface.ifr_ifrn.ifrn_name,ifName);
        }
        else{
            strcpy(ifName,argv[1]);
            strcpy(interface.ifr_ifrn.ifrn_name,ifName);
        }

        if(ioctl(fd,SIOCGIFFLAGS,&interface) != -1){

            interface.ifr_ifru.ifru_flags = interface.ifr_ifru.ifru_flags & ~IFF_PROMISC;

            if(ioctl(fd,SIOCSIFFLAGS,&interface) != -1){
                printf("Promisc mode for %s is OFF.\n",ifName);
            }
            else{
                perror("fout: ");
                exit(EXIT_FAILURE);
            }
        }
        else{
            perror("fout: ");
            exit(EXIT_FAILURE);
        }
    }
    else{
        perror("fout: ");
        exit(EXIT_FAILURE);
    }
    close(fd);
    
    return(EXIT_SUCCESS);
}
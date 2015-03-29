#include "setpromisc.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <string.h>
#include <netinet/in.h>
//#include <fcntl.h>
//#include <time.h>

void setpromisc(char intefaceName[]){
    int fd;
    struct ifreq interface;
    char ifName[20] = {};

    fd = socket(AF_INET,SOCK_PACKET,IPPROTO_TCP);

    if(fd != -1){
        
        strcpy(ifName,intefaceName);
        strcpy(interface.ifr_ifrn.ifrn_name,ifName);

        if(ioctl(fd,SIOCGIFFLAGS,&interface) != -1){

            interface.ifr_ifru.ifru_flags = interface.ifr_ifru.ifru_flags | IFF_PROMISC;

            if(ioctl(fd,SIOCSIFFLAGS,&interface) != -1){
                printf("Promisc mode for %s is ON.\n",ifName);
            }
            else{
                perror("ioctl-set: ");
                exit(EXIT_FAILURE);
            }
        }
        else{
            perror("ioctl-get: ");
            exit(EXIT_FAILURE);
        }
    }
    else{
        perror("socket: ");
        exit(EXIT_FAILURE);
    }
    close(fd);
}

/* 
 * File:   ipadrr.c
 * Author: Joost
 *
 * Created on March 6, 2014, 10:57 AM
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

 */
int main(int argc, char** argv) {

    int socketfd;
    struct ifreq interface;
    char ifName[20] = {};
    struct sockaddr_in *ipaddr;
    struct sockaddr_in *macaddr;
    
    socketfd = socket(AF_INET,SOCK_PACKET,IPPROTO_TCP);

    if(socketfd != -1){
        if(argc < 2){
            strcpy(ifName,"eth2");
            strcpy(interface.ifr_ifrn.ifrn_name,ifName);
        }
        else{
            strcpy(ifName,argv[1]);
            strcpy(interface.ifr_ifrn.ifrn_name,ifName);
        }

        if(ioctl(socketfd,SIOCGIFADDR,&interface) != -1){

            ipaddr = (struct sockaddr_in*)&interface.ifr_addr;
            printf("ip adress: %s\n",inet_ntoa(ipaddr->sin_addr));

            if(ioctl(socketfd,SIOCGIFHWADDR,&interface) != -1){
                printf("Mac adress: %02X:%02X:%02X:%02X:%02X:%02X:\n",
                interface.ifr_hwaddr.sa_data[0],
                interface.ifr_hwaddr.sa_data[1],
                interface.ifr_hwaddr.sa_data[2],
                interface.ifr_hwaddr.sa_data[3],
                interface.ifr_hwaddr.sa_data[4],
                interface.ifr_hwaddr.sa_data[5]);
            }
            else{
                perror("ioctl-GIFHWADDR: ");
                exit(EXIT_FAILURE);
            }

        }
        else{
            perror("ioctl-GIFADDR: ");
            exit(EXIT_FAILURE);
        }
    }
    else{
        perror("socket: ");
        exit(EXIT_FAILURE);
    }

    close(socketfd);
    
    
    
    return (EXIT_SUCCESS);
}


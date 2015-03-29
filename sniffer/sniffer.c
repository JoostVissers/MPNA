/* 
 * File:   sniffer.c
 * Author: Joost
 *
 * Created on February 26, 2014, 10:28 AM
 */
#include <netinet/ip.h>

#include <netinet/udp.h>
#include <netinet/tcp.h>

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_packet.h>
// #include <linux/in.h>
#include <linux/if_ether.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#include "resetpromisc.h"
#include "setpromisc.h"

int main(int argc, char **argv){
    
 int sock, n, i;
 unsigned char buffer[2048];
 //unsigned char *iphead;
 
 unsigned char *ethhead;
 struct ifreq ifreq;
 struct sockaddr_ll addr;

 if ((sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0){
    perror("socket");
    exit(EXIT_FAILURE);
 }

 if (argc == 2){ 
    strcpy (ifreq.ifr_name, argv[1]);
    setpromisc(ifreq.ifr_ifrn.ifrn_name);
 }
 else{ 
    strcpy (ifreq.ifr_name, "eth2");
    setpromisc(ifreq.ifr_ifrn.ifrn_name);
 }

 if (ioctl (sock, SIOCGIFINDEX, &ifreq) != 0){
    perror ("ioctl sock");
    exit (EXIT_FAILURE);
 }

 printf ("Interface index: %d\n", ifreq.ifr_ifindex);

 memset (&addr, 0, sizeof (struct sockaddr_ll));
 addr.sll_family = PF_PACKET;
 addr.sll_protocol = htons(ETH_P_ALL);
 addr.sll_ifindex = ifreq.ifr_ifindex;

 if (bind (sock, (struct sockaddr *)&addr, sizeof (struct sockaddr_ll)) != 0){
    perror ("bind addr");
    exit (EXIT_FAILURE);
 }

 i = 0;
 while (i < 1000){
    printf("----------\n");
    n = read (sock, buffer, 2048);
    printf("%d bytes read\n", n);

    if (n < 42){
        perror("recvfrom(): ");
        printf("Incomplete packet (errno is %d)\n", errno);
        close(sock);
        exit(EXIT_FAILURE);
    }

    ethhead = buffer;

    printf("Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
		  ethhead[0], ethhead[1], ethhead[2],
		  ethhead[3], ethhead[4], ethhead[5]);
    printf("Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
		  ethhead[6], ethhead[7], ethhead[8],
		  ethhead[9], ethhead[10], ethhead[11]);
    printf("Type: %02x:%02x\n", ethhead[12], ethhead[13]);

    if(ethhead[12] == 0x08 && ethhead[13] == 0x00){
        printf("----IP----\n");

        struct iphdr *ip = (struct iphdr*)(buffer + sizeof(struct ethhdr));

        struct sockaddr_in sourceip;
        struct sockaddr_in destip;

        sourceip.sin_addr.s_addr = ip->saddr;
        destip.sin_addr.s_addr =  ip->daddr;
        
        printf("Source Ip: %s\n",inet_ntoa(sourceip.sin_addr));
        
        printf("Dest Ip: %s\n",inet_ntoa(destip.sin_addr));

        
        if(ip->protocol == IPPROTO_TCP){
           printf("Protocol: TCP - %i\n",ip->protocol);
           printf("----TCP----\n");

           struct tcphdr *tcp = (struct tcphdr*)(buffer + sizeof(struct tcphdr));

           printf("Source port: %i\n",ntohs(tcp->source));
           printf("Dest port: %i\n",ntohs(tcp->dest));
           
        }
        else if(ip->protocol == IPPROTO_UDP){
           printf("Protocol: UDP - %i\n",ip->protocol);
           printf("----UDP----\n");
           
           struct udphdr *udp = (struct udphdr*)(buffer + sizeof(struct udphdr));
           printf("Source port: %i\n",ntohs(udp->source));
           printf("Dest port: %i\n",ntohs(udp->dest));
        }
        
    }
 }
 resetpromisc(ifreq.ifr_ifrn.ifrn_name);

 exit(EXIT_SUCCESS);
}


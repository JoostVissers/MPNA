#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <asm/types.h>
#include <linux/if.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
// #include <linux/if_arp.h>
// #include "if_arp.h"
#include <string.h>
#include <unistd.h>
#include <netinet/ether.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {

 int sock, n;

 struct sockaddr_ll addr;
 unsigned int packetsize =  (sizeof (struct ether_arp) + sizeof (struct ether_header));
 unsigned char packet[packetsize];
 struct ether_header *eth = (struct ether_header *)(packet);
 struct ether_arp *arp = (struct ether_arp *)(packet + sizeof (struct ether_header));
 struct ifreq ifreq;
 struct ether_addr *ether_addr_n;

 if ((sock = socket (PF_PACKET, SOCK_RAW, htons(ETH_P_ARP))) == -1)
 {
  perror ("creating socket");
  exit (0);
 }

 memset (packet, 0, packetsize);

/* zelf nu de arp header afmaken */
 arp->arp_hrd = htons(0x0001); //
 arp->arp_pro = htons(0x0800); //arp
 arp->arp_hln = 6;
 arp->arp_pln = 4;
 arp->arp_op = htons (1);
 ether_addr_n = ether_aton("00:0C:29:27:C4:56");
 memcpy (arp->arp_sha, ether_addr_n, ETH_ALEN);
 inet_aton ("192.168.1.143", (struct in_addr *)arp->arp_spa);
 ether_addr_n = ether_aton("00:00:00:00:00:00");
 memcpy (arp->arp_tha, ether_addr_n, ETH_ALEN);
 inet_aton ("192.168.1.2", (struct in_addr *)arp->arp_tpa);

/* zelf nu de eth header afmaken */
 ether_addr_n = ether_aton("FF:FF:FF:FF:FF:FF");
 memcpy (eth->ether_dhost, ether_addr_n, ETH_ALEN);
 ether_addr_n = ether_aton ("00:0C:29:27:C4:56");
 memcpy (eth->ether_shost, ether_addr_n, ETH_ALEN);
 eth->ether_type = htons (ETH_P_ARP);

 memset (&addr, 0, sizeof (struct sockaddr_ll));
 addr.sll_family = PF_PACKET;
 addr.sll_protocol = htons(ETH_P_ARP);

 strcpy (ifreq.ifr_name, "eth2");
 if (ioctl (sock, SIOCGIFINDEX, &ifreq) != 0)
 {
  perror ("ioctl get index");
  exit (0);
 }
 addr.sll_ifindex = ifreq.ifr_ifindex;
 printf ("Interface index: %d\n", ifreq.ifr_ifindex);

 if (bind (sock, (struct sockaddr *)&addr,
	sizeof (struct sockaddr_ll)) != 0)
 {
  perror ("bind addr");
  exit (0);
 }

 if ((n = write (sock, packet, packetsize)) <= 0)
 {
  perror ("ARP send");
  exit (0);
 }
 printf ("%d bytes sent\n", n);

 close (sock);
 exit(1);
}

/* 
 * File:   ipnetno.c
 * Author: Joost vissers
 *
 * Created on February 22, 2014, 8:03 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include <arpa/inet.h>

/*
 *
 */
int main(int argc, char** argv) {

    struct in_addr addr;
    struct in_addr mask;
    struct in_addr nNo;
    char address[20] = {"192.168.1.6"};
    char sMask[20] = {"255.255.255.0"};


    //printf("%s\n",address);
    int rValue;
    if((rValue = inet_aton(address,&addr)) == 0){
        printf("ongeldig invoer ");
        exit(EXIT_FAILURE);
    }
    else if(rValue == -1){
        perror("Fout opgetreden ");
        exit(EXIT_FAILURE);
    }
    else{
        if((rValue = inet_aton(sMask,&mask)) == 0){
            printf("ongeldig invoer ");
            exit(EXIT_FAILURE);
        }
        else if(rValue == -1){
            perror("Fout opgetreden ");
            exit(EXIT_FAILURE);
        }
        else{
            nNo.s_addr = addr.s_addr & mask.s_addr;
            printf("Ip adress: %s\nSubnetmask: %s\nNetwork adress: %s\n",address,sMask,inet_ntoa(nNo));
        }

    }

    

    return (EXIT_SUCCESS);
}


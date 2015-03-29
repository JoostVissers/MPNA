/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 20, 2014, 3:24 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include <arpa/inet.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    struct in_addr addr;
    char address[20] = {"192.168.1.1"};


    printf("%s\n",address);
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
       printf("%x\n",addr.s_addr);
    }  
    
    printf("%s\n",inet_ntoa(addr));

   // free(addr);

    return (EXIT_SUCCESS);
}


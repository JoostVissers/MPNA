/* 
 * File:   ipclass.c
 * Author: Joost Vissers
 *
 * Created on February 22, 2014, 4:13 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include <arpa/inet.h>

/*
 * 
 */
int main(int argc, char** argv) {

    struct in_addr addr;
    char address[] = {"126.0.0.1"};


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
        if((addr.s_addr & 0x80) != 0x80){
            printf("Adress: %s\nIs van klasse A.\n",address);
        }
        else{
           if((addr.s_addr & 0x40) != 0x40){
               printf("Adress: %s\nIs van klasse B.\n",address);
           }
           else{
               if((addr.s_addr & 0x20) != 0x20){
                    printf("Adress: %s\nIs van klasse C.\n",address);
               }
               else{
                   printf("Adress: %s\nValt niet onder klasse A,B of C.\n",address);
               }
           }
        }
    }



    return (EXIT_SUCCESS);
}


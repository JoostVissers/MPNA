/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 11, 2014, 9:04 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Sortlist.h"
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {

    char *apcWordList[10] = {};

    int i;
    int j;

    FILE *fp;
    fp=fopen("//home/Carel/woorden.txt", "r");
    if(fp == NULL){
        printf("file is niet geopend");
    }
    
    char buffer[20];
    
    for(i = 0; i < 10 ; i++){
       fgets(buffer, 20, fp);
       apcWordList[i] = strdup(buffer);
       printf("%s",buffer);
    }

    fclose(fp);

    sortlist(10, apcWordList);
    
    printf("\nList sorted\n\n");
    for(j = 0; j < 10 ; j++){
       printf("%s",apcWordList[j]);
    }

    fp=fopen("//home/Carel/sorted.txt", "w+");
    if(fp == NULL){
        printf("file is niet geopend");
    }

    for(i = 0; i < 10 ; i++){
       fputs(apcWordList[i], fp);
    }
    fclose(fp);

    
    
    return (EXIT_SUCCESS);
}

/*
fiets
auto
bananen
ijshoorntje
aap
koningkrijk
muismat
beeldscherm
toetsenbord
tentoonstelling
 */
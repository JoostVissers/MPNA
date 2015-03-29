/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 12, 2014, 9:06 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "MoveRandom.h"
#include <string.h>
#include <time.h>

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));

    char *apcWordList[10] = {};

    int i;
    int j;

    FILE *fp;
    fp=fopen("//home/Carel/sorted.txt", "r");
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

    moverandom(10, apcWordList);

    printf("\nList husseld\n\n");
    for(j = 0; j < 10 ; j++){
       printf("%s",apcWordList[j]);
    }

    fp=fopen("//home/Carel/random.txt", "w+");
    if(fp == NULL){
        printf("file is niet geopend");
    }

    for(i = 0; i < 10 ; i++){
       fputs(apcWordList[i], fp);
    }
    fclose(fp);

    return (EXIT_SUCCESS);
}


/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 10, 2014, 11:25 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CompareWords.h"

void speldoorgaan(char *doorgaan);

/*
 * 
 */
int main(int argc, char** argv) {

    char sSecretWord[50]= {};
    char sGuessedWord[50] = {};
    char sResult[50] = {};
    char doorgaan = 'y';
    char dummy;

    do{
        if(strlen(sSecretWord) == 0){
            printf("Voer secretword in:\n");
            scanf("%s",sSecretWord);
            scanf("%c",&dummy);
        }

        printf("Lengte woord:%d\n",strlen(sSecretWord));

        printf("Voer guessedword in:\n");
        scanf("%s",sGuessedWord);
        scanf("%c",&dummy);

        if(strlen(sSecretWord) == strlen(sGuessedWord)){
           comparewords (sSecretWord,sGuessedWord,sResult);

        }
        printf("%s",sResult);
        printf("\n");


        if( strcmp(sResult,sSecretWord) == 0){
            sSecretWord[0] = NULL;
            
            speldoorgaan(&doorgaan);
        }
    }
    while(doorgaan != 'n');


    return (EXIT_SUCCESS);
}

void speldoorgaan(char *doorgaan){
    char userinput;
    char dummy;

    printf("Nog een spel?: y/n\n");

    userinput = getchar();
    dummy = getchar();
    if(userinput == 'y' || userinput == 'n'){
        if(userinput == 'y'){
            *doorgaan = 'y';
        }
        else {
            *doorgaan = 'n';
        }
    }
    else{
        speldoorgaan(doorgaan);
    }
}


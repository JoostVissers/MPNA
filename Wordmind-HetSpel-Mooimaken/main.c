/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 12, 2014, 10:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "CompareWords.h"
#include "Sortlist.h"
#include "MoveRandom.h"


/*
 * 
 */
void speelwordmind(char *wordList[]);
void speldoorgaan(char *doorgaan);


int main(int argc, char** argv) {
    srand(time(NULL));
    
    char *apcWordList[MAX_WORDS] = {};

    int i;
    int j;

    sortlist(MAX_WORDS, &apcWordList);


    /*
    ////////////////////////////////////////////////////////open sorted.txt verwissel 10 willekeurige woorden en sla op onder random.txt
    FILE *fp;
    fp=fopen("//home/Carel/sorted.txt", "r");
    
    char buffer[20];

    for(i = 0; i < MAX_WORDS ; i++){
       fgets(buffer, 20, fp);
       apcWordList[i] = strdup(buffer);
       printf("%s",buffer);
    }

    fclose(fp);

    moverandom(MAX_WORDS, apcWordList);

    fp=fopen("//home/Carel/random.txt", "w+");

    for(i = 0; i < MAX_WORDS ; i++){
       fputs(apcWordList[i], fp);
    }
    fclose(fp);*/

 ///////////////////////////////////////////////////////////////////////open random.txt en speel spel
    
    FILE *fp;
    fp=fopen("//home/Carel/random.txt", "r");

    char buffer[20] ={};

    for(i = 0; i < MAX_WORDS ; i++){
       fgets(buffer, 20, fp);
       if(buffer[strlen(buffer) - 1] == '\n'){
            buffer[strlen(buffer) - 1] = '\0';
       }
       apcWordList[i] = strdup(buffer);
    }

    fclose(fp);

    speelwordmind(apcWordList);
    
    return (EXIT_SUCCESS);
}

void speelwordmind(char *wordList[]){
    char sSecretWord[50]= {};
    char sGuessedWord[50] = {};
    char sResult[50] = {};
    char doorgaan = 'y';
    char dummy;
    int random;
    int i;

    do{
        if(strlen(sSecretWord) == 0){
            random = rand() % MAX_WORDS;
            strcpy(sSecretWord,wordList[random]);
            //printf("%s\n",sSecretWord);
        }

        printf("Lengte van het te raden woord:%d\n",strlen(sSecretWord));

        printf("Voer guessedword in:\n");
        scanf("%s",sGuessedWord);
        scanf("%c",&dummy);

        if(strlen(sSecretWord) == strlen(sGuessedWord)){
           comparewords(sSecretWord,sGuessedWord,sResult);
        }
        
        printf("%s",sResult);
        printf("\n");


        if( strcmp(sResult,sSecretWord) == 0){
            sSecretWord[0] = NULL;
            
            for(i = 0; i < 50; i ++){
             sResult[i] = '\0';
            }
            speldoorgaan(&doorgaan);
        }
    }
    while(doorgaan != 'n');
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
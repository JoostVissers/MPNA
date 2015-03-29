#include <stdio.h>
#include <stdlib.h>
#include "CompareWords.h"
#include <string.h>

void comparewords (char *sSecretWord,char *sGuessedWord,char *sResult){
    int i;
    int j;

    printf("Resultaat:\n");
    char rest[strlen(sSecretWord)];

    strcpy(rest , sSecretWord);

    for( i = 0; sSecretWord[i] != '\0';i++){
        if(sSecretWord[i] == sGuessedWord[i]){
            sResult[i] = sGuessedWord[i];
            rest[i] = '.';
        }
        else{
            for(j = 0; sSecretWord[j] != '\0'; j++){
                if( rest[j] == sGuessedWord[i]){
                    sResult[i] = '*';
                    break;
                }
                else{
                    sResult[i] = '-';
                }

            }
        }
    }
} 

/*
                 if(rest[j] == sGuessedWord[i] ){
                    sResult[i] = '*';
                    break;
                }
                else{
                    sResult[i] = '-';
                }*/
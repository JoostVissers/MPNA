#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "CompareWords.h"
#include "playWordMind.h"
#include "structNode.h"

void playWordMind(int nWords,Node *wordList[]){
    char sSecretWord[50]= {};
    char sGuessedWord[50] = {};
    char sResult[50] = {};
    char continueGame = 'y';
    char dummy;
    int random;
    int i;
    int nPoints;

    do{
        if(strlen(sSecretWord) == 0){
            random = rand() % nWords;
            strcpy(sSecretWord,wordList[random]->pcWord);
            //printf("%s\n",sSecretWord);
            nPoints = 10;
        }

        printf("Lengte van het te raden woord:%d\n",strlen(sSecretWord));

        printf("Voer het woord in:\n");
        scanf("%s",sGuessedWord);
        scanf("%c",&dummy);

        if(sGuessedWord[0] == '!' && sGuessedWord[1] == '!'){
            printf("Het antwoord was: %s\n",sSecretWord);
            break;
        }

        if(strlen(sSecretWord) == strlen(sGuessedWord)){
           comparewords(sSecretWord,sGuessedWord,sResult);
        }

        printf("%s",sResult);
        printf("\n");


        if( strcmp(sResult,sSecretWord) == 0 && nPoints > 0){
            //sSecretWord[0] = NULL;

            for(i = 0; i < 50; i ++){
             sResult[i] = '\0';
            }
            printf("Goed Geraden! u heeft %d punten behaald.",nPoints);
                        
            if(nPoints >= wordList[random]->cMaxScore){
                printf("\nNieuwe Highscore!");
            }

            wordList[random]->cMaxScore = nPoints;
            wordList[random]->tTime = time(NULL);
            
            continueWordMind(&continueGame);
            
        }
        else if(nPoints == 0){
            printf("Helaas u heeft het woord niet kunnen raden.\nHet antwoord was: %s.",sSecretWord);
            continueWordMind(&continueGame);
        }
        else{
            nPoints--;
        }
    }
    while(continueGame != 'n');
}

void continueWordMind(char *continueGame){
    char userinput;
    char dummy;

    printf("\nNog een spel?: y/n\n");

    userinput = getchar();
    dummy = getchar();
    if(userinput == 'y' || userinput == 'n'){
        if(userinput == 'y'){
            *continueGame = 'y';
        }
        else {
            *continueGame = 'n';
        }
    }
    else{
        continueWordMind(continueGame);
    }
}

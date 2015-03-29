#include "loadWordsFromFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structNode.h"

void loadWordsFromFile(int nWords, char *path, Node *outputList[]){

    FILE *fp;
    fp=fopen(path, "r"); // "//home/Carel/woorden.txt" , "r" ,

    char bufferWord[20];
    int bufferMaxScore;
    int bufferTijd;
    //char bufferTijdDatum[20];
    int i;
    
    for(i = 0; i < nWords ; i++){

        //fgets(buffer, 20, fp);
        //fgets(buffer, 20, fp);
        
        fscanf(fp,"%s\t%d\t%d",bufferWord,&bufferMaxScore,&bufferTijd);

        if(bufferWord[strlen(bufferWord) - 1] == '\n'){
            bufferWord[strlen(bufferWord) - 1] = '\0';
        }
        
        outputList[i] = malloc(sizeof(struct Node));

        outputList[i]->pcWord = strdup(bufferWord);

        if( bufferMaxScore > 0 && bufferMaxScore <= 10){
            outputList[i]->cMaxScore = bufferMaxScore;
        }
        else{
            outputList[i]->cMaxScore = 0;
        }

        outputList[i]->tTime = bufferTijd;
        //printf("\n%i\n",outputList[i]->cMaxScore);
        //printf("%s",buffer);
    }
    fclose(fp);
}


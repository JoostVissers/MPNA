#include "loadWordsFromFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadWordsFromFile(int nWords,char *path,char *outputList[]){

    FILE *fp;
    fp=fopen(path, "r"); // "//home/Carel/woorden.txt" , "r" ,

    char buffer[20];
    int i;
    for(i = 0; i < nWords ; i++){
       fgets(buffer, 20, fp);
       outputList[i] = strdup(buffer);
       //printf("%s",buffer);
    }
    if(buffer[strlen(buffer) - 1] == '\n'){
        buffer[strlen(buffer) - 1] = '\0';
    }

    fclose(fp);
}


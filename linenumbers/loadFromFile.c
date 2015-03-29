#include "loadFromFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadFromFile(char *path, char *outputRowList[]){

    FILE *fp;
    fp=fopen(path, "r"); // "//home/Carel/woorden.txt" , "r" ,

    char bufferRow[2048];

    int i = 0;

    while(fscanf(fp,"%s",bufferRow) != EOF){
        //outputList[i] = malloc(sizeof(struct Node));

        outputRowList[i] = strdup(bufferRow);
        i++;
    }
    fclose(fp);
}

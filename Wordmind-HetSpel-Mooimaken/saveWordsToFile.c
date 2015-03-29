#include "saveWordsToFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saveWordsToFile(int nWords,char path[],char mode,char *inputList[]){

    FILE *fp;
    fp=fopen("//home/Carel/sorted.txt", "w+"); // "//home/Carel/sorted.txt", "w+"
    int i;
    for(i = 0; i < nWords ; i++){
       fputs(inputList[i], fp);
    }

    fclose(fp);
}

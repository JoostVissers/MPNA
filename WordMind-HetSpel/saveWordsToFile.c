#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saveWordsToFile.h"
#include "structNode.h"


void saveWordsToFile(int nWords,char path[],Node *inputList[]){

    FILE *fp;
    fp=fopen(path, "w"); // "//home/Carel/sorted.txt", "w+"
    int i;
    for(i = 0; i < nWords ; i++){
       fprintf(fp,"%s\t%d\t%d\n",inputList[i]->pcWord,inputList[i]->cMaxScore,inputList[i]->tTime);
    }

    fclose(fp);
}

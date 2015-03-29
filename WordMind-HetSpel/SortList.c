#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Sortlist.h"
#include "structNode.h"

void sortlist (int iListSize,Node *apcList[]){

    int i;
    int j;
    char *temp;

    for(i = 0; i < iListSize; i++){
        for(j = 0; j < iListSize; j++){
            if(strlen(apcList[i]->pcWord) < strlen(apcList[j]->pcWord)){
                temp = apcList[j]->pcWord;
                apcList[j]->pcWord = apcList[i]->pcWord;
                apcList[i]->pcWord = temp;
            }
        }
    }
}

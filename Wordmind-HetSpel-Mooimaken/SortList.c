#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Sortlist.h"

void sortlist (int iListSize, char *apcList[]){

    int i;
    int j;
    char *temp;

    for(i = 0; i < iListSize; i++){
        for(j = 0; j < iListSize; j++){
            if(strlen(apcList[i]) < strlen(apcList[j])){
                temp = apcList[j];
                apcList[j] = apcList[i];
                apcList[i] = temp;
            }
        }
    }
}

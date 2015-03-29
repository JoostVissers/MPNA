#include <stdio.h>
#include <stdlib.h>
#include "MoveRandom.h"
#include <time.h>

void moverandom(int iListSize, char *apcList[]){

    int i;
    int j;
    int random1;
    int random2;
    char *temp;

    for(i = 0; i < iListSize; i++){
        random1 = rand() % 10;
        random2 = rand() % 10;

        if(apcList[random1] != apcList[random2]){
            temp = apcList[random1];
            apcList[random1] = apcList[random2];
            apcList[random2] = temp;
        }
        else{
            j--;
        }
    }
}

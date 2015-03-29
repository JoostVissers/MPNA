#include <stdio.h>
#include <stdlib.h>
#include "MoveRandom.h"
#include <time.h>

void moverandom(int iListSize,Node *apcList[]){

    int i;
    int j;
    int random1;
    int random2;
    char *temp;

    for(i = 0; i < iListSize; i++){
        random1 = rand() % iListSize;
        random2 = rand() % iListSize;

        if(apcList[random1]->pcWord != apcList[random2]->pcWord ){
            temp = apcList[random1]->pcWord ;
            apcList[random1]->pcWord  = apcList[random2]->pcWord ;
            apcList[random2]->pcWord  = temp;
        }
        else{
            j--;
        }
    }
}

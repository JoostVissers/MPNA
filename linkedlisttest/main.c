/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 12, 2014, 6:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*
 * 
 */
int main(int argc, char** argv) {

    typedef struct st{
        int id;
        char *naam;
        char *adres;
        struct st *Next;
    }leraar;

    leraar *startptr;
    leraar *stptr;
    leraar *stptr1;
    leraar *stptr2;
    leraar *stptr3;

    stptr1 = malloc(sizeof(leraar));
    stptr2 = malloc(sizeof(leraar));
    stptr3 = malloc(sizeof(leraar));

    startptr = stptr1;
    stptr1->Next = stptr2;
    stptr2->Next = stptr3;
    stptr3->Next = NULL;

    stptr1->id = 1;
    stptr1->naam = "Carel";
    stptr1->adres = "6866AH15";

    stptr2->id = 2;
    stptr2->naam = "Karel";
    stptr2->adres = "7151AE71";

    stptr3->id = 2;
    stptr3->naam = "Leon";
    stptr3->adres = "5481RS33";

    for(stptr=startptr; stptr!= NULL; stptr = stptr->Next){
        printf("\nDocent informatie: \nid = %d \n%s \n%s\n",stptr->id,stptr->naam,stptr->adres);

        printf("adres in startptr:%p, adres in stptr:%p stptr->Next:%p\n",startptr,stptr,stptr->Next);
    }
    getchar();

    return (EXIT_SUCCESS);
}


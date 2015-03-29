/* 
 * File:   main.c
 * Author:  Joost Vissers
 *
 * Created on February 12, 2014, 10:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Sortlist.h"
#include "MoveRandom.h"
#include "playWordMind.h"
#include "loadWordsFromFile.h"
#include "saveWordsToFile.h"
#include "structNode.h"

#define MAX_WORDS 10
/*
 * 
 */

int main(/*int argc, char** argv*/) {
    srand(time(NULL));
    
    typedef Node *NodePtr;
    
    NodePtr apcWordList[MAX_WORDS];

    //"//home/Carel/woorden.txt" 

    char path[] = "//home/Carel/woorden.txt";
    //scanf("%s",path);

    loadWordsFromFile(MAX_WORDS,path,apcWordList);

    sortlist(MAX_WORDS, apcWordList);
    moverandom(MAX_WORDS, apcWordList);

    playWordMind(MAX_WORDS,apcWordList);

    //saveWordsToFile(MAX_WORDS,path,apcWordList);

    int i;
    for(i = 0; i < MAX_WORDS;i++){
        free(apcWordList[i]);
    }
    
    return (EXIT_SUCCESS);
}
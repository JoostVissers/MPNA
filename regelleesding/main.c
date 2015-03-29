/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 5, 2014, 7:47 PM
 */

#include <stdio.h>
#include <stdlib.h>

void lowerToUpper(int regel[],int t);
/*
 * 
 */
int main(int argc, char** argv) {
    int i = 0;
    int tCharacters = 0;
    int regel[100];
    while(i < 100){
        int invoer = getchar();
        if(invoer >= 'a' && invoer <= 'z'){
            regel[i] = invoer;
            i++;
            tCharacters++;
        }
        else if(invoer == '\n'){
          lowerToUpper(regel,tCharacters);
        }
    }
    //lowerToUpper(regel);
    return (EXIT_SUCCESS);
}

void lowerToUpper(int regel[],int tCharacters){
    int i;
    for(i=0;i<tCharacters;i++){
        printf("%c",regel[i]-32);
    }
}


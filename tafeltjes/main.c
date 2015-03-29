/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 4, 2014, 12:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int i = 1;


    while(i <= 10){
        tafelvan(i);
        printf("\n(Press enter to continue)\n");
        if(getchar() == '\n'){
            i++;
        }
    }
    
    return (EXIT_SUCCESS);
}

void tafelvan(int tafelvan);

void tafelvan(int tafelvan){
    int i;
    printf("Tafel van: %d\n=====================\n",tafelvan);
    for(i = 1; i<=10; i++){
    printf("%d X %d = %d\n",tafelvan,i,tafelvan*i);
    }
}


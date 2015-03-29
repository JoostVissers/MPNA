/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 3, 2014, 3:26 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int getallen[] = { 100, 200 , 900 , 300 , 600 , 400 , 700 , 1000 , 500 , 800};

    int i;
    int aantalG = 10;
    
    do{
        for(i = 0; i < aantalG-1; i++){
            if(getallen[i] > getallen[i+1]){
                int temp = getallen[i] ;
                getallen[i] = getallen[i+1];
                getallen[i+1] = temp;
            }
        }
    aantalG--;
    } while(aantalG > 1);

    for(i = 0; i < 10; i ++){
         printf("%d\n", getallen[i]);
    }

    return (EXIT_SUCCESS);
}


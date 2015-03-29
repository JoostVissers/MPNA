/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 3, 2014, 2:03 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    signed char i = 147;

    if((i & 0x10) == 0x10){
        printf("5e bit: is gezet!\n");
    }
    else{
        printf("5e bit: is 0\n");
    }
    getchar();
    return (EXIT_SUCCESS);
}


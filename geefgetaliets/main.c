/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 5, 2014, 10:26 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "geefgetal.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    int getal = geefgetal();
    if(getchar()){
        printf("Dit is uw getal: ");
        putchar(getal);
    }

    return (EXIT_SUCCESS);
}


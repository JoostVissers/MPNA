/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 5, 2014, 11:26 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aantalzetels.h"

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    float randomperc = rand() % 100;
    printf("Aantalzetels: %d",aantalzetels(randomperc));

    return (EXIT_SUCCESS);
}


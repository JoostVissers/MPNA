/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 11, 2014, 7:47 PM
 */

#include <stdio.h>
#include <stdlib.h>


struct Artikel{
    char naam[30];
    int nummer;
    int barcode;
    int voorraad;
};
/*
 * 
 */
int main(int argc, char** argv) {
    struct Artikel artikelen;
    int i;
    strcpy(artikelen.naam,"Pizza");
    artikelen.nummer = 1;
    artikelen.barcode = 200;
    artikelen.voorraad = 1000;
    printf("Naam    nummer      barcode     voorraad\n%s %d %d %d\n",artikelen.naam,artikelen.nummer,artikelen.barcode,artikelen.voorraad);


    return (EXIT_SUCCESS);
}


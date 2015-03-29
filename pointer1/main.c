/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 6, 2014, 12:33 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int Getal = 1;
    int *piNum;

    printf("Getal heeft de waarde %d en staat op geheugenadres %p\n", Getal, &Getal);
    printf("ptr piNum heeft de waarde %p en staat op geheugenadres %p\n", piNum, &piNum);

    piNum = &Getal;
    printf("De inhoud van waar de pointer naar toewijst is %d\n", *piNum);

    char sWoord[10] = "Hallo";
    char *pWord = &sWoord[0];

    return 0;
}
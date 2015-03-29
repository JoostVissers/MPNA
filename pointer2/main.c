/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 6, 2014, 12:34 PM
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

    return 0;
}

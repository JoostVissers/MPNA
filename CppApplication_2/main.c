/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 3, 2014, 3:01 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int c;
    while ((c = getchar()) != '*'){
        if(c >= 'a' && c <= 'z'){
            c -=32;
            printf(c);
        }
    }
    return (EXIT_SUCCESS);
}


/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 6, 2014, 9:23 AM
 */

#include <stdio.h>
#include <stdlib.h>

char leeschar();
/*
 * 
 */
int main(int argc, char** argv) {

    char ch;
    //printf("Geef een karakter");
    do{
        ch = leeschar();
        printf("%d\n",ch);
    }
    while(ch != '!');

    return (EXIT_SUCCESS);
}

char leeschar(){
    char ch = getchar();
    char dummy = getchar();

    return ch;
}


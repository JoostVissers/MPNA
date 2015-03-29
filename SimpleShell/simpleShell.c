/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 20, 2014, 1:08 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <dirent.h>
#include "createProcess.h"
#include "killProcessById.h"
#include "split.h"

#define MAX 100

/*
 * 
 */
int main(int argc, char** argv) {

    char usrInput[MAX] = {};
    char *argumenten[MAX] = {};
    int i;
    int max = MAX;
    int nArgumenten;


    printf("$ ");
    
    while(fgets(usrInput, MAX, stdin) != NULL){
                
        printf("$ ");
        
        i = strlen(usrInput);

        usrInput[i-1] = '\0';

        nArgumenten = split(usrInput, argumenten, max, ' ');

        if(nArgumenten > 0){
            if(strcmp(argumenten[0],"exit") == 0 || strcmp(argumenten[0],"quit") == 0 ){
                exit(EXIT_SUCCESS);
            }
            else if(strcmp(argumenten[0],"cd") == 0){
                chdir(argumenten[1]);
            }
            else if(strcmp(argumenten[0],"kill") == 0){
                killProcessById(argumenten);
            }
            else{
                createProcess(argumenten[0],argumenten);
            }
        }
        for(i = 0; i < MAX; i++){
            argumenten[i] = NULL;
        }
    }
  return (EXIT_SUCCESS);
}
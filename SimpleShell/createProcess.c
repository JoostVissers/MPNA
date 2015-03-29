#include <stdio.h>
#include <stdlib.h>
#include "createProcess.h"
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <dirent.h>

void createProcess(char *argument,char *argumenten[]){

    int childExitStatus;
    int pid = fork();

    switch(pid){
        case 0:
            //child
            execvp(argument,argumenten);

            break;

        case -1:
            perror("Error");
            break;
        default:
            //parent
            wait(&childExitStatus);
            break;
    }
}
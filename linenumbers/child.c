#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "child.h"

void child(int *ipPX, int *ipPY,int check){
    close(ipPX[1]);
    close(ipPY[0]);

    close(0);
    dup(ipPX[0]);
    close(ipPY[0]);           /* redirect stdin        */

    close(1);
    dup(ipPY[1]);
    close(ipPY[1]);           /* redirect stdout       */

    if(check == 1){
        if(execlp("cat", "cat","-n",NULL) == -1){
            perror("fault by exec: ");
            exit(EXIT_FAILURE);
        }
    }
    else{
        if(execlp("sed", "sed","s/^.......//",NULL) == -1){
            perror("fault by exec: ");
            exit(EXIT_FAILURE);
        }
    }
}

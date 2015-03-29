/* 
 * File:   linenumbers.c
 * Author: J
 *
 * Created on March 6, 2014, 3:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "parent.h"
#include "child.h"

/*
 * 
 */
int main(int argc, char** argv) {

      int aiPX[2];
      int aiPY[2];
      int  check;
      char filename[20] = {};
      pipe(aiPX);
      pipe(aiPY);  /* Create Communication Channels */

      if(argc > 1){
          if(strcmp(argv[1],"-n") == 0 ){
              check = 0;
              //printf("check = %i\n",check);
          }
          else{
              check = 1;
              //printf("check = %i\n",check);
          }
          if(argc > 2){
              strcpy(filename,argv[2]);
          }
          else{
              strcpy(filename,argv[1]);
          }
      }
      else{
          printf("Opdracht mist paramaters.\n");
          exit(EXIT_FAILURE);
      }

    int pid;

    switch(pid = fork()){
        case 0:
            //child
            child(aiPX,aiPY,check);
            break;

        case -1:
            perror("Error creating child");
            exit(EXIT_FAILURE);

        default:
            //parent
            parent(aiPX, aiPY,filename);
    }
    return (EXIT_SUCCESS);
}
/*
    while((readC = read(ipPY[0],&plh,1)) > 0){

        //rFromChild++;

        if(readC == -1){
            printf("Error bij read from child (final check)\n");
            exit(EXIT_FAILURE);
        }

        writeC = write(fpwrite, &plh, 1); // write to file

        if(writeC == -1){
          printf("Error bij write to file (final check)\n");
          exit(EXIT_FAILURE);
        }
    }*/


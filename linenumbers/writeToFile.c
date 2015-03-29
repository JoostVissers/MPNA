#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "writeToFile.h"

void writeToFile(int fpToReadFrom,int fpToWriteTo){
    int readC;
    int writeC;
    char plh;

    while((readC = read(fpToReadFrom,&plh,1)) > 0){

      if(readC == -1){
        printf("Error bij read from child (final check)\n");
        exit(EXIT_FAILURE);
      }

      writeC = write(fpToWriteTo, &plh, 1); // write to file

      if(writeC == -1){
        printf("Error bij write to file (final check)\n");
        exit(EXIT_FAILURE);
      }
    }
}

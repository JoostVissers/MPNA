#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "parent.h"
#include "writeToFile.h"

void parent(int *ipPX, int *ipPY,char *filename) {

  int readC;
  char plh;
  int writeC = 0;

  close(ipPX[0]);
  close(ipPY[1]);

  int fp = open(filename, O_RDONLY);
  
  if(fp == -1){
      perror("fopen error:");
      exit(EXIT_FAILURE);
  }

  int fpwrite = open("dump.txt", O_WRONLY | O_TRUNC);

  if(fpwrite == -1){
      perror("fopen error:");
      exit(EXIT_FAILURE);
  }

  while((readC = read(fp,&plh,1)) > 0){
    if(readC == -1){
          printf("Error bij read from file\n");
          exit(EXIT_FAILURE);
    }
    writeC = write(ipPX[1], &plh, 1);//write to child

    if(writeC == -1){
        printf("Error bij write to child\n");
        exit(EXIT_FAILURE);
    }

    fcntl(ipPY[0], F_SETFL, O_NONBLOCK); // set nonblocking

    writeToFile(ipPY[0],fpwrite);

    fcntl(ipPY[0], F_SETFL, O_SYNC);
  }

  close(fp);
  close(ipPX[1]);

  writeToFile(ipPY[0],fpwrite);

  close(fpwrite);
  close(ipPY[0]);

  fp = open("dump.txt", O_RDONLY);
  if(fp == -1){
      perror("fopen error:");
      exit(EXIT_FAILURE);
  }

  fpwrite = open(filename, O_WRONLY | O_TRUNC);

  if(fpwrite == -1){
      perror("fopen error:");
      exit(EXIT_FAILURE);
  }

  writeToFile(fp,fpwrite);

  close(fp);
  close(fpwrite);
  
  wait(0);
}

/*
 * Joost Vissers
 * 17-02-2014
 * V:0.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <fcntl.h>
#include <unistd.h>

#define permissions 0600

int main(int argc, char *argv[]){

  int inputFile;
  int outputFile;
  char *inFilename = NULL;
  char *outFilename = NULL;

  int readLength;
  int writeLenght;
  char c;
  
  if( argc < 3 ){
      printf("Opdracht mist een parameter.\n");
      exit(EXIT_FAILURE);
  }
  else{
      inFilename = argv[1];//"text.txt";
      outFilename = argv[2];//"test.txt";
  }
  
 
  if((inputFile = open(inFilename,O_RDONLY)) < 0){
      perror("Fout opgetreden bij parameter 1 ");
      exit(EXIT_FAILURE);
  }  

  if((outputFile = open(outFilename, O_WRONLY|O_CREAT,permissions)) < 0){
      perror("Fout opgetreden bij parameter 2 ");
      exit(EXIT_FAILURE);
  }

  while((readLength = read(inputFile,&c,1))> 0){
      if(readLength < 0){
          perror("Fout opgetreden ");
          exit(EXIT_FAILURE);
      }
      else{
          c = c ^ 00011111;
          if((writeLenght = write(outputFile,&c,1)) < 0){
              perror("Fout opgetreden ");
              exit(EXIT_FAILURE);
          }
      }
  }

  close(inputFile);
  close(outputFile);

  return EXIT_SUCCESS;
}


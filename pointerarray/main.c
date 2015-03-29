/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 6, 2014, 3:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(char **a,int r1,int r2);
/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    char *woordenLijst[9] = { "woord1","woord2","woord3","woord4","woord5","woord6","woord7","woord8","woord9"};

    int i;
    for(i = 0; i < 9; i++){
      printf("%s\n",woordenLijst[i]);
    }
    printf("\n");

    int random1 = rand() % 9;
    int random2 = rand() % 9;

    printf("(Druk enter om verder te gaan)\n");
    char character = getchar();
    if(character == '\n'){
      //printf("%p\n",&woordenLijst[random1]);
      //printf("%p\n",&woordenLijst[random2]);
      swap(&woordenLijst[0],random1,random2);

      int j;
      for(j = 0; j < 9; j++){
        printf("%s\n",woordenLijst[j]);
      }
      
      time_t start = time(NULL);
      char invoernummer1;
      char invoernummer2;
      char dummy;
      //printf("%d -- %d\n",random1+1,random2+1);
      invoernummer1 = getchar();
      invoernummer2 = getchar();
      dummy = getchar();

      if(invoernummer1 == random1+49 && invoernummer2 == random2+49 || invoernummer2 == random1+49 && invoernummer1 == random2+49){
        time_t end = time(NULL);
        printf("\n%.f seconden zijn verlopen.\n",difftime(end,start));
      }
    }
    return (EXIT_SUCCESS);
}

void swap(char **woordenLijst,int r1,int r2){
    char *temp;

    temp = woordenLijst[r1];
    //printf("%p\n",temp);

    woordenLijst[r1] = woordenLijst[r2];
    //printf("%p\n",woordenLijst[r1]);

    woordenLijst[r2] = temp;
    //printf("%p\n",woordenLijst[r2]);
} 






/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 3, 2014, 3:30 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    char letters[10] = "lettertien";
    int i;
    int j;
    int aantal;
    
    for(i = 'a'; i < 'z'; i++){
      aantal = 0;
      for(j = 0; j < 10; j++){
        if(i == letters[j]){
            aantal++;
        }
      }
      if(aantal != 0){
        printf("%c : %d\n",i,aantal);
      }
    }

    return (EXIT_SUCCESS);

}







#include "split.h"
/*
** splitst str volgens scheidingsteken c in maximaal max woorden
** bij terugkeer bevat word[] pointers naar de afzonderlijke woorden
** de functiewaarde is het aantal woorden in str resp. word[]
** N.B. zorg dat word[] minimaal max elementen heeft!
*/

int split(char *str,char *word[],int max,char c){
   int n;

   n=0;
   do {
      while (*str==c) str++;
      if (!*str || n==max) return n;

      word[n++]=str++;
      while (*str && *str!=c) str++;

      if (!*str) return n;

      *str++ ='\0';
   } while (1);
} /* split */

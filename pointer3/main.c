/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 6, 2014, 12:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void PrintZin1(char **pVar);
void PrintZin2(char **pVar);

int main(void)
{
  char sWoord1[20] = "Klas";
  char sWoord2[20] = "MPNA";
  char *pZin[2];

  pZin[0] = &sWoord1[0];
  pZin[1] = &sWoord2[0];
  printf("Woord1: beginadres %x   inhoud %s\n", (int)pZin[0], pZin[0]);
  printf("Woord2: beginadres %x   inhoud %s\n", (int)pZin[1], pZin[1]);

  PrintZin1(&pZin[0]);
  PrintZin2(pZin);

  return 0;
}


void PrintZin1(char **pVar)
{
  printf("PrintZin1\n");
  printf("Zin : %s %s\n", pVar[0], pVar[1]);
}

void PrintZin2(char **pVar)
{
  printf("PrintZin2\n");
  printf("Zin : %s ", *pVar++);
  printf("%s\n", *pVar);
}

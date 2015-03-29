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

//Prototyping
void PrintDemo1(void);
void PrintDemo2(void);
void PrintDemo3(void);
void PrintDemo4(void);


int main(void)
{
  PrintDemo1();
  PrintDemo2();
  PrintDemo3();
  PrintDemo4();

  return(0);
}

// Verschillende manieren om de string 'sKlas' te printen:
// sKlas is hetzelfde &sKlas[0]:
// 		- sKlas is het beginadres van de string
//		- &sKlas[0] is het adres van het eerste element van de string
//		- en %s verwacht een pointer (=adres) naar een char string
//
// Men kan ook met een pointer de string doorlopen en karakter voor karakter printen
// Hierdoor initialiseert men eerst een pointer met het adres van het eerste karakter van de string
// Door de pointer te verhogen, wijst deze pointer naar het volgende karakter
// Met hoeveel bytes een pointer verhoogd wordt is afhankelijk van het type pointer:
// 		- hier is het type 'char' dus 1 byte
//		- zou de pointer van het type 'int' zijn, dan wordt er telkens met 4 byte verhoogd
//		- Zie variabelen tijdens het debuggen.
void PrintDemo1(void)
{
	char sKlas[16] = "IC1A";
	char *pK = NULL;		// initialiseer altijd een pointer naar NULL
	int i=0;

	printf("PrintDemo1\n");
	printf("Naam Klas: %s \n", sKlas);	// or
	printf("Naam Klas: %s \n", &sKlas[0]);
	printf("Naam Klas: ");
	pK = &sKlas[0];
	for(i=0; i< strlen(sKlas); i++)
	{
		printf("%c", *pK);
		pK++;
	}
	printf("\n");
}

// Een tweedimensionale array printen
void PrintDemo2(void)
{
	char acKlasseLijstIC1A[4][20] = {"Harm Verhoeven", "Karel Verbeek", "Joost Vermeulen", "Rick Troost"};
	int i=0;

	printf("PrintDemo2\n");
	printf("Klasselijst: ");
	for(i=0; i<4; i++)
	{
	  printf("%s ", acKlasseLijstIC1A[i]);
	}
	printf("\n");
}

// Een tweedimensionale array printen
// Deze tweedimensionale array is gedeclareerd als een eendimensionale array van char pointers
void PrintDemo3(void)
{
	char *apcKlasseLijstIC1B[4] = {"Klaas Vaak", "Pieter Storm", "Jan Jansen", "Harrie van Boven"};
	int i=0;

	printf("PrintDemo3\n");
	printf("Klasselijst: ");
	for(i=0; i<4; i++)
	{
	  printf("%s ", apcKlasseLijstIC1B[i]);
	}
	printf("\n");
}

// Een tweedimensionale array printen
// Deze tweedimensionale array is gedeclareerd als een eendimensionale array van char pointers
// Bij het printen wordt nu het incrementen van een pointer apcKL gebruikt om de array van pointers te doorlopen
// De sprongen die de pointer maakt is afhankelijk van de grootte van de afzonderlijke strings!!
// Start debugger en neem waar hoe apccKL verhoogd wordt.
void PrintDemo4(void)
{
	char *apcKlasseLijstIC1B[4] = {"Klaas Vaak", "Pieter Storm", "Jan Jansen", "Harrie van Boven"};
	char **apcKL = NULL;
	int i=0;

	printf("PrintDemo4\n");
	printf("Klasselijst: ");
	apcKL = &apcKlasseLijstIC1B[0];
	for(i=0; i<4; i++)
	{
	  printf("%s ", *apcKL++);
	}
	printf("\n");
}

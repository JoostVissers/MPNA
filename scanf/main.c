/* 
 * File:   main.c
 * Author: Carel
 *
 * Created on February 6, 2014, 9:48 AM
 */

#include <stdio.h>
#include <stdlib.h>

char leeswoord();
/*
 * 
 */
int main(int argc, char** argv) {
char vNaam[100]={};
char tVoegsel[100]={};
char aNaam[100]={};
char geslacht[100]={};
char sNummer[100]={};
char cBetaald[100]={};
char dummy;
    
    printf("geef u voornaam: ");
    scanf("%s",vNaam);
    scanf("%c",&dummy);

    printf("geef u achternaam: ");
    scanf("%s",aNaam);
    scanf("%c",&dummy);
    
    printf("geef u tussenvoegsel: ");
    scanf("%[^\n]s",tVoegsel);
    scanf("%c",&dummy);

    printf("m/v: ");
    scanf("%[mv]s",geslacht);
    scanf("%c",&dummy);

    printf("geef u studentnummer: ");
    scanf("%[0-9]s",sNummer);
    scanf("%c",&dummy);

    printf("Collegegeld: ");
    scanf("%[jn]s",cBetaald);
    scanf("%c",&dummy);

    printf("\nVoornaam: %s\nAchternaam: %s\nTussenvoegsel:%s\nGeslacht: %s\nStudentnummer: %s\nCollegegeld: %s\n",vNaam,aNaam,tVoegsel,geslacht,sNummer,cBetaald);

    return (EXIT_SUCCESS);
}
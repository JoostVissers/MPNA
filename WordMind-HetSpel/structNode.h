/* 
 * File:   structNode.h
 * Author: Carel
 *
 * Created on February 13, 2014, 10:57 AM
 */
#include <time.h>

#ifndef STRUCTNODE_H
#define	STRUCTNODE_H

/*
** pcWord:		pointer naar het geheime woord
** cMaxScore: 	maximum score
** tTime: 		datum en tijd in seconden
*/
typedef struct Node
	    {
	      char *pcWord;
              unsigned char cMaxScore;
              time_t tTime;
	    } Node;

#endif	/* STRUCTNODE_H */


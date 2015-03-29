/* 
 * File:   CompareWords.h
 * Author: Carel
 *
 * Created on February 10, 2014, 11:28 AM
 */

#ifndef COMPAREWORDS_H
#define	COMPAREWORDS_H

	/*
	** This function compares the strings sSecretWord and
	** sGuessedWord.  If both the value and the position of a
	** letter are correct, the letter is echoed in sResult at
	** the correct position.  If the value is correct, but
	** the position is not, then an asterisk (*) is echoed at
	** the corresponding position in sGuessedWord.  For all
	** remaining letters a hyphen (-) is echoed in sResult.
	** pre:  Length (sSecretWord) == Length (sGuessedWord)
	**       and sResult points to sufficient memory space
	**       to accommodate a string of at least the length
	**       of sSecretWord.
	** post: Length (sResult) == Length (sSecretWord) and the
	**       and the contents of sResult reflects the match
	**           between sSecretWord and sGuessedWord.
	*/
void comparewords (char *sSecretWord,char *sGuessedWord,char *sResult);


#endif	/* COMPAREWORDS_H */


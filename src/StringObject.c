#include "StringObject.h"
#include "Evaluate.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
 * This function will generate a string
 *
 * Input: *expression 		which contain the string(expression)
 * Output: none
 * return: Tokenizer 		which pass to the getToken to generate token.
 */
String *stringCreate(char *expression) {
	int length = strlen(expression);
	String *newString = malloc (sizeof(String));
	char *newRawString = malloc (length+1);
	
	newRawString = expression;
	newString->rawString = newRawString;
	newString->startIndex = 0;
	newString->length = strlen(newString->rawString);
	
	return newString;
}

/*
	This function is to copy string from the middle of the string for specific length.
	
	input :
	*source				The string that contain the wanted string.
	startLocation		The start location of the wanted string in source
	length 				The length of the wanted string 
	
	output:
	*destination 		The wanted string will be copied to this string.(must be in array to make this work)
	
	return:
	none
*/
void stringCopy(char *source, char*destination, int startLocation, int length) {
	int i, j = 0;

	for (i = 0; i < length; i++, j++) {
		destination[j]= source[startLocation+i];
	}

	destination[j] = '\0';
}
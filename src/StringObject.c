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




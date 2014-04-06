#include "StringObject.h"
#include "Evaluate.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Error.h"
#include "CException.h"

/*
 * This function will generate a string
 *
 * Input: *expression 		which contain the string(expression)
 * Output: none
 * return: Tokenizer 		which pass to the getToken to generate token.
 
 
 Throw:
	UNDEFINED_IDENTIFIER			if the expression contained undefined identifier
	INVALID_EXPRESSION				if the expression contained invalid expression (not following format)
 
 */
String *stringCreate(char *expression) {
	int length = strlen(expression);
	String *newString = malloc (sizeof(String));
	char *newRawString = malloc (length+1);
	int tempIndex,stringStartLocation,lengthOfTheIdentifier=0; 
	Token *newToken;
	char name[20];
	Error exception;
	stringCopy(expression, newRawString, 0, length);
	newString->rawString = newRawString;
	newString->startIndex = 0;
	newString->length = strlen(newString->rawString);
	Try
	{
	for(tempIndex=0;tempIndex<=newString->length;tempIndex++)
	{
		
		if (isalpha(newString->rawString[tempIndex])||(newString->rawString[tempIndex])=='.')
		{
				stringStartLocation=tempIndex;
				do
				{
					lengthOfTheIdentifier++;
					tempIndex++;
				}while(isalnum(newString->rawString[tempIndex])||(newString->rawString[tempIndex]=='.'));
				
				stringCopy(newString->rawString,name,stringStartLocation,lengthOfTheIdentifier);
				newToken=checkIdentifier(name);
				tempIndex-=lengthOfTheIdentifier+1;
				
				if(newToken==NULL)
				{
					if(name[0]==48||name[0]==98
						||name[0]==100||name[0]==104
						||name[0]==111)
					{
						newString = convertBasedNumberToBase10Number(newString);
						newString->startIndex++;
					}
					else
					{
						newString = getFromListAndUpdate(newString, name);
					}
				}
				else if(newToken!=NULL)
				{
					tempIndex += lengthOfTheIdentifier;
				}
				
				lengthOfTheIdentifier=0;
			
		}
		else
		{
			if(newString->rawString[tempIndex]==48||newString->rawString[tempIndex]==98
				||newString->rawString[tempIndex]==100||newString->rawString[tempIndex]==104
				||newString->rawString[tempIndex]==111)
			{
				newString = convertBasedNumberToBase10Number(newString);

			}
			newString->startIndex++;
		}
	}
	}
	Catch(exception)
	{
		errorMessage.rawString = newString->rawString;
		errorMessage.position = newString->startIndex;
		if(exception == UNDEFINED_IDENTIFIER)
		{
			Throw(UNDEFINED_IDENTIFIER);
		}
		else if(exception == INVALID_EXPRESSION)
		{
			Throw(INVALID_EXPRESSION);
		}
	}
	newString->startIndex=0;
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
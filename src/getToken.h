#ifndef __GETTOKEN_H__
#define __GETTOKEN_H__

#include "Evaluate.h"


//Function declaration

Token *getToken(String *tokenizer);

int isOperator (Token * unknownToken);
int isNumber (Token * unknownToken);

//Sub-function
Operator *detectOperator(String *tokenizer, int i);
Token *checkIdentifier(char *name);

#endif //__GETTOKEN_H__
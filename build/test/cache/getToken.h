#include "StringObject.h"
#include "Evaluate.h"












Token *getToken(String *tokenizer);



int isOperator(Token * unknownToken);

int isNumber(Token * unknownToken);





Operator *detectOperator(String *tokenizer, int i);

Token *checkIdentifier(char *name);

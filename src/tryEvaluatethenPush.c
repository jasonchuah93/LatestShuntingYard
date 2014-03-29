#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "Stack.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"

void tryEvaluatethenPush(Token *token,Stack *numberStack,Stack *operatorStack)
{
	Tokenizer *tokenizer;
	Token *token1; // operator token 1
	Token *token2; // number token 1
	Token *token3; // number token 2
	Token *token4; // operator token 2
	Token *ansToken; // result of token
	Operator *id1;
	Operator *id2;
	Number *value1;
	Number *value2;
	
	
		//use operator to compare
		//token1 = getToken(tokenizer);
		stackPush(token1,operatorStack);
	
	
		/*
		token1=(Token*)stackPop(operatorStack);
		id1=(Operator*)token1;
		token2=(Token*)stackPop(numberStack);
		value1=(Number*)token2;
		token3=(Token*)stackPop(numberStack);
		value2=(Number*)token3;
		ansToken = calculate(id1,value1,value2);
		stackPush(ansToken,numberStack);
		stackPush(token4,operatorStack);
		*/
	
}

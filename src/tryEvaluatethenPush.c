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
	Token *previousToken;
	if(operatorStack->topOfStack==NULL){
		stackPush(token,operatorStack);
	}
	else{
		stackPop(operatorStack,
}

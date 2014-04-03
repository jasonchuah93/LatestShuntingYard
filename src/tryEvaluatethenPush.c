#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "Stack.h"
#include "StringObject.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "createNumberToken.h" 
#include "LinkedList.h"
#include "stackForEvaluate.h"


void tryEvaluatethenPush(Token *token,Stack *numberStack,Stack *operatorStack)
{
	Token *previousToken;
	Token *numToken1;
	Token *numToken2;
	Number *number1;
	Number *number2;
	Operator *ope1;
	Operator *ope2;
	int tempAnswer;
	Token *tempAnswerToken;
	
	
	ope1=(Operator*)token;
	if(operatorStack->topOfStack==NULL){
		stackPush(token,operatorStack);

	}
	else
	{	
		previousToken=(Token*)stackPop(operatorStack);
		ope2=(Operator*)previousToken;
		if(ope1->precedence >= ope2->precedence)
		{	
			
			stackPush(token,operatorStack);
		}
		else 
		{
			numToken1=(Token*)stackPop(numberStack);
			number1=(Number*)numToken1;
			numToken2=(Token*)stackPop(numberStack);
			number2=(Number*)numToken2;
			tempAnswer=calculate(ope2,number2,number1);
			tempAnswerToken = createNumberToken(tempAnswer);
			stackPush(tempAnswerToken,numberStack);
			stackPush(token,operatorStack);
			
			
		}
	}
}

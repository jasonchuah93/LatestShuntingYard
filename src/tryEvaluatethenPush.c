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

/**
	Evaluate all operator token on the operator stack that have strictly lower
	precedence than the operator token to be pushed. The evaluation of operators token
	is from the top of stack to bottom
	
	Input :
		stack the operatorStack
		operator the operator to be pushed onto the operator stack 
		
**/
/*
void tryEvaluatethenPush(Token *token,Stack *numberStack,Stack *operatorStack)
{
	Token *previousToken;
	previousToken=(Operator*)pop(operatorStack);
	if(operatorSt){
		stackPush(token,operatorStack);
	}
	else
	{	
		previousToken=(Token*)stackPop(operatorStack);
		ope2=(Operator*)previousToken;
		ope1=(Operator*)token;
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
			printf("tempAns2 : %d \n",tempAnswer);
			stackPush(tempAnswerToken,numberStack);
			stackPush(token,operatorStack);
		}
	}
	
}
*/
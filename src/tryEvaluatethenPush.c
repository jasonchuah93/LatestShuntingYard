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
#include <malloc.h>

/**
	Evaluate all operator token on the operator stack that have strictly lower
	precedence than the operator token to be pushed. The evaluation of operators token
	is from the top of stack to bottom
	
	Input :
		stack the operatorStack
		operator the operator to be pushed onto the operator stack 
		
**/

void tryEvaluateOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack)
{
	Operator *previousToken;
	previousToken=(Operator*)stackPop(operatorStack);
	
	if(previousToken==NULL)
	{
		stackPush(newToken,operatorStack);
	}
	else{
		while(previousToken!=NULL)
		{
			if(newToken->precedence > previousToken->precedence)
			{
				break;
			}
			else 
			{
				operatorEvaluate(numberStack,previousToken);
			}
			
			previousToken=(Operator*)stackPop(operatorStack);
			
		}
		if(previousToken!=NULL)
		{
			stackPush(previousToken,operatorStack);
		}
		stackPush(newToken,operatorStack);
		
	}
}

void tryEvaluatePrefixOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack)
{
	Operator *previousToken;
	previousToken=(Operator*)stackPop(operatorStack);
	
	if(previousToken==NULL)
	{
		stackPush(newToken,operatorStack);
	}
	else{
		while(previousToken!=NULL)
		{
			if(newToken->precedence >= previousToken->precedence)
			{
				break;
			}
			else 
			{
				operatorPrefixEvaluate(numberStack,previousToken);
			}
			
			previousToken=(Operator*)stackPop(operatorStack);
			
		}
		if(previousToken!=NULL)
		{
			stackPush(previousToken,operatorStack);
		}
		stackPush(newToken,operatorStack);
		destroyStack(operatorStack);
	}
	
}
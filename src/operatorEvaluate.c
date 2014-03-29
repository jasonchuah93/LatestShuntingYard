#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "Stack.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"

/*
	This function is to evaluate the expression  
	
	input  : token
	output : none
	return : final token 
	Mocking function : 1)stackPop();   pop tokens from number stack or operator stack
					   2)calculate();  to calculate the token taken into 
*/	

void operatorEvaluate(Stack *numberStack , Stack *operatorStack){
	Token *token1; //operator Token
	Token *token2; // First number token
	Token *token3; // Second number token
	Token *ansToken; // The answer
	Operator *operation;
	Number *num1;
	Number *num2;

	token1=(Token*)stackPop(operatorStack);
	if(token1!=NULL)
	{
		operation=(Operator*)token1;
		token2=(Token*)stackPop(numberStack);
		num1=(Number*)token2;
		token3=(Token*)stackPop(numberStack);
		num2=(Number*)token3;
		ansToken = calculate(operation,num1,num2);
		stackPush(ansToken,numberStack);
	}
}	

#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "StringObject.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "Stack.h"
#include "stackForEvaluate.h"
#include "Error.h"

/*
	This function is to push tokens that tokenize from expression to stack 
	
	input  : expression 
	output : none
	return : token 
	Mocking function : 1)initTokenizer(); initialize expression into tokenizer
					   2)getToken();	  get tokens from the tokenizer
					   3)stackPush();   push tokens to number stack or operator stack
					  
*/	


int evaluate(char *expression){
	String *tokenizer;
	Token *token;
	Token *ansToken;
	ErrorCode exception;
	int i;
	int counter =0;
	Number *result;
	
	Stack *numberStack;
	numberStack=createStack();
	Stack *operatorStack;
	operatorStack=createStack();
	tokenizer = stringCreate(expression);
	if(expression ==NULL){	
		Throw(ERR_INVALID_EXPRESSION);
	}
	
	while((token=getToken(tokenizer))!=NULL){
		if(counter%2==0&&*token==OPERATOR){
			Throw(UNKNOWN_DATA);
		}
		else if(counter%2==1&&*token==NUMBER){
			Throw(UNKNOWN_OPERATOR);
		}
		
		if(isNumber(token)){
			
			stackPush(token,numberStack);
		}
		else if(isOperator(token)) 
		{
			tryEvaluateOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
		}
		
		counter ++;
	}
	evaluateAllOperatorOnStack(numberStack,operatorStack);
	result=(Number*)stackPop(numberStack);
	printf("Loop needed for each expression to completely evaluate : %d \n",counter);
	return result->value;
}









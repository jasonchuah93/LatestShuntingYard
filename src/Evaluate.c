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
#include "convertValue.h"
#include "CException.h"

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
	Error exception;
	int i;
	int counter =0;
	Number *result;
	
	Stack *numberStack;
	numberStack=createStack();
	Stack *operatorStack;
	operatorStack=createStack();
	tokenizer = stringCreate(expression);
	//Operator *prefixToken=(Operator*)token;
	if(expression ==NULL){	
		Throw(INVALID_EXPRESSION);
	}
	while((token=getToken(tokenizer))!=NULL){
		/*
		if(counter%2==0&&*token==OPERATOR){
			Throw(UNKNOWN_DATA);
			
		}
		else if(counter%2==1&&*token==NUMBER){
			Throw(UNKNOWN_OPERATOR);
		}
		*/
		
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
	destroyStack(numberStack);
	destroyStack(operatorStack);
	printf("Loop needed for each expression to completely evaluate : %d \n",counter);
	return result->value;
}

int prefixEvaluate(char *expression){
	String *tokenizer;
	Token *token;
	Token *ansToken;
	Error exception;
	int i;
	int counter =0;
	Number *result;
	
	Stack *numberStack;
	numberStack=createStack();
	Stack *operatorStack;
	operatorStack=createStack();
	tokenizer = stringCreate(expression);
	//Operator *prefixToken=(Operator*)token;
	if(expression ==NULL){	
		Throw(INVALID_EXPRESSION);
	}
	while((token=getToken(tokenizer))!=NULL){
		
		if(isOperator(token)) 
		{
			tryEvaluatePrefixOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
		}
		
		else if(isNumber(token)){
			
			stackPush(token,numberStack);
		}
		
		counter ++;
	}
	
	
	evaluatePrefixOperatorOnStack(numberStack,operatorStack);
	
	result=(Number*)stackPop(numberStack);
	destroyStack(numberStack);
	
	printf("Loop needed for each expression to completely evaluate : %d \n",counter);
	return result->value;
}

int universalEvaluate(char *expression){







}








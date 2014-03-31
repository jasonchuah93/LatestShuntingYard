#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "StringObject.h"
#include "Stack.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "LinkedList.h"

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
	int i;
	int counter =0;
	
	tokenizer = stringCreate(expression);
	if(expression ==NULL){	
		return 0;
	}
	
	while((token = getToken(tokenizer))!=NULL){
		if(isNumber(token)){
			Stack *createStack();
			stackPush(token,&numStack);
			
		}
		
		else if(isOperator(token)) 
		{
			tryEvaluatethenPush(token,&numStack,&opeStack);
			//stackPush(token,&opeStack);
		}
		counter ++;
	}
	 
	operatorEvaluate(&numStack,&opeStack);
	destroyStack(&numStack);
	return counter;
}







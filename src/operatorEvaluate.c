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

/*
	This function is to evaluate the expression and return final token
	
	input  : token
	output : none
	return : final token 
	
*/	

void operatorEvaluate(Stack *numberStack , Stack *operatorStack){
	Token *token1; //operator Token
	Token *token2; // First number token
	Token *token3; // Second number token
	int answer; // The answer
	Token *answerToken; //Cast answer into token
	Operator *operation; 
	Number *num1;
	Number *num2;
	
	
	token1=(Token*)stackPop(operatorStack); //Pop token from operator stack
	if(token1!=NULL) 
	{
		operation=(Operator*)token1; //Cast token1 into operator type
		token2=(Token*)stackPop(numberStack); //Pop token from number stack
		num1=(Number*)token2; //Cast the token2 into number type
		token3=(Token*)stackPop(numberStack); //Pop second token from number stack 
		num2=(Number*)token3; //Cast the token3 into number type
		answer = calculate(operation,num2,num1); //Calculate these token and return answer
		answerToken=createNumberToken(answer); //Cast the answer into token type
		stackPush(answerToken,numberStack); //Push back to number stack
	}
	destroyStack(operatorStack);
}	



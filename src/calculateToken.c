#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Evaluate.h"
#include "Stack.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "createNumberToken.h"

int calculate(Operator *opeToken, Number *first, Number *second){
	
	int answer;
	switch(opeToken->id)
	{	
		case MULTIPLY:
			answer=first->value*second->value;
		break;
		
		case DIVIDE:
			answer=first->value/second->value;
		break;
		case ADD:
			answer=first->value+second->value;
		break;	
		
		case SUBTRACT:
			answer=first->value-second->value;
		break;
		
		case BITWISE_AND:
			answer=first->value&second->value;
		break;
		
		case BITWISE_OR:
			answer=first->value|second->value;
		break;
		
		case BITWISE_XOR:
			answer=first->value^second->value;
		break;
	}
	
	return answer;
}
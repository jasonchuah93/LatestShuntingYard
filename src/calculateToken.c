#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "Stack.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "createNumberToken.h"

void *calculate(Operator *opeToken, Number *first, Number *second){
	Token *token;
	int number;
	first->value=number;
	second->value=number;
	switch(opeToken->id)
	{
		case MULTIPLY:
			createNumberToken(first->value * second->value);
		break;	
	}
	return token;
}
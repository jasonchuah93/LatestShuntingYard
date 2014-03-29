#include "unity.h"
#include "Evaluate.h"
#include "operatorEvaluate.h"
#include "stackForEvaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_Stack.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_calculateToken.h"
#include "mock_createNumberToken.h"

void setUp(void){}
void tearDown(void){}


void test_operator_evaluate_should_evaluate_2_PLUS_3(void){
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	int answer;
	Token *answerToken;
	
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,token1);
	stackPop_ExpectAndReturn(&numStack,token3);
	calculate_ExpectAndReturn(&plus,&number2,&number3,answer);
	createNumberToken_ExpectAndReturn(answer,answerToken);
	stackPush_Expect(answerToken,&numStack);
	operatorEvaluate(&numStack,&opeStack);
}


void test_operator_evaluate_should_evaluate_2_PLUS_3_MULTIPLY_4(void){
	
	Number number12 = {.type= NUMBER, .value=12};
	Token *token1 = (Token*)&number12;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token3 = (Token*)&number2;
	
	int answer;
	Token *answerToken;
	
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,token1);
	stackPop_ExpectAndReturn(&numStack,token3);
	calculate_ExpectAndReturn(&plus,&number12,&number2,answer);
	createNumberToken_ExpectAndReturn(answer,answerToken);
	stackPush_Expect(answerToken,&numStack);
	operatorEvaluate(&numStack,&opeStack);
	
}





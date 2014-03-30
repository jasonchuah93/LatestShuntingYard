#include "unity.h"
#include "Evaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_Stack.h"
#include "tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_calculateToken.h"
#include "stackForEvaluate.h"
#include "createNumberToken.h"


void setUp(void){}
void tearDown(void){}

void test_try_evaluate_2_PLUS_3_and_push_operator_token_if_top_of_stack_is_empty(void){
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD, .precedence=40};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Number answer = {.type=NUMBER, .value=5};
	Token *ansToken = (Token*)&answer;

	stackPush_Expect(token2,&opeStack);
	
	tryEvaluatethenPush(token2,&numStack,&opeStack);
}

void test_try_evaluate_2_PLUS_3_MULTIPLY_4_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD, .precedence=40};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY, .precedence=30};
	Token *token4 = (Token*)&multiply;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Number answer = {.type=NUMBER, .value=5};
	Token *ansToken = (Token*)&answer;
	
	
	stackPush_Expect(token4,&opeStack);
	
	tryEvaluatethenPush(token4,&numStack,&opeStack);
}


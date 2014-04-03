#include "unity.h"
#include "Evaluate.h"
#include "Stack.h"
#include "LinkedList.h"
#include "mock_StringObject.h"
#include "mock_getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "createNumberToken.h"

void setUp(void){}
void tearDown(void){}

void test_try_evaluate_2_PLUS_3_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD, .precedence=30};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	tryEvaluatethenPush(token2,numberStack,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(5,tempAns->value);
}

void test_try_evaluate_2_PLUS_3_MULTIPLY_4_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD, .precedence=30};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY, .precedence=60};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Stack *numberStack = createStack();
	Stack *operatorStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	tryEvaluatethenPush(token2,numberStack,operatorStack);
	stackPush(token3,numberStack);
	tryEvaluatethenPush(token4,numberStack,operatorStack);
	stackPush(token5,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(5,tempAns->value);
}
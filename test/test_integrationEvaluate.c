#include "unity.h"
#include "Evaluate.h"
#include "mock_StringObject.h"
#include "getToken.h"
#include "Stack.h"
#include "mock_tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "LinkedList.h"
#include "createNumberToken.h"

void setUp(void){}
void tearDown(void){}

/*
void test_shunting_yard_should_return_0_if_the_expression_is_null(){
	
	int check;
	String tokenizer = {.rawString = "NULL", .startIndex = 0, .length = 1};
	
	Number number2 = {.type= NUMBER, .value=0};
	Token *token1 = (Token*)&number2;
	
	stringCreate_ExpectAndReturn("NULL",&tokenizer);
	getToken_ExpectAndReturn(&tokenizer,0);
	//operatorEvaluate_Expect(&numStack,&opeStack);
	token1=(Token*)stackPop(&numStack);
	check=evaluate("NULL");
	TEST_ASSERT_EQUAL(0,check);
}
*/

void test_evaluate_2_PLUS_3(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Number answer = {.type=NUMBER, .value=5};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	//Initialize token and push token to stacks
	stringCreate_ExpectAndReturn("2+3",&tokenizer);
	
	getToken(&tokenizer);
	isNumber_(token1);
	stackPush(token1,&numStack);
	
	getToken(&tokenizer);
	isNumber(token2);
	isOperator(token2);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	
	getToken(&tokenizer);
	isNumber(token3);
	stackPush(token3,&numStack);
	getToken(&tokenizer);
	
	//function operatorEvaluate
	token2=(Token*)stackPop(&opeStack);
	token1=(Token*)stackPop(&numStack);
	token3=(Token*)stackPop(&numStack);
	calculate(&plus,&number2,&number3);
	stackPush(ansToken,&numStack);
	
	evaluate("2+3");
}


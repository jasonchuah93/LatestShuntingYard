#include "unity.h"



void setUp(void){}
void tearDown(void){}


void test_shunting_yard_should_return_0_if_the_expression_is_null(){
	/*
	int check;
	Tokenizer tokenizer = {.rawString = "0", .startIndex = 0, .length = 1};
	
	Number number2 = {.type= NUMBER, .value=0};
	Token *token1 = (Token*)&number2;
	
	initTokenizer_ExpectAndReturn(NULL,&tokenizer);
	
	check=evaluate(NULL);
	TEST_ASSERT_EQUAL(0,check);
	*/
}

/*
void test_evaluate_2_PLUS_3(void){
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};
	
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
	initTokenizer_ExpectAndReturn("2+3",&tokenizer);
	
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	
	//function operatorEvaluate
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,token1);
	stackPop_ExpectAndReturn(&numStack,token3);
	calculate_ExpectAndReturn(&plus,&number2,&number3,ansToken);
	stackPush_Expect(ansToken,&numStack);
	
	
	evaluate("2+3");
}
*/

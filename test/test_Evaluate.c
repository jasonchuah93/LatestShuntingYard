#include "unity.h"
#include "Evaluate.h"
#include "mock_Stack.h"
#include "LinkedList.h"
#include "mock_StringObject.h"
#include "mock_getToken.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_calculateToken.h"
#include "stackForEvaluate.h"


void setUp(void){}
void tearDown(void){}

/*
void test_shunting_yard_should_return_0_if_the_expression_is_null(){
	int check;
	String tokenizer = {.rawString = "0", .startIndex = 0, .length = 1};
	
	Number number2 = {.type= NUMBER, .value=0};
	Token *token1 = (Token*)&number2;
	
	stringCreate_ExpectAndReturn(NULL,&tokenizer);
	
	check=evaluate(NULL);
	TEST_ASSERT_EQUAL(0,check);
}


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
	
	//Evaluate the expression
	//Initialize token and push token to stacks
	stringCreate_ExpectAndReturn("2+3",&tokenizer);
	
	//Number token 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	
	//Number token 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);

	evaluate("2+3");
}

void test_evaluate_2_PLUS_3_MULTIPLY_4(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3*4", .startIndex = 0, .length = 5};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Number answer = {.type=NUMBER, .value=14};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2+3*4",&tokenizer);
	
	//Number token 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	//Number token 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Operator token multiply
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	//stackPush_Expect(token4,&opeStack);
	
	//Number token 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);

	evaluate("2+3*4");
}	


void test_evaluate_2_MULTIPLY_3_PLUS_4(void){	
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token2 = (Token*)&multiply;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Number answer = {.type=NUMBER, .value=10};
	Token *ansToken = (Token*)&answer;

	//Evaluate the expression
	stringCreate_ExpectAndReturn("2*3+4",&tokenizer);
	
	//Number token 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Operator token multiply
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	//Number token 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	//stackPush_Expect(token4,&opeStack);
	
	//Number token 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);

	evaluate("2*3+4");
}

void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token4 = (Token*)&multiply;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator plus1 = {.type= OPERATOR, .id = ADD};
	Token *token6 = (Token*)&plus1;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};
	Token *token8 = (Token*)&multiply1;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Number answer = {.type=NUMBER, .value=44};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2+3*4+5*6",&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	//stackPush_Expect(token4,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	//stackPush_Expect(token6,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	tryEvaluatethenPush_Expect(token8,&numStack,&opeStack);
	//stackPush_Expect(token8,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);

	evaluate("2+3*4+5*6");
}

void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token2 = (Token*)&multiply;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};
	Token *token6 = (Token*)&multiply1;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator plus1 = {.type= OPERATOR, .id = ADD};
	Token *token8 = (Token*)&plus1;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Number answer = {.type=NUMBER, .value=32};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2*3+4*5+6",&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	//stackPush_Expect(token4,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	
	//Token operator multiply 
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	//stackPush_Expect(token6,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	tryEvaluatethenPush_Expect(token8,&numStack,&opeStack);
	//stackPush_Expect(token8,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("2*3+4*5+6");

}

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){
	String tokenizer = {.rawString = "2|3+4*5-6-10", .startIndex = 0, .length = 11};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator OR = {.type= OPERATOR, .id = BITWISE_OR};
	Token *token2 = (Token*)&OR;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token6 = (Token*)&multiply;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator subtract = {.type= OPERATOR, .id = SUBTRACT};
	Token *token8 = (Token*)&subtract;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Operator subtract1 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token10 = (Token*)&subtract1;
	
	Number number10 = {.type= NUMBER, .value=10};
	Token *token11 = (Token*)&number10;
	
	Number answer = {.type=NUMBER, .value=7};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2|3+4*5-6-10",&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Token operator bitwize OR
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	//stackPush_Expect(token4,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	
	//Token operator multiply 
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	//stackPush_Expect(token6,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	tryEvaluatethenPush_Expect(token8,&numStack,&opeStack);
	//stackPush_Expect(token8,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,token10);
	isNumber_ExpectAndReturn(token10,0);
	isOperator_ExpectAndReturn(token10,1);
	tryEvaluatethenPush_Expect(token10,&numStack,&opeStack);
	//stackPush_Expect(token10,&opeStack);
	
	//Token	number 10 
	getToken_ExpectAndReturn(&tokenizer,token11);
	isNumber_ExpectAndReturn(token11,1);
	stackPush_Expect(token11,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);

	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("2|3+4*5-6-10");
	
}

void test_LEFT_PARENTHESIS_2_PLUS_3_RIGHT_PARENTHESIS_MULTIPLY_4(void){
	String tokenizer = {.rawString = "(2+3)*4", .startIndex = 0, .length = 7 };
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token1 = (Token*)&leftBracket;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token2 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token3 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token4 = (Token*)&number3;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token5 = (Token*)&rightBracket;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token6 = (Token*)&multiply;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token7 = (Token*)&number4;
	
	Number answer = {.type=NUMBER, .value=20};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("(2+3)*4",&tokenizer);
	
	//Token operator left parenthesis 
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	//stackPush_Expect(token1,&opeStack);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&numStack);
	
	//Token operator plus 
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	//stackPush_Expect(token3,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,1);
	stackPush_Expect(token4,&numStack);
	
	//Token operator right parenthesis
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	tryEvaluatethenPush_Expect(token5,&numStack,&opeStack);
	//stackPush_Expect(token5,&opeStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	//stackPush_Expect(token6,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("(2+3)*4");
}

void test_2_MULTIPLY_LEFT_PARENTHESIS_THREE_PLUS_FOUR_RIGHT_PARENTHESIS(void){
	String tokenizer = {.rawString = "2*(3+4)", .startIndex = 0, .length = 7 };
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token2 = (Token*)&multiply;
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token3 = (Token*)&leftBracket;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token4 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token5 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token6 = (Token*)&number4;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token7 = (Token*)&rightBracket;
	
	Number answer = {.type=NUMBER, .value=14};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2*(3+4)",&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	//Token operator left parenthesis
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	//stackPush_Expect(token3,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,1);
	stackPush_Expect(token4,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	tryEvaluatethenPush_Expect(token5,&numStack,&opeStack);
	//stackPush_Expect(token5,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,1);
	stackPush_Expect(token6,&numStack);
	
	//Token operator left parenthesis
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,0);
	isOperator_ExpectAndReturn(token7,1);
	tryEvaluatethenPush_Expect(token7,&numStack,&opeStack);
	//stackPush_Expect(token7,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("2*(3+4)");
}

void test_NEGATIVE_2_SHOULD_RETURN_NEGATIVE_2(void){
	String tokenizer = {.rawString = "-2", .startIndex = 0, .length = 2 };
	
	Operator subtract = {.type= OPERATOR, .id = SUBTRACT};
	Token *token1 = (Token*)&subtract;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token2 = (Token*)&number2;
	
	Number answer = {.type=NUMBER, .value=-2};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("-2",&tokenizer);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	//stackPush_Expect(token1,&opeStack);
	
	////Token number 2
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("-2");
}

void test_NEGATIVE_2_PLUS_NEGATIVE_3(void){
	String tokenizer = {.rawString = "-2+-3", .startIndex = 0, .length = 5 };
	
	Operator negative = {.type= OPERATOR, .id = SUBTRACT};
	Token *token1 = (Token*)&negative;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token2 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token3 = (Token*)&plus;
	
	Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token4 = (Token*)&negative2;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token5 = (Token*)&number3;
	
	Number answer = {.type=NUMBER, .value=-5};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("-2+-3",&tokenizer);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	//stackPush_Expect(token1,&opeStack);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	//stackPush_Expect(token3,&opeStack);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	//stackPush_Expect(token4,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("-2+-3");
}


void test_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_2(void){
	String tokenizer = {.rawString = "-----2", .startIndex = 0, .length = 6 };
	
	Operator negative = {.type= OPERATOR, .id = SUBTRACT};
	Token *token1 = (Token*)&negative;
	
	Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token2 = (Token*)&negative2;
	
	Operator negative3 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token3 = (Token*)&negative3;
	
	Operator negative4 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token4 = (Token*)&negative4;
	
	Operator negative5 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token5 = (Token*)&negative5;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token6 = (Token*)&number2;
	
	Number answer = {.type=NUMBER, .value=-2};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("-----2",&tokenizer);
	
	//Token operator negative
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	//stackPush_Expect(token1,&opeStack);
	
	//Token operator negative
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	//Token operator negative
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	//stackPush_Expect(token3,&opeStack);
	
	//Token operator negative
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	//stackPush_Expect(token4,&opeStack);
	
	//Token operator negative
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	tryEvaluatethenPush_Expect(token5,&numStack,&opeStack);
	//stackPush_Expect(token5,&opeStack);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("-----2");
	
}

void test_LEFT_PARENTHESIS_10_MULTIPLY_100_RIGHT_PARENTHESIS_DIVIDE_BY_LEFT_PARENTHESIS_LEFT_PARENTHESIS_NEGATIVE_5_MULTIPLY_6_RIGHT_PARENTHESIS_SUBTRACT_LEFT_PARENTHESIS_2_MINUS_30_RIGHT_PARENTHESIS_RIGHT_PARENTHESIS(void) {
	String tokenizer = {.rawString = "(10*100)/((-5*6)-(2-30))", .startIndex = 0, .length = 24 };
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token1 = (Token*)&leftBracket;
	
	Number number10 = {.type= NUMBER, .value=10};
	Token *token2 = (Token*)&number10;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token3 = (Token*)&multiply;
	
	Number number100 = {.type= NUMBER, .value=100};
	Token *token4 = (Token*)&number100;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token5 = (Token*)&rightBracket;
	
	Operator divide = {.type= OPERATOR, .id = DIVIDE};
	Token *token6 = (Token*)&divide;
	
	Operator leftBracket2 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token7 = (Token*)&leftBracket2;
	
	Operator leftBracket3 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token8 = (Token*)&leftBracket3;
	
	Operator negative = {.type= OPERATOR, .id = SUBTRACT};
	Token *token9 = (Token*)&negative;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token10 = (Token*)&number5;
	
	Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};
	Token *token11 = (Token*)&multiply1;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token12 = (Token*)&number6;
	
	Operator rightBracket1 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token13 = (Token*)&rightBracket1;
	
	Operator subtract = {.type= OPERATOR, .id = SUBTRACT};
	Token *token14 = (Token*)&subtract;
	
	Operator leftBracket4 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token15 = (Token*)&leftBracket4;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token16 = (Token*)&number2;
	
	Operator subtract2 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token17 = (Token*)&subtract2;
	
	Number number30 = {.type= NUMBER, .value=30};
	Token *token18 = (Token*)&number30;
	
	Operator rightBracket2 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token19 = (Token*)&rightBracket2;
	
	Operator rightBracket3 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token20 = (Token*)&rightBracket3;
	
	Number answer = {.type=NUMBER, .value=-500};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("(10*100)/((-5*6)-(2-30))",&tokenizer);
	
	//Token operator LEFT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	//stackPush_Expect(token1,&opeStack);
	
	//Token number 10
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&numStack);
	
	//Token operator MULTIPLY
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	//stackPush_Expect(token3,&opeStack);
	
	//Token number 100
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,1);
	stackPush_Expect(token4,&numStack);
	
	//Token operator RIGHT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	tryEvaluatethenPush_Expect(token5,&numStack,&opeStack);
	//stackPush_Expect(token5,&opeStack);
	
	//Token operator DIVIDE
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	//stackPush_Expect(token6,&opeStack);
	
	//Token operator LEFT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,0);
	isOperator_ExpectAndReturn(token7,1);
	tryEvaluatethenPush_Expect(token7,&numStack,&opeStack);
	//stackPush_Expect(token7,&opeStack);
	
	//Token operator LEFT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	tryEvaluatethenPush_Expect(token8,&numStack,&opeStack);
	//stackPush_Expect(token8,&opeStack);
	
	//Token operator NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,0);
	isOperator_ExpectAndReturn(token9,1);
	tryEvaluatethenPush_Expect(token9,&numStack,&opeStack);
	//stackPush_Expect(token9,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,token10);
	isNumber_ExpectAndReturn(token10,1);
	stackPush_Expect(token10,&numStack);
	
	//Token operator MULTIPLY
	getToken_ExpectAndReturn(&tokenizer,token11);
	isNumber_ExpectAndReturn(token11,0);
	isOperator_ExpectAndReturn(token11,1);
	tryEvaluatethenPush_Expect(token11,&numStack,&opeStack);
	//stackPush_Expect(token11,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,token12);
	isNumber_ExpectAndReturn(token12,1);
	stackPush_Expect(token12,&numStack);
	
	//Token operator RIGHT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token13);
	isNumber_ExpectAndReturn(token13,0);
	isOperator_ExpectAndReturn(token13,1);
	tryEvaluatethenPush_Expect(token13,&numStack,&opeStack);
	//stackPush_Expect(token13,&opeStack);
	
	//Token operator SUBTRACT
	getToken_ExpectAndReturn(&tokenizer,token14);
	isNumber_ExpectAndReturn(token14,0);
	isOperator_ExpectAndReturn(token14,1);
	tryEvaluatethenPush_Expect(token14,&numStack,&opeStack);
	//stackPush_Expect(token14,&opeStack);
	
	//Token operator LEFT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token15);
	isNumber_ExpectAndReturn(token15,0);
	isOperator_ExpectAndReturn(token15,1);
	tryEvaluatethenPush_Expect(token15,&numStack,&opeStack);
	//stackPush_Expect(token15,&opeStack);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token16);
	isNumber_ExpectAndReturn(token16,1);
	stackPush_Expect(token16,&numStack);
	
	//Token operator SUBTRACT
	getToken_ExpectAndReturn(&tokenizer,token17);
	isNumber_ExpectAndReturn(token17,0);
	isOperator_ExpectAndReturn(token17,1);
	tryEvaluatethenPush_Expect(token17,&numStack,&opeStack);
	//stackPush_Expect(token17,&opeStack);
	
	//Token number 30
	getToken_ExpectAndReturn(&tokenizer,token18);
	isNumber_ExpectAndReturn(token18,1);
	stackPush_Expect(token18,&numStack);

	//Token operator RIGHT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token19);
	isNumber_ExpectAndReturn(token19,0);
	isOperator_ExpectAndReturn(token19,1);
	tryEvaluatethenPush_Expect(token19,&numStack,&opeStack);
	//stackPush_Expect(token19,&opeStack);
	
	//Token operator RIGHT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token20);
	isNumber_ExpectAndReturn(token20,0);
	isOperator_ExpectAndReturn(token20,1);
	tryEvaluatethenPush_Expect(token20,&numStack,&opeStack);
	//stackPush_Expect(token20,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("(10*100)/((-5*6)-(2-30))");
}

void test_NEGATIVE_LEFT_PARENTHESIS_NEGATIVE_2_RIGHT_PARENTHESIS(void){
	String tokenizer = {.rawString = "-(-2)", .startIndex = 0, .length = 5 };
	
	Operator negative = {.type= OPERATOR, .id = SUBTRACT};
	Token *token1 = (Token*)&negative;

	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token2 = (Token*)&leftBracket;
	
	Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token3 = (Token*)&negative2;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token4 = (Token*)&number2;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token5 = (Token*)&rightBracket;
	
	Number answer = {.type=NUMBER, .value=2};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("-(-2)",&tokenizer);
	
	//Token operator NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	//stackPush_Expect(token1,&opeStack);
	
	//Token operator LEFT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	//Token operator NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	//stackPush_Expect(token3,&opeStack);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,1);
	stackPush_Expect(token4,&numStack);
	
	//Token operator RIGHT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	tryEvaluatethenPush_Expect(token5,&numStack,&opeStack);
	//stackPush_Expect(token5,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("-(-2)");
}

void test_NEGATIVE_LEFT_PARENTHESIS_POSITIVE_LEFT_PARENTHESIS_NEGATIVE_LEFT_PARENTHESIS__NEGATIVE_1_RIGHT_PARENTHESIS_MULTIPLY_3_RIGHT_PARENTHESIS_SUBTRACT_FOUR_RIGHT_PARENTHESIS(void){
	String tokenizer = {.rawString = "-(+(-(-1)*3)-4)", .startIndex = 0, .length = 15 };
	
	Operator negative = {.type= OPERATOR, .id = SUBTRACT};
	Token *token1 = (Token*)&negative;
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token2 = (Token*)&leftBracket;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token3 = (Token*)&plus;
	
	Operator leftBracket2 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token4 = (Token*)&leftBracket2;
	
	Operator subtract = {.type= OPERATOR, .id = SUBTRACT};
	Token *token5 = (Token*)&subtract;
	
	Operator leftBracket3 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};
	Token *token6 = (Token*)&leftBracket3;
	
	Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token7 = (Token*)&negative2;
	
	Number number1 = {.type= NUMBER, .value=1};
	Token *token8 = (Token*)&number1;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token9 = (Token*)&rightBracket;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token10 = (Token*)&multiply;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token11 = (Token*)&number3;
	
	Operator rightBracket1 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token12 = (Token*)&rightBracket1;
	
	Operator subtract2 = {.type= OPERATOR, .id = SUBTRACT};
	Token *token13 = (Token*)&subtract2;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token14 = (Token*)&number4;
	
	Operator rightBracket2 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};
	Token *token15 = (Token*)&rightBracket2;
	
	Number answer = {.type=NUMBER, .value=1};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("-(+(-(-1)*3)-4)",&tokenizer);
	
	//Token operator NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	tryEvaluatethenPush_Expect(token1,&numStack,&opeStack);
	//stackPush_Expect(token1,&opeStack);
	
	//Token operator LEFT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
	//stackPush_Expect(token2,&opeStack);
	
	//Token operator POSITIVE
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	tryEvaluatethenPush_Expect(token3,&numStack,&opeStack);
	//stackPush_Expect(token3,&opeStack);
	
	//Token operator LEFT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	tryEvaluatethenPush_Expect(token4,&numStack,&opeStack);
	//stackPush_Expect(token4,&opeStack);
	
	//Token operator NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	tryEvaluatethenPush_Expect(token5,&numStack,&opeStack);
	//stackPush_Expect(token5,&opeStack);
	
	//Token operator LEFT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	tryEvaluatethenPush_Expect(token6,&numStack,&opeStack);
	//stackPush_Expect(token6,&opeStack);
	
	//Token operator NEGATIVE
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,0);
	isOperator_ExpectAndReturn(token7,1);
	tryEvaluatethenPush_Expect(token7,&numStack,&opeStack);
	//stackPush_Expect(token7,&opeStack);
 
	//Token number 1
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,1);
	stackPush_Expect(token8,&numStack);
	
	//Token operator RIGHT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,0);
	isOperator_ExpectAndReturn(token9,1);
	tryEvaluatethenPush_Expect(token9,&numStack,&opeStack);
	//stackPush_Expect(token9,&opeStack);
	
	//Token operator MULTIPLY
	getToken_ExpectAndReturn(&tokenizer,token10);
	isNumber_ExpectAndReturn(token10,0);
	isOperator_ExpectAndReturn(token10,1);
	tryEvaluatethenPush_Expect(token10,&numStack,&opeStack);
	//stackPush_Expect(token10,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token11);
	isNumber_ExpectAndReturn(token11,1);
	stackPush_Expect(token11,&numStack);
	
	//Token operator RIGHT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token12);
	isNumber_ExpectAndReturn(token12,0);
	isOperator_ExpectAndReturn(token12,1);
	tryEvaluatethenPush_Expect(token12,&numStack,&opeStack);
	//stackPush_Expect(token12,&opeStack);
	
	//Token operator SUBTRACT
	getToken_ExpectAndReturn(&tokenizer,token13);
	isNumber_ExpectAndReturn(token13,0);
	isOperator_ExpectAndReturn(token13,1);
	tryEvaluatethenPush_Expect(token13,&numStack,&opeStack);
	//stackPush_Expect(token13,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token14);
	isNumber_ExpectAndReturn(token14,1);
	stackPush_Expect(token14,&numStack);
	
	//Token operator RIGHT BRACKET
	getToken_ExpectAndReturn(&tokenizer,token15);
	isNumber_ExpectAndReturn(token15,0);
	isOperator_ExpectAndReturn(token15,1);
	tryEvaluatethenPush_Expect(token15,&numStack,&opeStack);
	//stackPush_Expect(token15,&opeStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//ANSWER
	operatorEvaluate_Expect(&numStack,&opeStack);
	
	evaluate("-(+(-(-1)*3)-4)");
}
*/

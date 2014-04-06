#include "unity.h"
#include "Evaluate.h"
#include "mock_Stack.h"
#include "LinkedList.h"
#include "mock_StringObject.h"
#include "mock_getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "mock_createNumberToken.h"
#include "stackForEvaluate.h"
#include "Error.h"

void setUp(void){}
void tearDown(void){}

/*********************************************************************************************************************************
 Test on function evaluate
 Input parameter : 
					1)char *expression

 Using following mock function : 
								1)stringCreate()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
Using following real function : 
							1)operatorEvaluate(Stack *numberStack , Operator *opeToken);
							2)evaluateAllOperatorOnStack(Stack *numberStack,Stack *operatorStack);
							3)tryEvaluateOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack);
							4)calculate(Operator *opeToken, Number *first , Number *second);
 ********************************************************************************************************************************/	
void test_shunting_yard_should_return_0_if_the_expression_is_null(){
	int check;
	Stack numberStack;
	Stack operatorStack;
	ErrorCode exception;
	String tokenizer = {.rawString = "0", .startIndex = 0, .length=1};
	
	Number number2 = {.type= NUMBER, .value=0};
	Token *token1 = (Token*)&number2;
	
	createStack_ExpectAndReturn(&numberStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn(NULL,&tokenizer);
	
	Try
	{
		check = evaluate(NULL);
		TEST_FAIL_MESSAGE("Should throw Error no expression ");
	}
	Catch(exception)
	{
		TEST_ASSERT_EQUAL(ERR_INVALID_EXPRESSION,exception);
	}
}

void test_should_return_3_for_1_plus_2(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "1+2", .startIndex = 0, .length=3};
	
	Number number1 = {.type= NUMBER, .value=1};
	Token *token1 = (Token*)&number1;
	
	Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};
	Token *token2 = (Token*)&plus;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token3 = (Token*)&number2;
	
	Number answer = {.type= NUMBER, .value=3};
	Token *answerToken = (Token*)&answer;
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn("1+2",&tokenizer);
	//Number1
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&dataStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(token2,&operatorStack);
	
	//Number2
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&dataStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Calculation
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&dataStack,token3);
	stackPop_ExpectAndReturn(&dataStack,token1);
	createNumberToken_ExpectAndReturn(3,answerToken);
	stackPush_Expect(answerToken,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	stackPop_ExpectAndReturn(&dataStack,answerToken);
	
	check=evaluate("1+2");
	TEST_ASSERT_EQUAL(3,check);
	printf("Answer : %d ",check);
}

void test_should_return_6_for_60_divide_10(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "60/10", .startIndex = 0, .length=3};
	
	Number number60 = {.type= NUMBER, .value=60};
	Token *token1 = (Token*)&number60;
	
	Operator divide = {.type= OPERATOR, .id=DIVIDE, .precedence=100};
	Token *token2 = (Token*)&divide;
	
	Number number10 = {.type= NUMBER, .value=10};
	Token *token3 = (Token*)&number10;
	
	Number answer = {.type= NUMBER, .value=6};
	Token *answerToken = (Token*)&answer;
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn("60/10",&tokenizer);
	//Number60
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&dataStack);
	
	//Operator token divide
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(token2,&operatorStack);
	
	//Number10
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&dataStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Calculation
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&dataStack,token3);
	stackPop_ExpectAndReturn(&dataStack,token1);
	createNumberToken_ExpectAndReturn(6,answerToken);
	stackPush_Expect(answerToken,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	stackPop_ExpectAndReturn(&dataStack,answerToken);
	
	check=evaluate("60/10");
	TEST_ASSERT_EQUAL(6,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4(void){	
	
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token2 = (Token*)&multiply;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Number tempAnswer = {.type=NUMBER, .value=6};
	Token *tempAnsToken = (Token*)&tempAnswer;

	Number finalAnswer = {.type=NUMBER, .value=10};
	Token *finalAnsToken = (Token*)&finalAnswer;

	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	stringCreate_ExpectAndReturn("2*3+4",&tokenizer);
	
	//Number token 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Operator token multiply
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token2,&opeStack);
	
	//Number token 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Operator token plus cant push in and pop multiply out to evaluate
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(6,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token4,&opeStack);
	
	//Number token 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate expression
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(10,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,finalAnsToken); 
	check=evaluate("2*3+4");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d ",check);

}

void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token4 = (Token*)&multiply;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator plus1 = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token6 = (Token*)&plus1;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token8 = (Token*)&multiply1;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Number tempAnswer1 = {.type=NUMBER, .value=12};
	Token *tempAnsToken1 = (Token*)&tempAnswer1;
	
	Number tempAnswer2 = {.type=NUMBER, .value=14};
	Token *tempAnsToken2 = (Token*)&tempAnswer2;
	
	Number tempAnswer3 = {.type=NUMBER, .value=30};
	Token *tempAnsToken3 = (Token*)&tempAnswer3;
	
	Number finalAnswer = {.type=NUMBER, .value=44};
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	
	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	stringCreate_ExpectAndReturn("2+3*4+5*6",&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token2,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPush_Expect(token2,&opeStack);
	stackPush_Expect(token4,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	
	//Token operator plus could not push in as multiply has higher
	//precedence .
	//After evaluate multiply,plus still cannot push in as there is
	//one more plus token inside the stack.
	//Thus , plus token inside the stack need to be evaluate first
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,token3);
	createNumberToken_ExpectAndReturn(12,tempAnsToken1);
	stackPush_Expect(tempAnsToken1,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken1);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(14,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token6,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	stackPop_ExpectAndReturn(&opeStack,token6);
	stackPush_Expect(token6,&opeStack);
	stackPush_Expect(token8,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate expression
	stackPop_ExpectAndReturn(&opeStack,token8);
	stackPop_ExpectAndReturn(&numStack,token9);
	stackPop_ExpectAndReturn(&numStack,token7);
	createNumberToken_ExpectAndReturn(30,tempAnsToken3);
	stackPush_Expect(tempAnsToken3,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token6);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken3);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken2);
	createNumberToken_ExpectAndReturn(44,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,finalAnsToken); 
	check=evaluate("2+3*4+5*6");
	TEST_ASSERT_EQUAL(44,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token2 = (Token*)&multiply;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token6 = (Token*)&multiply1;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator plus1 = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token8 = (Token*)&plus1;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Number tempAnswer1 = {.type=NUMBER, .value=6};
	Token *tempAnsToken1 = (Token*)&tempAnswer1;
	
	Number tempAnswer2 = {.type=NUMBER, .value=20};
	Token *tempAnsToken2 = (Token*)&tempAnswer2;
	
	Number tempAnswer3 = {.type=NUMBER, .value=26};
	Token *tempAnsToken3 = (Token*)&tempAnswer3;
	
	Number finalAnswer = {.type=NUMBER, .value=32};
	Token *finalAnsToken = (Token*)&finalAnswer;

	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	stringCreate_ExpectAndReturn("2*3+4*5+6",&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token2,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(6,tempAnsToken1);
	stackPush_Expect(tempAnsToken1,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token4,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	
	//Token operator multiply 
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPush_Expect(token4,&opeStack);
	stackPush_Expect(token6,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	stackPop_ExpectAndReturn(&opeStack,token6);
	stackPop_ExpectAndReturn(&numStack,token7);
	stackPop_ExpectAndReturn(&numStack,token5);
	createNumberToken_ExpectAndReturn(20,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken2);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken1);
	createNumberToken_ExpectAndReturn(26,tempAnsToken3);
	stackPush_Expect(tempAnsToken3,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token8,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);

	//Evaluate expression
	stackPop_ExpectAndReturn(&opeStack,token8);
	stackPop_ExpectAndReturn(&numStack,token9);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken3);
	createNumberToken_ExpectAndReturn(32,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,finalAnsToken); 
	
	check=evaluate("2*3+4*5+6");
	TEST_ASSERT_EQUAL(32,check);
	printf("Answer : %d ",check);

	
	
	

}

/*
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

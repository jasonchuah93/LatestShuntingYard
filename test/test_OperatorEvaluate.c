#include "unity.h"
#include "Evaluate.h"
#include "LinkedList.h"
#include "mock_Stack.h"
#include "mock_StringObject.h"
#include "mock_getToken.h"
#include "mock_tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "mock_createNumberToken.h"
#include "Error.h"

void setUp(void){}
void tearDown(void){}

/***********************************************************************	
 Test on function operatorEvaluate
 ***********************************************************************/	
 void test_operatorEvaluate_should_throw_error_when_encounter_invalid_operator(void){
	
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	ErrorCode exception;
	
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "1$2", .startIndex = 0, .length=3};
	Number number1 = {.type= NUMBER, .value=1};
	Operator currentProgramCounter = {.type= OPERATOR, .id=CURRENT_PROGRAM_COUNTER , .precedence =0};
	Number number2 = {.type= NUMBER, .value=2};
	
	stackPop_ExpectAndReturn(&numberStack,&number1);
	stackPop_ExpectAndReturn(&numberStack,&number2);
	
	Try{
		 operatorEvaluate(&numberStack,&currentProgramCounter);
		TEST_FAIL_MESSAGE("Invalid Operator should throw Error Not Operator");
	}
	Catch(exception){
		TEST_ASSERT_EQUAL(UNKNOWN_OPERATOR,exception);
	}
}	

void test_operatorEvaluate_3_PLUS_7(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "3+7", .startIndex = 0, .length=3};
	Number number3 = {.type= NUMBER, .value=3};
	Operator plus = {.type= OPERATOR, .id=ADD , .precedence=70};
	Number number7 = {.type= NUMBER, .value=7};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number7);
	stackPop_ExpectAndReturn(&numberStack,&number3);
	createNumberToken_ExpectAndReturn(10,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&plus);
}

void test_operatorEvaluate_100_MINUS_37(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "100-37", .startIndex = 0, .length=3};
	Number number100 = {.type= NUMBER, .value=100};
	Operator minus = {.type= OPERATOR, .id=SUBTRACT , .precedence=70};
	Number number37 = {.type= NUMBER, .value=37};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number37);
	stackPop_ExpectAndReturn(&numberStack,&number100);
	createNumberToken_ExpectAndReturn(63,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&minus);
}

void test_operatorEvaluate_100_MULTIPLY_50(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "100*50", .startIndex = 0, .length=3};
	Number number100 = {.type= NUMBER, .value=100};
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY , .precedence=100};
	Number number50 = {.type= NUMBER, .value=50};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number50);
	stackPop_ExpectAndReturn(&numberStack,&number100);
	createNumberToken_ExpectAndReturn(5000,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&multiply);
}

void test_operatorEvaluate_99_DIVIDE_3(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "99/3", .startIndex = 0, .length=3};
	Number number99 = {.type= NUMBER, .value=99};
	Operator divide = {.type= OPERATOR, .id=DIVIDE , .precedence=100};
	Number number3 = {.type= NUMBER, .value=3};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number3);
	stackPop_ExpectAndReturn(&numberStack,&number99);
	createNumberToken_ExpectAndReturn(33,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&divide);
}

void test_operatorEvaluate_60_MODULUS_7(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "60%7", .startIndex = 0, .length=3};
	Number number60 = {.type= NUMBER, .value=60};
	Operator modulus = {.type= OPERATOR, .id=MODULUS , .precedence=100};
	Number number7 = {.type= NUMBER, .value=7};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number7);
	stackPop_ExpectAndReturn(&numberStack,&number60);
	createNumberToken_ExpectAndReturn(4,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&modulus);
}

void test_operatorEvaluate_45_BITWISEAND_54(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "45&54", .startIndex = 0, .length=3};
	Number number45 = {.type= NUMBER, .value=45};
	Operator bitwiseAND = {.type= OPERATOR, .id=BITWISE_AND , .precedence=20};
	Number number54 = {.type= NUMBER, .value=54};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number54);
	stackPop_ExpectAndReturn(&numberStack,&number45);
	createNumberToken_ExpectAndReturn(36,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&bitwiseAND);
}





































































































/*
void test_operator_evaluate_should_evaluate_99_PLUS_99(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "99+99", .startIndex = 0, .length = 3};
	
	Number numberA99 = {.type= NUMBER, .value=99};
	Token *token1 = (Token*)&numberA99;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number numberB99 = {.type= NUMBER, .value=99};
	Token *token3 = (Token*)&numberB99;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(198,tempAns->value);
}

void test_operator_evaluate_should_evaluate_2_PLUS_3(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
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
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(5,tempAns->value);
}

void test_operator_evaluate_should_evaluate_20_MINUS_15(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "20-15", .startIndex = 0, .length = 3};
	
	Number number20 = {.type= NUMBER, .value=20};
	Token *token1 = (Token*)&number20;
	
	Operator minus = {.type= OPERATOR, .id = SUBTRACT};
	Token *token2 = (Token*)&minus;
	
	Number number15 = {.type= NUMBER, .value=15};
	Token *token3 = (Token*)&number15;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(5,tempAns->value);
}

void test_operator_evaluate_should_evaluate_100_MINUS_67(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "100-67", .startIndex = 0, .length = 3};
	
	Number number100 = {.type= NUMBER, .value=100};
	Token *token1 = (Token*)&number100;
	
	Operator minus = {.type= OPERATOR, .id = SUBTRACT};
	Token *token2 = (Token*)&minus;
	
	Number number67 = {.type= NUMBER, .value=67};
	Token *token3 = (Token*)&number67;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(33,tempAns->value);
}

void test_operator_evaluate_should_evaluate_100_MULTIPLY_67(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "100*67", .startIndex = 0, .length = 3};
	
	Number number100 = {.type= NUMBER, .value=100};
	Token *token1 = (Token*)&number100;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY};
	Token *token2 = (Token*)&multiply;
	
	Number number67 = {.type= NUMBER, .value=67};
	Token *token3 = (Token*)&number67;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(6700,tempAns->value);
}

void test_operator_evaluate_should_evaluate_100_DIVIDE_67(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "100*10", .startIndex = 0, .length = 3};
	
	Number number100 = {.type= NUMBER, .value=100};
	Token *token1 = (Token*)&number100;
	
	Operator divide = {.type= OPERATOR, .id = DIVIDE};
	Token *token2 = (Token*)&divide;
	
	Number number10 = {.type= NUMBER, .value=10};
	Token *token3 = (Token*)&number10;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(10,tempAns->value);
}

void test_operator_evaluate_should_evaluate_10000_DIVIDE_20(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "10000*20", .startIndex = 0, .length = 3};
	
	Number number10000 = {.type= NUMBER, .value=10000};
	Token *token1 = (Token*)&number10000;
	
	Operator divide = {.type= OPERATOR, .id = DIVIDE};
	Token *token2 = (Token*)&divide;
	
	Number number20 = {.type= NUMBER, .value=20};
	Token *token3 = (Token*)&number20;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(500,tempAns->value);
}

void test_operator_evaluate_should_evaluate_56_BITWISE_AND_30(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "56&30", .startIndex = 0, .length = 3};
	
	Number number56 = {.type= NUMBER, .value=56};
	Token *token1 = (Token*)&number56;
	
	Operator bitwizeAND = {.type= OPERATOR, .id = BITWISE_AND};
	Token *token2 = (Token*)&bitwizeAND;
	
	Number number30 = {.type= NUMBER, .value=30};
	Token *token3 = (Token*)&number30;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(24,tempAns->value);
}

void test_operator_evaluate_should_evaluate_90_BITWISE_OR_20(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "90|20", .startIndex = 0, .length = 3};
	
	Number number90 = {.type= NUMBER, .value=90};
	Token *token1 = (Token*)&number90;
	
	Operator bitwizeOR = {.type= OPERATOR, .id = BITWISE_OR};
	Token *token2 = (Token*)&bitwizeOR;
	
	Number number20 = {.type= NUMBER, .value=20};
	Token *token3 = (Token*)&number20;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(94,tempAns->value);
}

void test_operator_evaluate_should_evaluate_99_BITWISE_XOR_66(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "99^66", .startIndex = 0, .length = 3};
	
	Number number99 = {.type= NUMBER, .value=99};
	Token *token1 = (Token*)&number99;
	
	Operator bitwizeXOR = {.type= OPERATOR, .id = BITWISE_XOR};
	Token *token2 = (Token*)&bitwizeXOR;
	
	Number number66 = {.type= NUMBER, .value=66};
	Token *token3 = (Token*)&number66;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(33,tempAns->value);
}

void test_operator_evaluate_should_evaluate_33_BITWISE_XOR_44(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "33^44", .startIndex = 0, .length = 3};
	
	Number number33 = {.type= NUMBER, .value=33};
	Token *token1 = (Token*)&number33;
	
	Operator bitwizeXOR = {.type= OPERATOR, .id = BITWISE_XOR};
	Token *token2 = (Token*)&bitwizeXOR;
	
	Number number44 = {.type= NUMBER, .value=44};
	Token *token3 = (Token*)&number44;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(13,tempAns->value);
}

void test_operator_evaluate_should_evaluate_55_MUDULUS_3(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "55^3", .startIndex = 0, .length = 3};
	
	Number number55 = {.type= NUMBER, .value=55};
	Token *token1 = (Token*)&number55;
	
	Operator modulus = {.type= OPERATOR, .id = MODULUS};
	Token *token2 = (Token*)&modulus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(1,tempAns->value);
}

void test_operator_evaluate_should_evaluate_68_MUDULUS_7(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "68^7", .startIndex = 0, .length = 3};
	
	Number number68 = {.type= NUMBER, .value=68};
	Token *token1 = (Token*)&number68;
	
	Operator modulus = {.type= OPERATOR, .id = MODULUS};
	Token *token2 = (Token*)&modulus;
	
	Number number7 = {.type= NUMBER, .value=7};
	Token *token3 = (Token*)&number7;
	
	Stack *operatorStack = createStack();
	Stack *numberStack = createStack();
	
	TEST_ASSERT_NOT_NULL(operatorStack);
	TEST_ASSERT_NOT_NULL(numberStack);
	TEST_ASSERT_NULL(operatorStack->topOfStack);
	TEST_ASSERT_NULL(numberStack->topOfStack);
	
	stackPush(token1,numberStack);
	stackPush(token2,operatorStack);
	stackPush(token3,numberStack);
	
	operatorEvaluate(numberStack ,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	TEST_ASSERT_EQUAL(5,tempAns->value);
}
*/
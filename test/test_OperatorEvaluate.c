#include "unity.h"
#include "Evaluate.h"
#include "Stack.h"
#include "LinkedList.h"
#include "mock_StringObject.h"
#include "mock_getToken.h"
#include "mock_tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "createNumberToken.h"

void setUp(void){}
void tearDown(void){}

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
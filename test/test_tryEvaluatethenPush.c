#include "unity.h"
#include "Evaluate.h"
#include "mock_Stack.h"
#include "LinkedList.h"
#include "mock_StringObject.h"
#include "mock_getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "mock_createNumberToken.h"

void setUp(void){}
void tearDown(void){}

/***********************************************************************	
 Test on tryEvaluateOperatorOnStackThenPush
 Input parameter : 
					1)Operator *newToken
					2)Stack *numberStack
					3)Stack *operatorStack

 Using following mock function : 
								1)stringCreate()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
								6)operatorEvaluate
								
 ***********************************************************************/	

 void test_tryEvaluateOperatorOnStackThenPush_will_push_OperatorToken_if_Operator_Stack_is_empty(void){
	Stack numberStack;
	Stack operatorStack;
	Operator *opeToken;
	
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(opeToken,&operatorStack);
	tryEvaluateOperatorOnStackThenPush(opeToken,&numberStack,&operatorStack);
}
 
void test_tryEvaluateOperatorOnStaclThenPush_will_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_higher_than_previousToken(void)
{
	Stack numberStack;
	Stack operatorStack;
	
	Operator plus = {.type= OPERATOR, .id=ADD , .precedence =70};
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY , .precedence =100};
	
	stackPop_ExpectAndReturn(&operatorStack,&plus);
	stackPush_Expect(&plus,&operatorStack);
	stackPush_Expect(&multiply,&operatorStack);
	tryEvaluateOperatorOnStackThenPush(&multiply,&numberStack,&operatorStack);
}
 
void test_tryEvaluateOperatorOnStackThenPush_will_not_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_lower_than_previousToken(void)
{
	Stack numberStack;
	Stack operatorStack;
	
	//1*2+3
	Number number1 = {.type= NUMBER, .value=1};
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY, .precedence=100};
	Number number2 = {.type= NUMBER, .value=2};
	Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};
	Number number3 = {.type= NUMBER, .value=3};
	
	Number tempAns = {.type= NUMBER, .value=2};
	Token *tempAnsToken =(Token*)&tempAns;
	stackPop_ExpectAndReturn(&operatorStack,&multiply);
	stackPop_ExpectAndReturn(&numberStack,&number2);
	stackPop_ExpectAndReturn(&numberStack,&number1);
	createNumberToken_ExpectAndReturn(2,tempAnsToken);
	stackPush_Expect(&tempAns,&numberStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(&plus,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&plus,&numberStack,&operatorStack);
}
 
 void test_tryEvaluateOperatorOnStackThenPush_evaluate_newToke_and_previousToken_if_both_have_same_precedence(void)
{
	Stack numberStack;
	Stack operatorStack;
	
	//100-20-16
	Number number100 = {.type= NUMBER, .value=100};
	Operator minus = {.type= OPERATOR, .id=SUBTRACT, .precedence=70};
	Number number20 = {.type= NUMBER, .value=20};
	Operator minusA = {.type= OPERATOR, .id=SUBTRACT , .precedence=70};
	Number number16 = {.type= NUMBER, .value=16};
	Number tempAns = {.type= NUMBER, .value=80};
	Token *tempAnsToken =(Token*)&tempAns;
	
	stackPop_ExpectAndReturn(&operatorStack,&minus);
	stackPop_ExpectAndReturn(&numberStack,&number20);
	stackPop_ExpectAndReturn(&numberStack,&number100);
	createNumberToken_ExpectAndReturn(80,tempAnsToken);
	stackPush_Expect(&tempAns,&numberStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(&minusA,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&minusA,&numberStack,&operatorStack);
}

void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_1(void)
{
	Stack numberStack;
	Stack operatorStack;
	//21*22+30/6
	Number number21 = {.type= NUMBER, .value=21};
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY, .precedence=100};
	Number number22 = {.type= NUMBER, .value=22};
	
	Number tempAns = {.type= NUMBER, .value=462};
	Token *tempAnsToken =(Token*)&tempAns;
	
	Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};
	Number number30 = {.type= NUMBER, .value=30};
	Operator divide = {.type= OPERATOR, .id=DIVIDE, .precedence=100};
	Number number6 = {.type= NUMBER, .value=6};
	
		
	stackPop_ExpectAndReturn(&operatorStack,&multiply);
	stackPop_ExpectAndReturn(&numberStack,&number22);
	stackPop_ExpectAndReturn(&numberStack,&number21);
	createNumberToken_ExpectAndReturn(462,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numberStack);

	stackPop_ExpectAndReturn(&operatorStack,&plus);
	stackPush_Expect(&plus,&operatorStack);
	stackPush_Expect(&divide,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&divide,&numberStack,&operatorStack);
}

void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_2(void)
{
	Stack dataStack;
	Stack operatorStack;
	//21+22&30|6
	Number number21 = {.type= NUMBER, .value=21};
	Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};
	Number number22 = {.type= NUMBER, .value=22};
	
	Number tempAns1 = {.type= NUMBER, .value=43};
	Token *tempAnsToken1 =(Token*)&tempAns1;
	
	Operator bitwiseAND = {.type= OPERATOR, .id=BITWISE_AND, .precedence=20};
	Number number30 = {.type= NUMBER, .value=30};
	Operator bitwiseOR = {.type= OPERATOR, .id=BITWISE_OR, .precedence=10};
	Number number6 = {.type= NUMBER, .value=6};
	
	Number tempAns2 = {.type= NUMBER, .value=6};
	Token *tempAnsToken2 =(Token*)&tempAns2;
	
	stackPop_ExpectAndReturn(&operatorStack,&plus);
	stackPop_ExpectAndReturn(&dataStack,&number22);
	stackPop_ExpectAndReturn(&dataStack,&number21);
	createNumberToken_ExpectAndReturn(43,tempAnsToken1);
	stackPush_Expect(tempAnsToken1,&dataStack);

	stackPop_ExpectAndReturn(&operatorStack,&bitwiseAND);
	stackPop_ExpectAndReturn(&dataStack,&number30);
	stackPop_ExpectAndReturn(&dataStack,&number6);
	createNumberToken_ExpectAndReturn(6,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&dataStack);
	
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(&bitwiseOR,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&bitwiseOR,&dataStack,&operatorStack);
}

 
 
 
 
 
 
 
 
 
 
 
 /*
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

void test_try_evaluate_20_MINUS_3_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "20-3", .startIndex = 0, .length = 3};
	
	Number number20 = {.type= NUMBER, .value=20};
	Token *token1 = (Token*)&number20;
	
	Operator minus = {.type= OPERATOR, .id = SUBTRACT, .precedence=30};
	Token *token2 = (Token*)&minus;
	
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
	TEST_ASSERT_EQUAL(17,tempAns->value);
}

void test_try_evaluate_56_MULTIPLY_5_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "56*5", .startIndex = 0, .length = 3};
	
	Number number56 = {.type= NUMBER, .value=56};
	Token *token1 = (Token*)&number56;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY, .precedence=60};
	Token *token2 = (Token*)&multiply;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token3 = (Token*)&number5;
	
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
	TEST_ASSERT_EQUAL(280,tempAns->value);
}

void test_try_evaluate_55_DIVIDE_11_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "55/11", .startIndex = 0, .length = 3};
	
	Number number55 = {.type= NUMBER, .value=55};
	Token *token1 = (Token*)&number55;
	
	Operator divide = {.type= OPERATOR, .id = DIVIDE, .precedence=60};
	Token *token2 = (Token*)&divide;
	
	Number number11 = {.type= NUMBER, .value=11};
	Token *token3 = (Token*)&number11;
	
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

void test_try_evaluate_99_MODULUS_8_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "99%8", .startIndex = 0, .length = 3};
	
	Number number99 = {.type= NUMBER, .value=99};
	Token *token1 = (Token*)&number99;
	
	Operator modulus = {.type= OPERATOR, .id = MODULUS, .precedence=30};
	Token *token2 = (Token*)&modulus;
	
	Number number8 = {.type= NUMBER, .value=8};
	Token *token3 = (Token*)&number8;
	
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
	TEST_ASSERT_EQUAL(3,tempAns->value);
}

void test_try_evaluate_71_BITWISEAND_45_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "71&45", .startIndex = 0, .length = 3};
	
	Number number71 = {.type= NUMBER, .value=71};
	Token *token1 = (Token*)&number71;
	
	Operator bitwiseAnd = {.type= OPERATOR, .id = BITWISE_AND, .precedence=10};
	Token *token2 = (Token*)&bitwiseAnd;
	
	Number number45 = {.type= NUMBER, .value=45};
	Token *token3 = (Token*)&number45;
	
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

void test_try_evaluate_71_BITWISEOR_45_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	int tempAnswer;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "71|45", .startIndex = 0, .length = 3};
	
	Number number71 = {.type= NUMBER, .value=71};
	Token *token1 = (Token*)&number71;
	
	Operator bitwiseOR = {.type= OPERATOR, .id = BITWISE_OR, .precedence=10};
	Token *token2 = (Token*)&bitwiseOR;
	
	Number number45 = {.type= NUMBER, .value=45};
	Token *token3 = (Token*)&number45;
	
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
	TEST_ASSERT_EQUAL(111,tempAns->value);
}

void test_try_evaluate_71_BITWISEXOR_45_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	Token *tempToken;
	Number *tempAns;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "71^45", .startIndex = 0, .length = 3};
	
	Number number71 = {.type= NUMBER, .value=71};
	Token *token1 = (Token*)&number71;
	
	Operator bitwiseXOR = {.type= OPERATOR, .id = BITWISE_XOR, .precedence=10};
	Token *token2 = (Token*)&bitwiseXOR;
	
	Number number45 = {.type= NUMBER, .value=45};
	Token *token3 = (Token*)&number45;
	
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
	TEST_ASSERT_EQUAL(106,tempAns->value);
}


void test_try_evaluate_5_PLUS_6_MULTIPLY_7_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	Token *tempToken;
	Token *finalToken;
	Number *tempAns;
	Number *finalAns;
	
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "5+6*7", .startIndex = 0, .length = 3};
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token1 = (Token*)&number5;
	
	Operator plus = {.type= OPERATOR, .id = ADD, .precedence=30};
	Token *token2 = (Token*)&plus;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token3 = (Token*)&number6;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY, .precedence=60};
	Token *token4 = (Token*)&multiply;
	
	Number number7 = {.type= NUMBER, .value=7};
	Token *token5 = (Token*)&number7;
	
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
	
	operatorEvaluate(numberStack,operatorStack);
	tempToken=(Token*)stackPop(numberStack);
	tempAns=(Number*)tempToken;
	printf("tempAns : %d \n",tempAns->value);
	stackPush(tempToken,numberStack);
	
	//halfOperatorEvaluate(numberStack,operatorStack);
	finalToken=(Token*)stackPop(numberStack);
	finalAns=(Number*)finalToken;
	printf("finalAns : %d \n",finalAns->value);
	TEST_ASSERT_EQUAL(10,finalAns->value);
	
}
*/
#include "unity.h"
#include "Evaluate.h"
#include "Stack.h"
#include "LinkedList.h"
#include "mock_StringObject.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "createNumberToken.h"
#include "stackForEvaluate.h"
#include "Error.h"
#include "CException.h"



void setUp(void){}
void tearDown(void){}

/*********************************************************************************************************************************
 Test on function evaluate
 Input parameter : 
					1)char *expression

 Using following real function : 
								1)getToken()
								2)stackPop()  
								3)stackPush()
								4)createNumberToken()
								5)operatorEvaluate(Stack *numberStack , Operator *opeToken);
								6)evaluateAllOperatorOnStack(Stack *numberStack,Stack *operatorStack);
								7)tryEvaluateOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack);
								8)calculate(Operator *opeToken, Number *first , Number *second);

								
Mock function left stringCreate 


********************************************************************************************************************************/	

void test_should_return_3_for_1_plus_2(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "1+2", .startIndex = 0, .length=3};
	
	stringCreate_ExpectAndReturn("1+2",&tokenizer);
	
	check=evaluate("1+2");
	TEST_ASSERT_EQUAL(3,check);
	printf("Answer : %d ",check);
}

void test_should_return_6_for_60_divide_10(void){
	
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "60/10", .startIndex = 0, .length=3};
	
	stringCreate_ExpectAndReturn("60/10",&tokenizer);
	
	check=evaluate("60/10");
	TEST_ASSERT_EQUAL(6,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4(void){	
	
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};
	
	
	//Evaluate the expression
	
	stringCreate_ExpectAndReturn("2*3+4",&tokenizer);
	
	
	check=evaluate("2*3+4");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d ",check);

}

void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2+3*4+5*6",&tokenizer);
	
	check=evaluate("2+3*4+5*6");
	TEST_ASSERT_EQUAL(44,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2*3+4*5+6",&tokenizer);
	
	check=evaluate("2*3+4*5+6");
	TEST_ASSERT_EQUAL(32,check);
	printf("Answer : %d ",check);
}

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){
	
	int check;
	String tokenizer = {.rawString = "2|3+4*5-6-10", .startIndex = 0, .length = 11};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2|3+4*5-6-10",&tokenizer);
	
	//Token number 2
	check=evaluate("2|3+4*5-6-10");
	TEST_ASSERT_EQUAL(7,check);
	printf("Answer : %d ",check);
}

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10_OR_10_AND_53_XOR_21(void){
	
	int check;
	String tokenizer = {.rawString = "2|3+4*5-6-10|10&53^21", .startIndex = 0, .length = 17};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2|3+4*5-6-10|10&53^21",&tokenizer);
	
	//Token number 2
	check=evaluate("2|3+4*5-6-10|10&53^21");
	TEST_ASSERT_EQUAL(16,check);
	printf("Answer : %d ",check);
}

void test_evaluate_with_different_expression(void){
	int check;
	String tokenizer = {.rawString = "2|3+4*5-6-10|10&53^21+95%6^200%5*80", .startIndex = 0, .length = 27};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2|3+4*5-6-10|10&53^21+95%6^200%5*80",&tokenizer);
	
	//Token number 2
	check=evaluate("2|3+4*5-6-10|10&53^21+95%6^200%5*80");
	TEST_ASSERT_EQUAL(31,check);
	printf("Answer : %d ",check);
}

void test_evaluate_with_longer_expression(void){
	int check;
	String tokenizer = {.rawString = "2|3&4^5|6^10|10&53^21&95|6^200&5|80", .startIndex = 0, .length = 27};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2|3&4^5|6^10|10&53^21&95|6^200&5|80",&tokenizer);
	
	//Token number 2
	check=evaluate("2|3&4^5|6^10|10&53^21&95|6^200&5|80");
	TEST_ASSERT_EQUAL(84,check);
	printf("Answer : %d ",check);
}

void test_should_evaluate_left_parenthesis_2_right_parenthesis(void){
	
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(2)", .startIndex = 0, .length = 3};
	
	stringCreate_ExpectAndReturn("(2)",&tokenizer);
	
	
	check=evaluate("(2)");
	TEST_ASSERT_EQUAL(2,check);
	printf("Answer : %d ",check);
	
}	
	
void test_should_evaluate_left_parenthesis_22_right_parenthesis(void){
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(22)", .startIndex = 0, .length = 3};
	
	stringCreate_ExpectAndReturn("(22)",&tokenizer);
	
	check=evaluate("(22)");
	TEST_ASSERT_EQUAL(22,check);
	printf("Answer : %d ",check);
	
}

void test_should_evaluate_left__left_parenthesis_22_right_right_parenthesis(void){
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "((22))", .startIndex = 0, .length = 5};
	
	stringCreate_ExpectAndReturn("((22))",&tokenizer);
	
	check=evaluate("((22))");
	TEST_ASSERT_EQUAL(22,check);
	printf("Answer : %d ",check);
	
}	
	
void test_should_evaluate_left_left_left_parenthesis_16_right_right_right_parenthesis(void){
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(((16)))", .startIndex = 0, .length = 6};
	
	stringCreate_ExpectAndReturn("(((16)))",&tokenizer);
	
	check=evaluate("(((16)))");
	TEST_ASSERT_EQUAL(16,check);
	printf("Answer : %d ",check);
	
}	


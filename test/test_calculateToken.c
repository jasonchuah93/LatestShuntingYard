#include "unity.h"
#include <malloc.h>
#include "Evaluate.h"
#include "StringObject.h"
#include "stackForEvaluate.h"
#include "calculateToken.h"
#include "mock_operatorEvaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_Stack.h"
#include "mock_tryEvaluatethenPush.h"
#include "createNumberToken.h"


void setUp(void){}
void tearDown(void){}

//Token *calculate(Operator *opeToken, Number *first, Number *second)

void test_should_calculate_2_PLUS_3(void)
{
	int check;
	Operator plus={.type=OPERATOR,.id=ADD};
	Number two={.type=NUMBER,.value=2};
	Number three={.type=NUMBER,.value=3};
	
	check=calculate(&plus,&two,&three);
	
	TEST_ASSERT_EQUAL(5,check);
}

void test_should_calculate_10_MINUS_3(void)
{
	int check;
	Operator subtract={.type=OPERATOR,.id=SUBTRACT};
	Number ten={.type=NUMBER,.value=10};
	Number three={.type=NUMBER,.value=3};
	
	check=calculate(&subtract,&ten,&three);
	
	TEST_ASSERT_EQUAL(7,check);
}

void test_should_calculate_10_MULTIPLY_10(void)
{
	int check;
	Operator multiply={.type=OPERATOR,.id=MULTIPLY};
	Number ten={.type=NUMBER,.value=10};
	Number ten1={.type=NUMBER,.value=10};
	
	check=calculate(&multiply,&ten,&ten1);
	
	TEST_ASSERT_EQUAL(100,check);
}

void test_should_calculate_1000_DIVIDE_10(void)
{
	int check;
	Operator divide={.type=OPERATOR,.id=DIVIDE};
	Number thousand={.type=NUMBER,.value=1000};
	Number ten={.type=NUMBER,.value=10};
	
	check=calculate(&divide,&thousand,&ten);
	
	TEST_ASSERT_EQUAL(100,check);
}

void test_should_calculate_56_BITWISE_AND_30(void)
{
	int check;
	Operator bitwiseAnd ={.type=OPERATOR,.id=BITWISE_AND};
	Number fiftySix ={.type=NUMBER,.value=56};
	Number thirty ={.type=NUMBER,.value=30};
	
	check=calculate(&bitwiseAnd,&fiftySix,&thirty);
	
	TEST_ASSERT_EQUAL(24,check);
}

void test_should_calculate_90_BITWISE_OR_20(void)
{
	int check;
	Operator bitwiseOR ={.type=OPERATOR,.id=BITWISE_OR};
	Number ninety ={.type=NUMBER,.value=90};
	Number twenty ={.type=NUMBER,.value=20};
	
	check=calculate(&bitwiseOR,&ninety,&twenty);
	
	TEST_ASSERT_EQUAL(94,check);
}

void test_should_calculate_99_BITWISE_XOR_66(void)
{
	int check;
	Operator bitwiseXOR ={.type=OPERATOR,.id=BITWISE_XOR};
	Number ninetyNine ={.type=NUMBER,.value=99};
	Number sistySix ={.type=NUMBER,.value=66};
	
	check=calculate(&bitwiseXOR,&ninetyNine,&sistySix);
	
	TEST_ASSERT_EQUAL(33,check);
}

void test_should_calculate_55_MODULUS_3(void)
{
	int check;
	Operator modulus ={.type=OPERATOR,.id=MODULUS};
	Number fiftyFive ={.type=NUMBER,.value=55};
	Number three ={.type=NUMBER,.value=3};
	
	check=calculate(&modulus,&fiftyFive,&three);
	
	TEST_ASSERT_EQUAL(1,check);
}

void test_should_calculate_68_MODULUS_7(void)
{
	int check;
	Operator modulus ={.type=OPERATOR,.id=MODULUS};
	Number sixtyEight ={.type=NUMBER,.value=68};
	Number seven ={.type=NUMBER,.value=7};
	
	check=calculate(&modulus,&sixtyEight,&seven);
	
	TEST_ASSERT_EQUAL(5,check);
}

void test_should_complement_78(void){
	int check;
	Operator complement ={.type=OPERATOR,.id=COMPLEMENT};
	Number seventyEight ={.type=NUMBER,.value=78};
	
	check=calculate(&complement,&seventyEight,NULL);
	
	TEST_ASSERT_EQUAL(-79,check);
}

void test_should_complement_2(void){
	int check;
	Operator complement ={.type=OPERATOR,.id=COMPLEMENT};
	Number two ={.type=NUMBER,.value=2};
	
	check=calculate(&complement,&two,NULL);
	
	TEST_ASSERT_EQUAL(-3,check);
}

void test_should_PLUS_PLUS_3(void){
	int check;
	Operator increment ={.type=OPERATOR,.id=INCREMENT};
	Number three ={.type=NUMBER,.value=3};
	
	check=calculate(&increment,&three,NULL);
	
	TEST_ASSERT_EQUAL(4,check);
}

void test_should_PLUS_PLUS_100(void){
	int check;
	Operator increment ={.type=OPERATOR,.id=INCREMENT};
	Number hundred ={.type=NUMBER,.value=100};
	
	check=calculate(&increment,&hundred,NULL);
	
	TEST_ASSERT_EQUAL(101,check);
}

void test_should_MINUS_MINUS_10(void){
	int check;
	Operator decrement ={.type=OPERATOR,.id=DECREMENT};
	Number ten ={.type=NUMBER,.value=10};
	
	check=calculate(&decrement,&ten,NULL);
	
	TEST_ASSERT_EQUAL(9,check);
}





#include "unity.h"
#include <malloc.h>
#include "Evaluate.h"
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

void test_should_calculate_2_PLUS_3()
{
	int check;
	Operator plus={.type=OPERATOR,.id=ADD};
	Number two={.type=NUMBER,.value=2};
	Number three={.type=NUMBER,.value=3};
	
	check=calculate(&plus,&two,&three);
	
	TEST_ASSERT_EQUAL(5,check);
	
}

void test_should_calculate_10_MINUS_3()
{
	int check;
	Operator subtract={.type=OPERATOR,.id=SUBTRACT};
	Number ten={.type=NUMBER,.value=10};
	Number three={.type=NUMBER,.value=3};
	
	check=calculate(&subtract,&ten,&three);
	
	TEST_ASSERT_EQUAL(7,check);
	
}


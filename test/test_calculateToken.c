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

void test_should_calculate_2_MULTIPLY_3()
{
	int check;
	Number *two = malloc (sizeof(Number));
	two->value=2;
	
	printf("token : %d ",);
	//calculate(multiply,two,three);
}

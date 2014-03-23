#include "unity.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_calculateToken.h"
#include "mock_Stack.h"
#include "Evaluate.h"






void setUp(void){}

void tearDown(void){}



void test_operator_evaluate_should_calculate_2_PLUS_3(void){



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Number answer = {.type=NUMBER, .value=5};

 Token *ansToken = (Token*)&answer;



 stackPop_CMockExpectAndReturn(30, &opeStack, token2);

 stackPop_CMockExpectAndReturn(31, &numStack, token1);

 stackPop_CMockExpectAndReturn(32, &numStack, token3);

 calculate_CMockExpectAndReturn(33, &plus, &number2, &number3, ansToken);

 stackPush_CMockExpect(34, ansToken, &numStack);



 operatorEvaluate(&numStack,&opeStack);

}



void test_operator_evaluate_should_calculate_2_PLUS_3_MULTIPLY_4(void){



 Number number12 = {.type= NUMBER, .value=12};

 Token *token1 = (Token*)&number12;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token3 = (Token*)&number2;



 Number answer = {.type=NUMBER, .value=14};

 Token *ansToken = (Token*)&answer;



 stackPop_CMockExpectAndReturn(53, &opeStack, token2);

 stackPop_CMockExpectAndReturn(54, &numStack, token1);

 stackPop_CMockExpectAndReturn(55, &numStack, token3);

 calculate_CMockExpectAndReturn(56, &plus, &number12, &number2, ansToken);

 stackPush_CMockExpect(57, ansToken, &numStack);



 operatorEvaluate(&numStack,&opeStack);

}

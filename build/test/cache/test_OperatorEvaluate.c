#include "unity.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_createNumberToken.h"
#include "mock_calculateToken.h"
#include "mock_StringObject.h"
#include "mock_Stack.h"
#include "Evaluate.h"


void setUp(void){}

void tearDown(void){}





void test_operator_evaluate_should_evaluate_2_PLUS_3(void){



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;





 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 int answer;

 Token *answerToken;



 stackPop_CMockExpectAndReturn(32, &opeStack, token2);

 stackPop_CMockExpectAndReturn(33, &numStack, token1);

 stackPop_CMockExpectAndReturn(34, &numStack, token3);

 calculate_CMockExpectAndReturn(35, &plus, &number2, &number3, answer);

 createNumberToken_CMockExpectAndReturn(36, answer, answerToken);

 stackPush_CMockExpect(37, answerToken, &numStack);

 operatorEvaluate(&numStack,&opeStack);

}



void test_operator_evaluate_should_evaluate_2_PLUS_3_MULTIPLY_4(void){



 Number number12 = {.type= NUMBER, .value=12};

 Token *token1 = (Token*)&number12;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token3 = (Token*)&number2;



 int answer;

 Token *answerToken;



 stackPop_CMockExpectAndReturn(55, &opeStack, token2);

 stackPop_CMockExpectAndReturn(56, &numStack, token1);

 stackPop_CMockExpectAndReturn(57, &numStack, token3);

 calculate_CMockExpectAndReturn(58, &plus, &number12, &number2, answer);

 createNumberToken_CMockExpectAndReturn(59, answer, answerToken);

 stackPush_CMockExpect(60, answerToken, &numStack);

 operatorEvaluate(&numStack,&opeStack);

}



void test_NEGATIVE_LEFT_PARENTHESIS_NEGATIVE_2_RIGHT_PARENTHESIS(void){

 Tokenizer tokenizer = {.rawString = "-(-2)", .startIndex = 0, .length = 5 };



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



 int answer;

 Token *answerToken;





}

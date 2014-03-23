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

void test_evaluate_2_PLUS_3(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;





 Number answer = {.type=NUMBER, .value=5};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(48, "2+3", &tokenizer);



 getToken_CMockExpectAndReturn(50, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(51, token1, 1);

 stackPush_CMockExpect(52, token1, &numStack);



 getToken_CMockExpectAndReturn(54, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(55, token2, 0);

 isOperator_CMockExpectAndReturn(56, token2, 1);

 tryEvaluatethenPush_CMockExpect(57, token2, &numStack, &opeStack);

 stackPush_CMockExpect(58, token2, &opeStack);



 getToken_CMockExpectAndReturn(60, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(61, token3, 1);

 stackPush_CMockExpect(62, token3, &numStack);

 getToken_CMockExpectAndReturn(63, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(66, &opeStack, token2);

 stackPop_CMockExpectAndReturn(67, &numStack, token1);

 stackPop_CMockExpectAndReturn(68, &numStack, token3);

 calculate_CMockExpectAndReturn(69, &plus, &number2, &number3, ansToken);

 stackPush_CMockExpect(70, ansToken, &numStack);



 evaluate("2+3");

}

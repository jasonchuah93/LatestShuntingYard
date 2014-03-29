#include "unity.h"
#include "stackForEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_calculateToken.h"
#include "mock_Stack.h"
#include "Evaluate.h"


void setUp(void){}

void tearDown(void){}



void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 Tokenizer tokenizer = {.rawString = "0", .startIndex = 0, .length = 1};



 Number number2 = {.type= NUMBER, .value=0};

 Token *token1 = (Token*)&number2;



 initTokenizer_CMockExpectAndReturn(21, ((void *)0), &tokenizer);



 check=evaluate(((void *)0));

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

}





void test_evaluate_2_PLUS_3(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;







 initTokenizer_CMockExpectAndReturn(44, "2+3", &tokenizer);



 getToken_CMockExpectAndReturn(46, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(47, token1, 1);

 stackPush_CMockExpect(48, token1, &numStack);



 getToken_CMockExpectAndReturn(50, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(51, token2, 0);

 isOperator_CMockExpectAndReturn(52, token2, 1);

 tryEvaluatethenPush_CMockExpect(53, token2, &numStack, &opeStack);





 getToken_CMockExpectAndReturn(56, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(57, token3, 1);

 stackPush_CMockExpect(58, token3, &numStack);

 getToken_CMockExpectAndReturn(59, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(61, &numStack, &opeStack);

 evaluate("2+3");

}

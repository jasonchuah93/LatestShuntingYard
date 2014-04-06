#include "unity.h"
#include "tryEvaluatethenPush.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "mock_getToken.h"
#include "mock_createNumberToken.h"
#include "mock_StringObject.h"
#include "mock_Stack.h"
#include "calculateToken.h"
#include "LinkedList.h"
#include "Evaluate.h"
#include "Error.h"


void setUp(void){}

void tearDown(void){}

void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 Stack numberStack;

 Stack operatorStack;

 ErrorCode exception;

 String tokenizer = {.rawString = "0", .startIndex = 0, .length=1};



 Number number2 = {.type= NUMBER, .value=0};

 Token *token1 = (Token*)&number2;



 createStack_CMockExpectAndReturn(44, &numberStack);

 createStack_CMockExpectAndReturn(45, &operatorStack);

 stringCreate_CMockExpectAndReturn(46, ((void *)0), &tokenizer);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  check = evaluate(((void *)0));

  UnityFail( ("Should throw Error no expression "), (_U_UINT)51);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_EXPRESSION)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_should_return_3_for_1_plus_2(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 String tokenizer = {.rawString = "1+2", .startIndex = 0, .length=3};



 Number number1 = {.type= NUMBER, .value=1};

 Token *token1 = (Token*)&number1;



 Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};

 Token *token2 = (Token*)&plus;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token3 = (Token*)&number2;



 Number answer = {.type= NUMBER, .value=3};

 Token *answerToken = (Token*)&answer;

 createStack_CMockExpectAndReturn(77, &dataStack);

 createStack_CMockExpectAndReturn(78, &operatorStack);

 stringCreate_CMockExpectAndReturn(79, "1+2", &tokenizer);



 getToken_CMockExpectAndReturn(81, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(82, token1, 1);

 stackPush_CMockExpect(83, token1, &dataStack);





 getToken_CMockExpectAndReturn(86, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(87, token2, 0);

 isOperator_CMockExpectAndReturn(88, token2, 1);

 stackPop_CMockExpectAndReturn(89, &operatorStack, ((void *)0));

 stackPush_CMockExpect(90, token2, &operatorStack);





 getToken_CMockExpectAndReturn(93, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(94, token3, 1);

 stackPush_CMockExpect(95, token3, &dataStack);

 getToken_CMockExpectAndReturn(96, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(99, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(100, &dataStack, token3);

 stackPop_CMockExpectAndReturn(101, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(102, 3, answerToken);

 stackPush_CMockExpect(103, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(104, &operatorStack, ((void *)0));



 stackPop_CMockExpectAndReturn(106, &dataStack, answerToken);



 check=evaluate("1+2");

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_should_return_6_for_60_divide_10(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 String tokenizer = {.rawString = "60/10", .startIndex = 0, .length=3};



 Number number60 = {.type= NUMBER, .value=60};

 Token *token1 = (Token*)&number60;



 Operator divide = {.type= OPERATOR, .id=DIVIDE, .precedence=100};

 Token *token2 = (Token*)&divide;



 Number number10 = {.type= NUMBER, .value=10};

 Token *token3 = (Token*)&number10;



 Number answer = {.type= NUMBER, .value=6};

 Token *answerToken = (Token*)&answer;



 createStack_CMockExpectAndReturn(132, &dataStack);

 createStack_CMockExpectAndReturn(133, &operatorStack);

 stringCreate_CMockExpectAndReturn(134, "60/10", &tokenizer);



 getToken_CMockExpectAndReturn(136, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(137, token1, 1);

 stackPush_CMockExpect(138, token1, &dataStack);





 getToken_CMockExpectAndReturn(141, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(142, token2, 0);

 isOperator_CMockExpectAndReturn(143, token2, 1);

 stackPop_CMockExpectAndReturn(144, &operatorStack, ((void *)0));

 stackPush_CMockExpect(145, token2, &operatorStack);





 getToken_CMockExpectAndReturn(148, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(149, token3, 1);

 stackPush_CMockExpect(150, token3, &dataStack);

 getToken_CMockExpectAndReturn(151, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(154, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(155, &dataStack, token3);

 stackPop_CMockExpectAndReturn(156, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(157, 6, answerToken);

 stackPush_CMockExpect(158, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(159, &operatorStack, ((void *)0));



 stackPop_CMockExpectAndReturn(161, &dataStack, answerToken);



 check=evaluate("60/10");

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}

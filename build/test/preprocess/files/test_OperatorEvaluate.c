#include "unity.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
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

 void test_operatorEvaluate_should_throw_error_when_encounter_invalid_operator(void){



 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 ErrorCode exception;





 String tokenizer = {.rawString = "1$2", .startIndex = 0, .length=3};

 Number number1 = {.type= NUMBER, .value=1};

 Operator currentProgramCounter = {.type= OPERATOR, .id=CURRENT_PROGRAM_COUNTER , .precedence =0};

 Number number2 = {.type= NUMBER, .value=2};



 stackPop_CMockExpectAndReturn(40, &numberStack, &number1);

 stackPop_CMockExpectAndReturn(41, &numberStack, &number2);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

   operatorEvaluate(&numberStack,&currentProgramCounter);

  UnityFail( ("Invalid Operator should throw Error Not Operator"), (_U_UINT)45);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_operatorEvaluate_3_PLUS_7(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "3+7", .startIndex = 0, .length=3};

 Number number3 = {.type= NUMBER, .value=3};

 Operator plus = {.type= OPERATOR, .id=ADD , .precedence=70};

 Number number7 = {.type= NUMBER, .value=7};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(66, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(67, &numberStack, &number3);

 createNumberToken_CMockExpectAndReturn(68, 10, answerToken);

 stackPush_CMockExpect(69, &answer, &numberStack);



 operatorEvaluate(&numberStack,&plus);

}



void test_operatorEvaluate_100_MINUS_37(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "100-37", .startIndex = 0, .length=3};

 Number number100 = {.type= NUMBER, .value=100};

 Operator minus = {.type= OPERATOR, .id=SUBTRACT , .precedence=70};

 Number number37 = {.type= NUMBER, .value=37};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(88, &numberStack, &number37);

 stackPop_CMockExpectAndReturn(89, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(90, 63, answerToken);

 stackPush_CMockExpect(91, &answer, &numberStack);



 operatorEvaluate(&numberStack,&minus);

}



void test_operatorEvaluate_100_MULTIPLY_50(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "100*50", .startIndex = 0, .length=3};

 Number number100 = {.type= NUMBER, .value=100};

 Operator multiply = {.type= OPERATOR, .id=MULTIPLY , .precedence=100};

 Number number50 = {.type= NUMBER, .value=50};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(110, &numberStack, &number50);

 stackPop_CMockExpectAndReturn(111, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(112, 5000, answerToken);

 stackPush_CMockExpect(113, &answer, &numberStack);



 operatorEvaluate(&numberStack,&multiply);

}



void test_operatorEvaluate_99_DIVIDE_3(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "99/3", .startIndex = 0, .length=3};

 Number number99 = {.type= NUMBER, .value=99};

 Operator divide = {.type= OPERATOR, .id=DIVIDE , .precedence=100};

 Number number3 = {.type= NUMBER, .value=3};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(132, &numberStack, &number3);

 stackPop_CMockExpectAndReturn(133, &numberStack, &number99);

 createNumberToken_CMockExpectAndReturn(134, 33, answerToken);

 stackPush_CMockExpect(135, &answer, &numberStack);



 operatorEvaluate(&numberStack,&divide);

}



void test_operatorEvaluate_60_MODULUS_7(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "60%7", .startIndex = 0, .length=3};

 Number number60 = {.type= NUMBER, .value=60};

 Operator modulus = {.type= OPERATOR, .id=MODULUS , .precedence=100};

 Number number7 = {.type= NUMBER, .value=7};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(154, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(155, &numberStack, &number60);

 createNumberToken_CMockExpectAndReturn(156, 4, answerToken);

 stackPush_CMockExpect(157, &answer, &numberStack);



 operatorEvaluate(&numberStack,&modulus);

}



void test_operatorEvaluate_45_BITWISEAND_54(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "45&54", .startIndex = 0, .length=3};

 Number number45 = {.type= NUMBER, .value=45};

 Operator bitwiseAND = {.type= OPERATOR, .id=BITWISE_AND , .precedence=20};

 Number number54 = {.type= NUMBER, .value=54};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(176, &numberStack, &number54);

 stackPop_CMockExpectAndReturn(177, &numberStack, &number45);

 createNumberToken_CMockExpectAndReturn(178, 36, answerToken);

 stackPush_CMockExpect(179, &answer, &numberStack);



 operatorEvaluate(&numberStack,&bitwiseAND);

}



void test_operatorEvaluate_56_BITWISEOR_30(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "56|30", .startIndex = 0, .length=3};

 Number number56 = {.type= NUMBER, .value=56};

 Operator bitwiseOR = {.type= OPERATOR, .id=BITWISE_OR , .precedence=10};

 Number number30 = {.type= NUMBER, .value=30};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(198, &numberStack, &number30);

 stackPop_CMockExpectAndReturn(199, &numberStack, &number56);

 createNumberToken_CMockExpectAndReturn(200, 62, answerToken);

 stackPush_CMockExpect(201, &answer, &numberStack);



 operatorEvaluate(&numberStack,&bitwiseOR);

}



void test_operatorEvaluate_56_BITWISEXOR_30(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "56^30", .startIndex = 0, .length=3};

 Number number56 = {.type= NUMBER, .value=56};

 Operator bitwiseXOR = {.type= OPERATOR, .id=BITWISE_XOR , .precedence=10};

 Number number30 = {.type= NUMBER, .value=30};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(220, &numberStack, &number30);

 stackPop_CMockExpectAndReturn(221, &numberStack, &number56);

 createNumberToken_CMockExpectAndReturn(222, 38, answerToken);

 stackPush_CMockExpect(223, &answer, &numberStack);



 operatorEvaluate(&numberStack,&bitwiseXOR);

}

 void test_evaluateAllOperatorOnStack_2_plus_3_plus_4(void){

 Stack numStack;

 Stack operatorStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "2+3+4", .startIndex = 0 ,.length=5};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator add = {.type= OPERATOR, .id=ADD ,.precedence=70};

 Token *token4 = (Token*)&add;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Number tempAnswer = {.type= NUMBER, .value=5};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number finalAnswer;

 Token *finalAnsToken = (Token*)&finalAnswer;





 stackPop_CMockExpectAndReturn(270, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(271, &numStack, token3);

 stackPop_CMockExpectAndReturn(272, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(273, 5, tempAnsToken);

 stackPush_CMockExpect(274, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(277, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(278, &numStack, token5);

 stackPop_CMockExpectAndReturn(279, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(280, 9, finalAnsToken);

 stackPush_CMockExpect(281, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(282, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_10_plus_3_multiply_9(void){

 Stack numStack;

 Stack operatorStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "10+3*9", .startIndex = 0, .length=5};



 Number number10 = {.type= NUMBER, .value=10};

 Token *token1 = (Token*)&number10;



 Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator multiply = {.type= OPERATOR, .id=MULTIPLY ,.precedence=100};

 Token *token4 = (Token*)&multiply;



 Number number9 = {.type= NUMBER, .value=9};

 Token *token5 = (Token*)&number9;



 Number tempAnswer = {.type= NUMBER, .value=13};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number finalAnswer;

 Token *finalAnsToken = (Token*)&finalAnswer;





 stackPop_CMockExpectAndReturn(318, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(319, &numStack, token3);

 stackPop_CMockExpectAndReturn(320, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(321, 13, tempAnsToken);

 stackPush_CMockExpect(322, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(325, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(326, &numStack, token5);

 stackPop_CMockExpectAndReturn(327, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(328, 117, finalAnsToken);

 stackPush_CMockExpect(329, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(330, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_100_divide_5_plus_60(void){

 Stack numStack;

 Stack operatorStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "100/5+60", .startIndex = 0, .length=5};



 Number number100 = {.type= NUMBER, .value=100};

 Token *token1 = (Token*)&number100;



 Operator divide = {.type= OPERATOR, .id=DIVIDE ,.precedence=100};

 Token *token2 = (Token*)&divide;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token3 = (Token*)&number5;



 Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};

 Token *token4 = (Token*)&plus;



 Number number60 = {.type= NUMBER, .value=60};

 Token *token5 = (Token*)&number60;



 Number tempAnswer = {.type= NUMBER, .value=20};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number finalAnswer;

 Token *finalAnsToken = (Token*)&finalAnswer;





 stackPop_CMockExpectAndReturn(366, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(367, &numStack, token3);

 stackPop_CMockExpectAndReturn(368, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(369, 20, tempAnsToken);

 stackPush_CMockExpect(370, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(373, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(374, &numStack, token5);

 stackPop_CMockExpectAndReturn(375, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(376, 80, finalAnsToken);

 stackPush_CMockExpect(377, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(378, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_99_XOR_66_divide_11_plus_10(void){

 Stack numStack;

 Stack operatorStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "99^66/11", .startIndex = 0, .length=7};



 Number number99 = {.type= NUMBER, .value=99};

 Token *token1 = (Token*)&number99;



 Operator bitwiseXOR = {.type= OPERATOR, .id=BITWISE_XOR ,.precedence=50};

 Token *token2 = (Token*)&bitwiseXOR;



 Number number66 = {.type= NUMBER, .value=66};

 Token *token3 = (Token*)&number66;



 Operator divide = {.type= OPERATOR, .id=DIVIDE ,.precedence=100};

 Token *token4 = (Token*)&divide;



 Number number11 = {.type= NUMBER, .value=11};

 Token *token5 = (Token*)&number11;



 Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};

 Token *token6 = (Token*)&plus;



 Number number10 = {.type= NUMBER, .value=10};

 Token *token7 = (Token*)&number10;





 Number tempAnswer = {.type= NUMBER, .value=33};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number tempAnswer2 = {.type= NUMBER, .value=3};

 Token *tempAnsToken2 = (Token*)&tempAnswer2;



 Number finalAnswer;

 Token *finalAnsToken = (Token*)&finalAnswer;





 stackPop_CMockExpectAndReturn(424, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(425, &numStack, token3);

 stackPop_CMockExpectAndReturn(426, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(427, 33, tempAnsToken);

 stackPush_CMockExpect(428, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(431, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(432, &numStack, token5);

 stackPop_CMockExpectAndReturn(433, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(434, 3, tempAnsToken2);

 stackPush_CMockExpect(435, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(438, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(439, &numStack, token7);

 stackPop_CMockExpectAndReturn(440, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(441, 13, finalAnsToken);

 stackPush_CMockExpect(442, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(443, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}

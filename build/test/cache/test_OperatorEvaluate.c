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



 stackPop_CMockExpectAndReturn(67, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(68, &numberStack, &number3);

 createNumberToken_CMockExpectAndReturn(69, 10, answerToken);

 stackPush_CMockExpect(70, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(90, &numberStack, &number37);

 stackPop_CMockExpectAndReturn(91, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(92, 63, answerToken);

 stackPush_CMockExpect(93, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(112, &numberStack, &number50);

 stackPop_CMockExpectAndReturn(113, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(114, 5000, answerToken);

 stackPush_CMockExpect(115, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(134, &numberStack, &number3);

 stackPop_CMockExpectAndReturn(135, &numberStack, &number99);

 createNumberToken_CMockExpectAndReturn(136, 33, answerToken);

 stackPush_CMockExpect(137, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(156, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(157, &numberStack, &number60);

 createNumberToken_CMockExpectAndReturn(158, 4, answerToken);

 stackPush_CMockExpect(159, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(178, &numberStack, &number54);

 stackPop_CMockExpectAndReturn(179, &numberStack, &number45);

 createNumberToken_CMockExpectAndReturn(180, 36, answerToken);

 stackPush_CMockExpect(181, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(200, &numberStack, &number30);

 stackPop_CMockExpectAndReturn(201, &numberStack, &number56);

 createNumberToken_CMockExpectAndReturn(202, 62, answerToken);

 stackPush_CMockExpect(203, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(222, &numberStack, &number30);

 stackPop_CMockExpectAndReturn(223, &numberStack, &number56);

 createNumberToken_CMockExpectAndReturn(224, 38, answerToken);

 stackPush_CMockExpect(225, &answer, &numberStack);



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





 stackPop_CMockExpectAndReturn(273, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(274, &numStack, token3);

 stackPop_CMockExpectAndReturn(275, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(276, 5, tempAnsToken);

 stackPush_CMockExpect(277, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(280, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(281, &numStack, token5);

 stackPop_CMockExpectAndReturn(282, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(283, 9, finalAnsToken);

 stackPush_CMockExpect(284, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(285, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(321, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(322, &numStack, token3);

 stackPop_CMockExpectAndReturn(323, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(324, 13, tempAnsToken);

 stackPush_CMockExpect(325, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(328, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(329, &numStack, token5);

 stackPop_CMockExpectAndReturn(330, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(331, 117, finalAnsToken);

 stackPush_CMockExpect(332, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(333, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(369, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(370, &numStack, token3);

 stackPop_CMockExpectAndReturn(371, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(372, 20, tempAnsToken);

 stackPush_CMockExpect(373, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(376, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(377, &numStack, token5);

 stackPop_CMockExpectAndReturn(378, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(379, 80, finalAnsToken);

 stackPush_CMockExpect(380, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(381, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_99_XOR_66_divide_11_plus_10(void){

 Stack numStack;

 Stack operatorStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "99^66/11+10", .startIndex = 0, .length=7};



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





 stackPop_CMockExpectAndReturn(427, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(428, &numStack, token3);

 stackPop_CMockExpectAndReturn(429, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(430, 33, tempAnsToken);

 stackPush_CMockExpect(431, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(434, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(435, &numStack, token5);

 stackPop_CMockExpectAndReturn(436, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(437, 3, tempAnsToken2);

 stackPush_CMockExpect(438, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(441, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(442, &numStack, token7);

 stackPop_CMockExpectAndReturn(443, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(444, 13, finalAnsToken);

 stackPush_CMockExpect(445, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(446, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20(void){

 Stack numStack;

 Stack operatorStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "100/5*6+99-20", .startIndex = 0, .length=9};



 Number number100 = {.type= NUMBER, .value=100};

 Token *token1 = (Token*)&number100;



 Operator divide= {.type= OPERATOR, .id=DIVIDE ,.precedence=100};

 Token *token2 = (Token*)&divide;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token3 = (Token*)&number5;



 Operator multiply = {.type= OPERATOR, .id=MULTIPLY ,.precedence=100};

 Token *token4 = (Token*)&multiply;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token5 = (Token*)&number6;



 Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};

 Token *token6 = (Token*)&plus;



 Number number99 = {.type= NUMBER, .value=99};

 Token *token7 = (Token*)&number99;



 Operator minus = {.type= OPERATOR, .id=SUBTRACT ,.precedence=70};

 Token *token8 = (Token*)&minus;



 Number number20 = {.type= NUMBER, .value=20};

 Token *token9 = (Token*)&number20;





 Number tempAnswer = {.type= NUMBER, .value=20};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number tempAnswer2 = {.type= NUMBER, .value=120};

 Token *tempAnsToken2 = (Token*)&tempAnswer2;



 Number tempAnswer3 = {.type= NUMBER, .value=219};

 Token *tempAnsToken3 = (Token*)&tempAnswer3;



 Number finalAnswer;

 Token *finalAnsToken = (Token*)&finalAnswer;





 stackPop_CMockExpectAndReturn(501, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(502, &numStack, token3);

 stackPop_CMockExpectAndReturn(503, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(504, 20, tempAnsToken);

 stackPush_CMockExpect(505, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(508, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(509, &numStack, token5);

 stackPop_CMockExpectAndReturn(510, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(511, 120, tempAnsToken2);

 stackPush_CMockExpect(512, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(515, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(516, &numStack, token7);

 stackPop_CMockExpectAndReturn(517, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(518, 219, tempAnsToken3);

 stackPush_CMockExpect(519, tempAnsToken3, &numStack);





 stackPop_CMockExpectAndReturn(522, &operatorStack, token8);

 stackPop_CMockExpectAndReturn(523, &numStack, token9);

 stackPop_CMockExpectAndReturn(524, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(525, 199, finalAnsToken);

 stackPush_CMockExpect(526, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(527, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20_modulus_30(void){

 Stack numStack;

 Stack operatorStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "100/5*6+99-20%30", .startIndex = 0, .length=11};



 Number number100 = {.type= NUMBER, .value=100};

 Token *token1 = (Token*)&number100;



 Operator divide= {.type= OPERATOR, .id=DIVIDE ,.precedence=100};

 Token *token2 = (Token*)&divide;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token3 = (Token*)&number5;



 Operator multiply = {.type= OPERATOR, .id=MULTIPLY ,.precedence=100};

 Token *token4 = (Token*)&multiply;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token5 = (Token*)&number6;



 Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};

 Token *token6 = (Token*)&plus;



 Number number99 = {.type= NUMBER, .value=99};

 Token *token7 = (Token*)&number99;



 Operator minus = {.type= OPERATOR, .id=SUBTRACT ,.precedence=70};

 Token *token8 = (Token*)&minus;



 Number number20 = {.type= NUMBER, .value=20};

 Token *token9 = (Token*)&number20;



 Operator modulus = {.type= OPERATOR, .id=MODULUS ,.precedence=100};

 Token *token10 = (Token*)&modulus;



 Number number30 = {.type= NUMBER, .value=30};

 Token *token11 = (Token*)&number30;





 Number tempAnswer = {.type= NUMBER, .value=20};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number tempAnswer2 = {.type= NUMBER, .value=120};

 Token *tempAnsToken2 = (Token*)&tempAnswer2;



 Number tempAnswer3 = {.type= NUMBER, .value=219};

 Token *tempAnsToken3 = (Token*)&tempAnswer3;



 Number tempAnswer4 = {.type= NUMBER, .value=199};

 Token *tempAnsToken4 = (Token*)&tempAnswer4;



 Number finalAnswer;

 Token *finalAnsToken = (Token*)&finalAnswer;





 stackPop_CMockExpectAndReturn(591, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(592, &numStack, token3);

 stackPop_CMockExpectAndReturn(593, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(594, 20, tempAnsToken);

 stackPush_CMockExpect(595, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(598, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(599, &numStack, token5);

 stackPop_CMockExpectAndReturn(600, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(601, 120, tempAnsToken2);

 stackPush_CMockExpect(602, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(605, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(606, &numStack, token7);

 stackPop_CMockExpectAndReturn(607, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(608, 219, tempAnsToken3);

 stackPush_CMockExpect(609, tempAnsToken3, &numStack);





 stackPop_CMockExpectAndReturn(612, &operatorStack, token8);

 stackPop_CMockExpectAndReturn(613, &numStack, token9);

 stackPop_CMockExpectAndReturn(614, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(615, 199, tempAnsToken4);

 stackPush_CMockExpect(616, tempAnsToken4, &numStack);





 stackPop_CMockExpectAndReturn(619, &operatorStack, token10);

 stackPop_CMockExpectAndReturn(620, &numStack, token11);

 stackPop_CMockExpectAndReturn(621, &numStack, tempAnsToken4);

 createNumberToken_CMockExpectAndReturn(622, 19, finalAnsToken);

 stackPush_CMockExpect(623, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(624, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20_modulus_30_bitwiseAnd_89(void){

 Stack numStack;

 Stack operatorStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "100/5*6+99-20%30&89", .startIndex = 0, .length=13};



 Number number100 = {.type= NUMBER, .value=100};

 Token *token1 = (Token*)&number100;



 Operator divide= {.type= OPERATOR, .id=DIVIDE ,.precedence=100};

 Token *token2 = (Token*)&divide;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token3 = (Token*)&number5;



 Operator multiply = {.type= OPERATOR, .id=MULTIPLY ,.precedence=100};

 Token *token4 = (Token*)&multiply;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token5 = (Token*)&number6;



 Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};

 Token *token6 = (Token*)&plus;



 Number number99 = {.type= NUMBER, .value=99};

 Token *token7 = (Token*)&number99;



 Operator minus = {.type= OPERATOR, .id=SUBTRACT ,.precedence=70};

 Token *token8 = (Token*)&minus;



 Number number20 = {.type= NUMBER, .value=20};

 Token *token9 = (Token*)&number20;



 Operator modulus = {.type= OPERATOR, .id=MODULUS ,.precedence=100};

 Token *token10 = (Token*)&modulus;



 Number number30 = {.type= NUMBER, .value=30};

 Token *token11 = (Token*)&number30;



 Operator bitwiseAnd = {.type= OPERATOR, .id=BITWISE_AND ,.precedence=20};

 Token *token12 = (Token*)&bitwiseAnd;



 Number number89 = {.type= NUMBER, .value=89};

 Token *token13 = (Token*)&number89;





 Number tempAnswer = {.type= NUMBER, .value=20};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number tempAnswer2 = {.type= NUMBER, .value=120};

 Token *tempAnsToken2 = (Token*)&tempAnswer2;



 Number tempAnswer3 = {.type= NUMBER, .value=219};

 Token *tempAnsToken3 = (Token*)&tempAnswer3;



 Number tempAnswer4 = {.type= NUMBER, .value=199};

 Token *tempAnsToken4 = (Token*)&tempAnswer4;



 Number tempAnswer5 = {.type= NUMBER, .value=19};

 Token *tempAnsToken5 = (Token*)&tempAnswer5;



 Number finalAnswer;

 Token *finalAnsToken = (Token*)&finalAnswer;





 stackPop_CMockExpectAndReturn(697, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(698, &numStack, token3);

 stackPop_CMockExpectAndReturn(699, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(700, 20, tempAnsToken);

 stackPush_CMockExpect(701, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(704, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(705, &numStack, token5);

 stackPop_CMockExpectAndReturn(706, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(707, 120, tempAnsToken2);

 stackPush_CMockExpect(708, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(711, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(712, &numStack, token7);

 stackPop_CMockExpectAndReturn(713, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(714, 219, tempAnsToken3);

 stackPush_CMockExpect(715, tempAnsToken3, &numStack);





 stackPop_CMockExpectAndReturn(718, &operatorStack, token8);

 stackPop_CMockExpectAndReturn(719, &numStack, token9);

 stackPop_CMockExpectAndReturn(720, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(721, 199, tempAnsToken4);

 stackPush_CMockExpect(722, tempAnsToken4, &numStack);





 stackPop_CMockExpectAndReturn(725, &operatorStack, token10);

 stackPop_CMockExpectAndReturn(726, &numStack, token11);

 stackPop_CMockExpectAndReturn(727, &numStack, tempAnsToken4);

 createNumberToken_CMockExpectAndReturn(728, 19, tempAnsToken5);

 stackPush_CMockExpect(729, tempAnsToken5, &numStack);





 stackPop_CMockExpectAndReturn(732, &operatorStack, token12);

 stackPop_CMockExpectAndReturn(733, &numStack, token13);

 stackPop_CMockExpectAndReturn(734, &numStack, tempAnsToken5);

 createNumberToken_CMockExpectAndReturn(735, 17, finalAnsToken);

 stackPush_CMockExpect(736, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(737, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}

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



 stackPop_CMockExpectAndReturn(44, &numberStack, &number1);

 stackPop_CMockExpectAndReturn(45, &numberStack, &number2);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

   operatorEvaluate(&numberStack,&currentProgramCounter);

  UnityFail( ("Invalid Operator should throw Error Not Operator"), (_U_UINT)49);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

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



 stackPop_CMockExpectAndReturn(71, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(72, &numberStack, &number3);

 createNumberToken_CMockExpectAndReturn(73, 10, answerToken);

 stackPush_CMockExpect(74, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(94, &numberStack, &number37);

 stackPop_CMockExpectAndReturn(95, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(96, 63, answerToken);

 stackPush_CMockExpect(97, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(116, &numberStack, &number50);

 stackPop_CMockExpectAndReturn(117, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(118, 5000, answerToken);

 stackPush_CMockExpect(119, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(138, &numberStack, &number3);

 stackPop_CMockExpectAndReturn(139, &numberStack, &number99);

 createNumberToken_CMockExpectAndReturn(140, 33, answerToken);

 stackPush_CMockExpect(141, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(160, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(161, &numberStack, &number60);

 createNumberToken_CMockExpectAndReturn(162, 4, answerToken);

 stackPush_CMockExpect(163, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(182, &numberStack, &number54);

 stackPop_CMockExpectAndReturn(183, &numberStack, &number45);

 createNumberToken_CMockExpectAndReturn(184, 36, answerToken);

 stackPush_CMockExpect(185, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(204, &numberStack, &number30);

 stackPop_CMockExpectAndReturn(205, &numberStack, &number56);

 createNumberToken_CMockExpectAndReturn(206, 62, answerToken);

 stackPush_CMockExpect(207, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(226, &numberStack, &number30);

 stackPop_CMockExpectAndReturn(227, &numberStack, &number56);

 createNumberToken_CMockExpectAndReturn(228, 38, answerToken);

 stackPush_CMockExpect(229, &answer, &numberStack);



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





 stackPop_CMockExpectAndReturn(281, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(282, &numStack, token3);

 stackPop_CMockExpectAndReturn(283, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(284, 5, tempAnsToken);

 stackPush_CMockExpect(285, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(288, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(289, &numStack, token5);

 stackPop_CMockExpectAndReturn(290, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(291, 9, finalAnsToken);

 stackPush_CMockExpect(292, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(293, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(329, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(330, &numStack, token3);

 stackPop_CMockExpectAndReturn(331, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(332, 13, tempAnsToken);

 stackPush_CMockExpect(333, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(336, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(337, &numStack, token5);

 stackPop_CMockExpectAndReturn(338, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(339, 117, finalAnsToken);

 stackPush_CMockExpect(340, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(341, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(377, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(378, &numStack, token3);

 stackPop_CMockExpectAndReturn(379, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(380, 20, tempAnsToken);

 stackPush_CMockExpect(381, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(384, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(385, &numStack, token5);

 stackPop_CMockExpectAndReturn(386, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(387, 80, finalAnsToken);

 stackPush_CMockExpect(388, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(389, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(435, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(436, &numStack, token3);

 stackPop_CMockExpectAndReturn(437, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(438, 33, tempAnsToken);

 stackPush_CMockExpect(439, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(442, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(443, &numStack, token5);

 stackPop_CMockExpectAndReturn(444, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(445, 3, tempAnsToken2);

 stackPush_CMockExpect(446, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(449, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(450, &numStack, token7);

 stackPop_CMockExpectAndReturn(451, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(452, 13, finalAnsToken);

 stackPush_CMockExpect(453, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(454, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(509, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(510, &numStack, token3);

 stackPop_CMockExpectAndReturn(511, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(512, 20, tempAnsToken);

 stackPush_CMockExpect(513, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(516, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(517, &numStack, token5);

 stackPop_CMockExpectAndReturn(518, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(519, 120, tempAnsToken2);

 stackPush_CMockExpect(520, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(523, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(524, &numStack, token7);

 stackPop_CMockExpectAndReturn(525, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(526, 219, tempAnsToken3);

 stackPush_CMockExpect(527, tempAnsToken3, &numStack);





 stackPop_CMockExpectAndReturn(530, &operatorStack, token8);

 stackPop_CMockExpectAndReturn(531, &numStack, token9);

 stackPop_CMockExpectAndReturn(532, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(533, 199, finalAnsToken);

 stackPush_CMockExpect(534, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(535, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(599, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(600, &numStack, token3);

 stackPop_CMockExpectAndReturn(601, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(602, 20, tempAnsToken);

 stackPush_CMockExpect(603, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(606, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(607, &numStack, token5);

 stackPop_CMockExpectAndReturn(608, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(609, 120, tempAnsToken2);

 stackPush_CMockExpect(610, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(613, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(614, &numStack, token7);

 stackPop_CMockExpectAndReturn(615, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(616, 219, tempAnsToken3);

 stackPush_CMockExpect(617, tempAnsToken3, &numStack);





 stackPop_CMockExpectAndReturn(620, &operatorStack, token8);

 stackPop_CMockExpectAndReturn(621, &numStack, token9);

 stackPop_CMockExpectAndReturn(622, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(623, 199, tempAnsToken4);

 stackPush_CMockExpect(624, tempAnsToken4, &numStack);





 stackPop_CMockExpectAndReturn(627, &operatorStack, token10);

 stackPop_CMockExpectAndReturn(628, &numStack, token11);

 stackPop_CMockExpectAndReturn(629, &numStack, tempAnsToken4);

 createNumberToken_CMockExpectAndReturn(630, 19, finalAnsToken);

 stackPush_CMockExpect(631, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(632, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(705, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(706, &numStack, token3);

 stackPop_CMockExpectAndReturn(707, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(708, 20, tempAnsToken);

 stackPush_CMockExpect(709, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(712, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(713, &numStack, token5);

 stackPop_CMockExpectAndReturn(714, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(715, 120, tempAnsToken2);

 stackPush_CMockExpect(716, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(719, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(720, &numStack, token7);

 stackPop_CMockExpectAndReturn(721, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(722, 219, tempAnsToken3);

 stackPush_CMockExpect(723, tempAnsToken3, &numStack);





 stackPop_CMockExpectAndReturn(726, &operatorStack, token8);

 stackPop_CMockExpectAndReturn(727, &numStack, token9);

 stackPop_CMockExpectAndReturn(728, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(729, 199, tempAnsToken4);

 stackPush_CMockExpect(730, tempAnsToken4, &numStack);





 stackPop_CMockExpectAndReturn(733, &operatorStack, token10);

 stackPop_CMockExpectAndReturn(734, &numStack, token11);

 stackPop_CMockExpectAndReturn(735, &numStack, tempAnsToken4);

 createNumberToken_CMockExpectAndReturn(736, 19, tempAnsToken5);

 stackPush_CMockExpect(737, tempAnsToken5, &numStack);





 stackPop_CMockExpectAndReturn(740, &operatorStack, token12);

 stackPop_CMockExpectAndReturn(741, &numStack, token13);

 stackPop_CMockExpectAndReturn(742, &numStack, tempAnsToken5);

 createNumberToken_CMockExpectAndReturn(743, 17, finalAnsToken);

 stackPush_CMockExpect(744, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(745, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}

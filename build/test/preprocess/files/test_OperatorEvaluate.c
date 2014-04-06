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
#include "CException.h"




void setUp(void){}

void tearDown(void){}

 void test_operatorEvaluate_should_throw_error_when_encounter_invalid_operator(void){



 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 Error exception;





 String tokenizer = {.rawString = "1$2", .startIndex = 0, .length=3};

 Number number1 = {.type= NUMBER, .value=1};

 Operator currentProgramCounter = {.type= OPERATOR, .id=CURRENT_PROGRAM_COUNTER , .precedence =0};

 Number number2 = {.type= NUMBER, .value=2};



 stackPop_CMockExpectAndReturn(45, &numberStack, &number1);

 stackPop_CMockExpectAndReturn(46, &numberStack, &number2);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

   operatorEvaluate(&numberStack,&currentProgramCounter);

  UnityFail( ("Invalid Operator should throw Error Not Operator"), (_U_UINT)50);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

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



 stackPop_CMockExpectAndReturn(72, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(73, &numberStack, &number3);

 createNumberToken_CMockExpectAndReturn(74, 10, answerToken);

 stackPush_CMockExpect(75, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(95, &numberStack, &number37);

 stackPop_CMockExpectAndReturn(96, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(97, 63, answerToken);

 stackPush_CMockExpect(98, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(117, &numberStack, &number50);

 stackPop_CMockExpectAndReturn(118, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(119, 5000, answerToken);

 stackPush_CMockExpect(120, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(139, &numberStack, &number3);

 stackPop_CMockExpectAndReturn(140, &numberStack, &number99);

 createNumberToken_CMockExpectAndReturn(141, 33, answerToken);

 stackPush_CMockExpect(142, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(161, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(162, &numberStack, &number60);

 createNumberToken_CMockExpectAndReturn(163, 4, answerToken);

 stackPush_CMockExpect(164, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(183, &numberStack, &number54);

 stackPop_CMockExpectAndReturn(184, &numberStack, &number45);

 createNumberToken_CMockExpectAndReturn(185, 36, answerToken);

 stackPush_CMockExpect(186, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(205, &numberStack, &number30);

 stackPop_CMockExpectAndReturn(206, &numberStack, &number56);

 createNumberToken_CMockExpectAndReturn(207, 62, answerToken);

 stackPush_CMockExpect(208, &answer, &numberStack);



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



 stackPop_CMockExpectAndReturn(227, &numberStack, &number30);

 stackPop_CMockExpectAndReturn(228, &numberStack, &number56);

 createNumberToken_CMockExpectAndReturn(229, 38, answerToken);

 stackPush_CMockExpect(230, &answer, &numberStack);



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





 stackPop_CMockExpectAndReturn(282, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(283, &numStack, token3);

 stackPop_CMockExpectAndReturn(284, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(285, 5, tempAnsToken);

 stackPush_CMockExpect(286, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(289, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(290, &numStack, token5);

 stackPop_CMockExpectAndReturn(291, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(292, 9, finalAnsToken);

 stackPush_CMockExpect(293, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(294, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(330, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(331, &numStack, token3);

 stackPop_CMockExpectAndReturn(332, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(333, 13, tempAnsToken);

 stackPush_CMockExpect(334, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(337, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(338, &numStack, token5);

 stackPop_CMockExpectAndReturn(339, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(340, 117, finalAnsToken);

 stackPush_CMockExpect(341, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(342, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(378, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(379, &numStack, token3);

 stackPop_CMockExpectAndReturn(380, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(381, 20, tempAnsToken);

 stackPush_CMockExpect(382, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(385, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(386, &numStack, token5);

 stackPop_CMockExpectAndReturn(387, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(388, 80, finalAnsToken);

 stackPush_CMockExpect(389, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(390, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(436, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(437, &numStack, token3);

 stackPop_CMockExpectAndReturn(438, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(439, 33, tempAnsToken);

 stackPush_CMockExpect(440, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(443, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(444, &numStack, token5);

 stackPop_CMockExpectAndReturn(445, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(446, 3, tempAnsToken2);

 stackPush_CMockExpect(447, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(450, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(451, &numStack, token7);

 stackPop_CMockExpectAndReturn(452, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(453, 13, finalAnsToken);

 stackPush_CMockExpect(454, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(455, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(510, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(511, &numStack, token3);

 stackPop_CMockExpectAndReturn(512, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(513, 20, tempAnsToken);

 stackPush_CMockExpect(514, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(517, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(518, &numStack, token5);

 stackPop_CMockExpectAndReturn(519, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(520, 120, tempAnsToken2);

 stackPush_CMockExpect(521, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(524, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(525, &numStack, token7);

 stackPop_CMockExpectAndReturn(526, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(527, 219, tempAnsToken3);

 stackPush_CMockExpect(528, tempAnsToken3, &numStack);





 stackPop_CMockExpectAndReturn(531, &operatorStack, token8);

 stackPop_CMockExpectAndReturn(532, &numStack, token9);

 stackPop_CMockExpectAndReturn(533, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(534, 199, finalAnsToken);

 stackPush_CMockExpect(535, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(536, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(600, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(601, &numStack, token3);

 stackPop_CMockExpectAndReturn(602, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(603, 20, tempAnsToken);

 stackPush_CMockExpect(604, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(607, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(608, &numStack, token5);

 stackPop_CMockExpectAndReturn(609, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(610, 120, tempAnsToken2);

 stackPush_CMockExpect(611, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(614, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(615, &numStack, token7);

 stackPop_CMockExpectAndReturn(616, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(617, 219, tempAnsToken3);

 stackPush_CMockExpect(618, tempAnsToken3, &numStack);





 stackPop_CMockExpectAndReturn(621, &operatorStack, token8);

 stackPop_CMockExpectAndReturn(622, &numStack, token9);

 stackPop_CMockExpectAndReturn(623, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(624, 199, tempAnsToken4);

 stackPush_CMockExpect(625, tempAnsToken4, &numStack);





 stackPop_CMockExpectAndReturn(628, &operatorStack, token10);

 stackPop_CMockExpectAndReturn(629, &numStack, token11);

 stackPop_CMockExpectAndReturn(630, &numStack, tempAnsToken4);

 createNumberToken_CMockExpectAndReturn(631, 19, finalAnsToken);

 stackPush_CMockExpect(632, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(633, &operatorStack, ((void *)0));



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





 stackPop_CMockExpectAndReturn(706, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(707, &numStack, token3);

 stackPop_CMockExpectAndReturn(708, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(709, 20, tempAnsToken);

 stackPush_CMockExpect(710, tempAnsToken, &numStack);





 stackPop_CMockExpectAndReturn(713, &operatorStack, token4);

 stackPop_CMockExpectAndReturn(714, &numStack, token5);

 stackPop_CMockExpectAndReturn(715, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(716, 120, tempAnsToken2);

 stackPush_CMockExpect(717, tempAnsToken2, &numStack);





 stackPop_CMockExpectAndReturn(720, &operatorStack, token6);

 stackPop_CMockExpectAndReturn(721, &numStack, token7);

 stackPop_CMockExpectAndReturn(722, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(723, 219, tempAnsToken3);

 stackPush_CMockExpect(724, tempAnsToken3, &numStack);





 stackPop_CMockExpectAndReturn(727, &operatorStack, token8);

 stackPop_CMockExpectAndReturn(728, &numStack, token9);

 stackPop_CMockExpectAndReturn(729, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(730, 199, tempAnsToken4);

 stackPush_CMockExpect(731, tempAnsToken4, &numStack);





 stackPop_CMockExpectAndReturn(734, &operatorStack, token10);

 stackPop_CMockExpectAndReturn(735, &numStack, token11);

 stackPop_CMockExpectAndReturn(736, &numStack, tempAnsToken4);

 createNumberToken_CMockExpectAndReturn(737, 19, tempAnsToken5);

 stackPush_CMockExpect(738, tempAnsToken5, &numStack);





 stackPop_CMockExpectAndReturn(741, &operatorStack, token12);

 stackPop_CMockExpectAndReturn(742, &numStack, token13);

 stackPop_CMockExpectAndReturn(743, &numStack, tempAnsToken5);

 createNumberToken_CMockExpectAndReturn(744, 17, finalAnsToken);

 stackPush_CMockExpect(745, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(746, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&numStack,&operatorStack);

}

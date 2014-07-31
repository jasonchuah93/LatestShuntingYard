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
#include "CException.h"




void setUp(void){}

void tearDown(void){}

 void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 Stack numberStack;

 Stack operatorStack;

 Error exception;

 String tokenizer = {.rawString = "0", .startIndex = 0, .length=1};



 Number number2 = {.type= NUMBER, .value=0};

 Token *token1 = (Token*)&number2;



 createStack_CMockExpectAndReturn(46, &numberStack);

 createStack_CMockExpectAndReturn(47, &operatorStack);

 stringCreate_CMockExpectAndReturn(48, ((void *)0), &tokenizer);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  check = evaluate(((void *)0));

  UnityFail( ("Should throw Error no expression "), (_U_UINT)53);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((INVALID_EXPRESSION)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_should_return_3_for_1_plus_2(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 String tokenizer = {.rawString = "1+2", .startIndex = 0, .length=3};



 Number number1 = {.type= NUMBER, .value=1};

 Number number2 = {.type= NUMBER, .value=2};

 Number number3 = {.type= NUMBER, .value=3};

 Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};



 createStack_CMockExpectAndReturn(73, &dataStack);

 createStack_CMockExpectAndReturn(74, &operatorStack);

 stringCreate_CMockExpectAndReturn(75, "1+2", &tokenizer);



 getToken_CMockExpectAndReturn(77, &tokenizer, (Token *)&number1);

 isNumber_CMockExpectAndReturn(78, (Token *)&number1, 1);

 stackPush_CMockExpect(79, (Token *)&number1, &dataStack);





 getToken_CMockExpectAndReturn(82, &tokenizer, (Token *)&plus);

 isNumber_CMockExpectAndReturn(83, (Token *)&plus, 0);

 isOperator_CMockExpectAndReturn(84, (Token *)&plus, 1);

 stackPop_CMockExpectAndReturn(85, &operatorStack, ((void *)0));

 stackPush_CMockExpect(86, (Token *)&plus, &operatorStack);





 getToken_CMockExpectAndReturn(89, &tokenizer, (Token *)&number2);

 isNumber_CMockExpectAndReturn(90, (Token *)&number2, 1);

 stackPush_CMockExpect(91, (Token *)&number2, &dataStack);

 getToken_CMockExpectAndReturn(92, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(95, &operatorStack, (Token *)&plus);

 stackPop_CMockExpectAndReturn(96, &dataStack, (Token *)&number2);

 stackPop_CMockExpectAndReturn(97, &dataStack, (Token *)&number1);

 createNumberToken_CMockExpectAndReturn(98, 3, (Token *)&number3);

 stackPush_CMockExpect(99, (Token *)&number3, &dataStack);

 stackPop_CMockExpectAndReturn(100, &operatorStack, ((void *)0));



 stackPop_CMockExpectAndReturn(102, &dataStack, (Token *)&number3);

 destroyStack_CMockExpect(103, &dataStack);

 destroyStack_CMockExpect(104, &operatorStack);

 check = evaluate("1+2");

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(129, &dataStack);

 createStack_CMockExpectAndReturn(130, &operatorStack);

 stringCreate_CMockExpectAndReturn(131, "60/10", &tokenizer);



 getToken_CMockExpectAndReturn(133, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(134, token1, 1);

 stackPush_CMockExpect(135, token1, &dataStack);





 getToken_CMockExpectAndReturn(138, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(139, token2, 0);

 isOperator_CMockExpectAndReturn(140, token2, 1);

 stackPop_CMockExpectAndReturn(141, &operatorStack, ((void *)0));

 stackPush_CMockExpect(142, token2, &operatorStack);





 getToken_CMockExpectAndReturn(145, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(146, token3, 1);

 stackPush_CMockExpect(147, token3, &dataStack);

 getToken_CMockExpectAndReturn(148, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(151, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(152, &dataStack, token3);

 stackPop_CMockExpectAndReturn(153, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(154, 6, answerToken);

 stackPush_CMockExpect(155, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(156, &operatorStack, ((void *)0));



 stackPop_CMockExpectAndReturn(158, &dataStack, answerToken);

 destroyStack_CMockExpect(159, &dataStack);

 destroyStack_CMockExpect(160, &operatorStack);



 check=evaluate("60/10");

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_evaluate_2_MULTIPLY_3_PLUS_4(void){



 int check;



 String tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};

 Token *token2 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Number tempAnswer = {.type=NUMBER, .value=6};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number finalAnswer = {.type=NUMBER, .value=10};

 Token *finalAnsToken = (Token*)&finalAnswer;





 createStack_CMockExpectAndReturn(195, &numStack);

 createStack_CMockExpectAndReturn(196, &opeStack);

 stringCreate_CMockExpectAndReturn(197, "2*3+4", &tokenizer);





 getToken_CMockExpectAndReturn(200, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(201, token1, 1);

 stackPush_CMockExpect(202, token1, &numStack);





 getToken_CMockExpectAndReturn(205, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(206, token2, 0);

 isOperator_CMockExpectAndReturn(207, token2, 1);

 stackPop_CMockExpectAndReturn(208, &opeStack, ((void *)0));

 stackPush_CMockExpect(209, token2, &opeStack);





 getToken_CMockExpectAndReturn(212, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(213, token3, 1);

 stackPush_CMockExpect(214, token3, &numStack);





 getToken_CMockExpectAndReturn(217, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(218, token4, 0);

 isOperator_CMockExpectAndReturn(219, token4, 1);

 stackPop_CMockExpectAndReturn(220, &opeStack, token2);

 stackPop_CMockExpectAndReturn(221, &numStack, token3);

 stackPop_CMockExpectAndReturn(222, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(223, 6, tempAnsToken);

 stackPush_CMockExpect(224, tempAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(225, &opeStack, ((void *)0));

 stackPush_CMockExpect(226, token4, &opeStack);





 getToken_CMockExpectAndReturn(229, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(230, token5, 1);

 stackPush_CMockExpect(231, token5, &numStack);

 getToken_CMockExpectAndReturn(232, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(235, &opeStack, token4);

 stackPop_CMockExpectAndReturn(236, &numStack, token5);

 stackPop_CMockExpectAndReturn(237, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(238, 10, finalAnsToken);

 stackPush_CMockExpect(239, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(240, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(242, &numStack, finalAnsToken);



 destroyStack_CMockExpect(244, &numStack);

 destroyStack_CMockExpect(245, &opeStack);



 check=evaluate("2*3+4");

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)248, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){

 int check;



 String tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};

 Token *token4 = (Token*)&multiply;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Operator plus1 = {.type= OPERATOR, .id = ADD ,.precedence=70};

 Token *token6 = (Token*)&plus1;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token7 = (Token*)&number5;



 Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};

 Token *token8 = (Token*)&multiply1;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token9 = (Token*)&number6;



 Number tempAnswer1 = {.type=NUMBER, .value=12};

 Token *tempAnsToken1 = (Token*)&tempAnswer1;



 Number tempAnswer2 = {.type=NUMBER, .value=14};

 Token *tempAnsToken2 = (Token*)&tempAnswer2;



 Number tempAnswer3 = {.type=NUMBER, .value=30};

 Token *tempAnsToken3 = (Token*)&tempAnswer3;



 Number finalAnswer = {.type=NUMBER, .value=44};

 Token *finalAnsToken = (Token*)&finalAnswer;







 createStack_CMockExpectAndReturn(299, &numStack);

 createStack_CMockExpectAndReturn(300, &opeStack);

 stringCreate_CMockExpectAndReturn(301, "2+3*4+5*6", &tokenizer);





 getToken_CMockExpectAndReturn(304, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(305, token1, 1);

 stackPush_CMockExpect(306, token1, &numStack);





 getToken_CMockExpectAndReturn(309, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(310, token2, 0);

 isOperator_CMockExpectAndReturn(311, token2, 1);

 stackPop_CMockExpectAndReturn(312, &opeStack, ((void *)0));

 stackPush_CMockExpect(313, token2, &opeStack);





 getToken_CMockExpectAndReturn(316, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(317, token3, 1);

 stackPush_CMockExpect(318, token3, &numStack);





 getToken_CMockExpectAndReturn(321, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(322, token4, 0);

 isOperator_CMockExpectAndReturn(323, token4, 1);

 stackPop_CMockExpectAndReturn(324, &opeStack, token2);

 stackPush_CMockExpect(325, token2, &opeStack);

 stackPush_CMockExpect(326, token4, &opeStack);





 getToken_CMockExpectAndReturn(329, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(330, token5, 1);

 stackPush_CMockExpect(331, token5, &numStack);













 getToken_CMockExpectAndReturn(338, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(339, token6, 0);

 isOperator_CMockExpectAndReturn(340, token6, 1);

 stackPop_CMockExpectAndReturn(341, &opeStack, token4);

 stackPop_CMockExpectAndReturn(342, &numStack, token5);

 stackPop_CMockExpectAndReturn(343, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(344, 12, tempAnsToken1);

 stackPush_CMockExpect(345, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(346, &opeStack, token2);

 stackPop_CMockExpectAndReturn(347, &numStack, tempAnsToken1);

 stackPop_CMockExpectAndReturn(348, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(349, 14, tempAnsToken2);

 stackPush_CMockExpect(350, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(351, &opeStack, ((void *)0));

 stackPush_CMockExpect(352, token6, &opeStack);





 getToken_CMockExpectAndReturn(355, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(356, token7, 1);

 stackPush_CMockExpect(357, token7, &numStack);





 getToken_CMockExpectAndReturn(360, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(361, token8, 0);

 isOperator_CMockExpectAndReturn(362, token8, 1);

 stackPop_CMockExpectAndReturn(363, &opeStack, token6);

 stackPush_CMockExpect(364, token6, &opeStack);

 stackPush_CMockExpect(365, token8, &opeStack);





 getToken_CMockExpectAndReturn(368, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(369, token9, 1);

 stackPush_CMockExpect(370, token9, &numStack);

 getToken_CMockExpectAndReturn(371, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(374, &opeStack, token8);

 stackPop_CMockExpectAndReturn(375, &numStack, token9);

 stackPop_CMockExpectAndReturn(376, &numStack, token7);

 createNumberToken_CMockExpectAndReturn(377, 30, tempAnsToken3);

 stackPush_CMockExpect(378, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(379, &opeStack, token6);

 stackPop_CMockExpectAndReturn(380, &numStack, tempAnsToken3);

 stackPop_CMockExpectAndReturn(381, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(382, 44, finalAnsToken);

 stackPush_CMockExpect(383, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(384, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(386, &numStack, finalAnsToken);



 destroyStack_CMockExpect(388, &numStack);

 destroyStack_CMockExpect(389, &opeStack);



 check=evaluate("2+3*4+5*6");

 UnityAssertEqualNumber((_U_SINT)((44)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)392, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){

 int check;



 String tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};

 Token *token2 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};

 Token *token6 = (Token*)&multiply1;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token7 = (Token*)&number5;



 Operator plus1 = {.type= OPERATOR, .id = ADD ,.precedence=70};

 Token *token8 = (Token*)&plus1;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token9 = (Token*)&number6;



 Number tempAnswer1 = {.type=NUMBER, .value=6};

 Token *tempAnsToken1 = (Token*)&tempAnswer1;



 Number tempAnswer2 = {.type=NUMBER, .value=20};

 Token *tempAnsToken2 = (Token*)&tempAnswer2;



 Number tempAnswer3 = {.type=NUMBER, .value=26};

 Token *tempAnsToken3 = (Token*)&tempAnswer3;



 Number finalAnswer = {.type=NUMBER, .value=32};

 Token *finalAnsToken = (Token*)&finalAnswer;





 createStack_CMockExpectAndReturn(441, &numStack);

 createStack_CMockExpectAndReturn(442, &opeStack);

 stringCreate_CMockExpectAndReturn(443, "2*3+4*5+6", &tokenizer);





 getToken_CMockExpectAndReturn(446, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(447, token1, 1);

 stackPush_CMockExpect(448, token1, &numStack);





 getToken_CMockExpectAndReturn(451, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(452, token2, 0);

 isOperator_CMockExpectAndReturn(453, token2, 1);

 stackPop_CMockExpectAndReturn(454, &opeStack, ((void *)0));

 stackPush_CMockExpect(455, token2, &opeStack);





 getToken_CMockExpectAndReturn(458, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(459, token3, 1);

 stackPush_CMockExpect(460, token3, &numStack);





 getToken_CMockExpectAndReturn(463, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(464, token4, 0);

 isOperator_CMockExpectAndReturn(465, token4, 1);

 stackPop_CMockExpectAndReturn(466, &opeStack, token2);

 stackPop_CMockExpectAndReturn(467, &numStack, token3);

 stackPop_CMockExpectAndReturn(468, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(469, 6, tempAnsToken1);

 stackPush_CMockExpect(470, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(471, &opeStack, ((void *)0));

 stackPush_CMockExpect(472, token4, &opeStack);





 getToken_CMockExpectAndReturn(475, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(476, token5, 1);

 stackPush_CMockExpect(477, token5, &numStack);





 getToken_CMockExpectAndReturn(480, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(481, token6, 0);

 isOperator_CMockExpectAndReturn(482, token6, 1);

 stackPop_CMockExpectAndReturn(483, &opeStack, token4);

 stackPush_CMockExpect(484, token4, &opeStack);

 stackPush_CMockExpect(485, token6, &opeStack);





 getToken_CMockExpectAndReturn(488, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(489, token7, 1);

 stackPush_CMockExpect(490, token7, &numStack);





 getToken_CMockExpectAndReturn(493, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(494, token8, 0);

 isOperator_CMockExpectAndReturn(495, token8, 1);

 stackPop_CMockExpectAndReturn(496, &opeStack, token6);

 stackPop_CMockExpectAndReturn(497, &numStack, token7);

 stackPop_CMockExpectAndReturn(498, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(499, 20, tempAnsToken2);

 stackPush_CMockExpect(500, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(501, &opeStack, token4);

 stackPop_CMockExpectAndReturn(502, &numStack, tempAnsToken2);

 stackPop_CMockExpectAndReturn(503, &numStack, tempAnsToken1);

 createNumberToken_CMockExpectAndReturn(504, 26, tempAnsToken3);

 stackPush_CMockExpect(505, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(506, &opeStack, ((void *)0));

 stackPush_CMockExpect(507, token8, &opeStack);





 getToken_CMockExpectAndReturn(510, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(511, token9, 1);

 stackPush_CMockExpect(512, token9, &numStack);

 getToken_CMockExpectAndReturn(513, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(516, &opeStack, token8);

 stackPop_CMockExpectAndReturn(517, &numStack, token9);

 stackPop_CMockExpectAndReturn(518, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(519, 32, finalAnsToken);

 stackPush_CMockExpect(520, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(521, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(523, &numStack, finalAnsToken);

 destroyStack_CMockExpect(524, &numStack);

 destroyStack_CMockExpect(525, &opeStack);



 check=evaluate("2*3+4*5+6");

 UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)528, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){



 int check;

 String tokenizer = {.rawString = "2|3+4*5-6-10", .startIndex = 0, .length = 11};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator OR = {.type= OPERATOR, .id = BITWISE_OR ,.precedence=10};

 Token *token2 = (Token*)&OR;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};

 Token *token6 = (Token*)&multiply;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token7 = (Token*)&number5;



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT ,.precedence=70};

 Token *token8 = (Token*)&subtract;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token9 = (Token*)&number6;



 Operator subtract1 = {.type= OPERATOR, .id = SUBTRACT ,.precedence=70};

 Token *token10 = (Token*)&subtract1;



 Number number10 = {.type= NUMBER, .value=10};

 Token *token11 = (Token*)&number10;



 Number tempAnswer1 = {.type=NUMBER, .value=20};

 Token *tempAnsToken1 = (Token*)&tempAnswer1;



 Number tempAnswer2 = {.type=NUMBER, .value=23};

 Token *tempAnsToken2 = (Token*)&tempAnswer2;



 Number tempAnswer3 = {.type=NUMBER, .value=17};

 Token *tempAnsToken3 = (Token*)&tempAnswer3;



 Number tempAnswer4 = {.type=NUMBER, .value=7};

 Token *tempAnsToken4 = (Token*)&tempAnswer4;



 Number finalAnswer = {.type=NUMBER, .value=7};

 Token *finalAnsToken = (Token*)&finalAnswer;





 createStack_CMockExpectAndReturn(586, &numStack);

 createStack_CMockExpectAndReturn(587, &opeStack);

 stringCreate_CMockExpectAndReturn(588, "2|3+4*5-6-10", &tokenizer);





 getToken_CMockExpectAndReturn(591, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(592, token1, 1);

 stackPush_CMockExpect(593, token1, &numStack);





 getToken_CMockExpectAndReturn(596, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(597, token2, 0);

 isOperator_CMockExpectAndReturn(598, token2, 1);

 stackPop_CMockExpectAndReturn(599, &opeStack, ((void *)0));

 stackPush_CMockExpect(600, token2, &opeStack);





 getToken_CMockExpectAndReturn(603, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(604, token3, 1);

 stackPush_CMockExpect(605, token3, &numStack);





 getToken_CMockExpectAndReturn(608, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(609, token4, 0);

 isOperator_CMockExpectAndReturn(610, token4, 1);

 stackPop_CMockExpectAndReturn(611, &opeStack, token2);

 stackPush_CMockExpect(612, token2, &opeStack);

 stackPush_CMockExpect(613, token4, &opeStack);





 getToken_CMockExpectAndReturn(616, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(617, token5, 1);

 stackPush_CMockExpect(618, token5, &numStack);





 getToken_CMockExpectAndReturn(621, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(622, token6, 0);

 isOperator_CMockExpectAndReturn(623, token6, 1);

 stackPop_CMockExpectAndReturn(624, &opeStack, token4);

 stackPush_CMockExpect(625, token4, &opeStack);

 stackPush_CMockExpect(626, token6, &opeStack);





 getToken_CMockExpectAndReturn(629, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(630, token7, 1);

 stackPush_CMockExpect(631, token7, &numStack);





 getToken_CMockExpectAndReturn(634, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(635, token8, 0);

 isOperator_CMockExpectAndReturn(636, token8, 1);

 stackPop_CMockExpectAndReturn(637, &opeStack, token6);

 stackPop_CMockExpectAndReturn(638, &numStack, token7);

 stackPop_CMockExpectAndReturn(639, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(640, 20, tempAnsToken1);

 stackPush_CMockExpect(641, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(642, &opeStack, token4);

 stackPop_CMockExpectAndReturn(643, &numStack, tempAnsToken1);

 stackPop_CMockExpectAndReturn(644, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(645, 23, tempAnsToken2);

 stackPush_CMockExpect(646, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(647, &opeStack, token2);

 stackPush_CMockExpect(648, token2, &opeStack);

 stackPush_CMockExpect(649, token8, &opeStack);





 getToken_CMockExpectAndReturn(652, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(653, token9, 1);

 stackPush_CMockExpect(654, token9, &numStack);





 getToken_CMockExpectAndReturn(657, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(658, token10, 0);

 isOperator_CMockExpectAndReturn(659, token10, 1);

 stackPop_CMockExpectAndReturn(660, &opeStack, token8);

 stackPop_CMockExpectAndReturn(661, &numStack, token9);

 stackPop_CMockExpectAndReturn(662, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(663, 17, tempAnsToken3);

 stackPush_CMockExpect(664, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(665, &opeStack, token2);

 stackPush_CMockExpect(666, token2, &opeStack);

 stackPush_CMockExpect(667, token10, &opeStack);





 getToken_CMockExpectAndReturn(670, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(671, token11, 1);

 stackPush_CMockExpect(672, token11, &numStack);

 getToken_CMockExpectAndReturn(673, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(676, &opeStack, token10);

 stackPop_CMockExpectAndReturn(677, &numStack, token11);

 stackPop_CMockExpectAndReturn(678, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(679, 7, tempAnsToken4);

 stackPush_CMockExpect(680, tempAnsToken4, &numStack);

 stackPop_CMockExpectAndReturn(681, &opeStack, token2);

 stackPop_CMockExpectAndReturn(682, &numStack, tempAnsToken4);

 stackPop_CMockExpectAndReturn(683, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(684, 7, finalAnsToken);

 stackPush_CMockExpect(685, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(686, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(688, &numStack, finalAnsToken);

 destroyStack_CMockExpect(689, &numStack);

 destroyStack_CMockExpect(690, &opeStack);



 check=evaluate("2|3+4*5-6-10");

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)693, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_should_evaluate_43_HASHTAG_42_and_throw_error_invalid_operator(void){



 Stack dataStack;

 Stack operatorStack;

 int check;

 Error e;



 String tokenizer = {.rawString = "43)42", .startIndex = 0};



 Number number43 = {.type= NUMBER, .value=43};

 Token *token1 = (Token*)&number43;



 Operator hashtag = {.type= OPERATOR, .id=RIGHT_PARENTHESIS, .precedence=50};

 Token *token2 = (Token*)&hashtag;



 Number number42 = {.type= NUMBER, .value=42};

 Token *token3 = (Token*)&number42;



 createStack_CMockExpectAndReturn(715, &dataStack);

 createStack_CMockExpectAndReturn(716, &operatorStack);

 stringCreate_CMockExpectAndReturn(717, "43#42", &tokenizer);



 getToken_CMockExpectAndReturn(719, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(720, token1, 1);

 stackPush_CMockExpect(721, token1, &dataStack);



 getToken_CMockExpectAndThrow(723, &tokenizer, UNKNOWN_OPERATOR);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("43#42");

   UnityFail( ("Should throw ERR_INVALID_OPERATOR"), (_U_UINT)727);;

  }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

   UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)729, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_should_evaluate_left_parenthesis_2_right_parenthesis(void){

 Stack dataStack;

 Stack operatorStack;

 int check;

 int e;



 String tokenizer = {.rawString = "(2)", .startIndex = 0, .length = 3};



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};

 Token *token1 = (Token*)&leftBracket;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};

 Token *token3 = (Token*)&rightBracket;



 Number answer = {.type= NUMBER, .value=2};

 Token *answerToken = (Token*)&answer;



 createStack_CMockExpectAndReturn(753, &dataStack);

 createStack_CMockExpectAndReturn(754, &operatorStack);

 stringCreate_CMockExpectAndReturn(755, "(2)", &tokenizer);





 getToken_CMockExpectAndReturn(758, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(759, token1, 0);

 isOperator_CMockExpectAndReturn(760, token1, 1);

 stackPop_CMockExpectAndReturn(761, &operatorStack, ((void *)0));

 stackPush_CMockExpect(762, token1, &operatorStack);





 getToken_CMockExpectAndReturn(765, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(766, token2, 1);

 stackPush_CMockExpect(767, token2, &dataStack);





 getToken_CMockExpectAndReturn(770, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(771, token3, 0);

 isOperator_CMockExpectAndReturn(772, token3, 1);

 stackPop_CMockExpectAndReturn(773, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(774, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(775, 2, answerToken);

 stackPush_CMockExpect(776, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(777, &operatorStack, ((void *)0));

 getToken_CMockExpectAndReturn(778, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(781, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(782, &dataStack, answerToken);

 destroyStack_CMockExpect(783, &dataStack);

 destroyStack_CMockExpect(784, &operatorStack);



 check=evaluate("(2)");

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)787, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left_parenthesis_22_right_parenthesis(void){

 Stack dataStack;

 Stack operatorStack;

 int check;

 int e;



 String tokenizer = {.rawString = "(22)", .startIndex = 0, .length = 3};



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};

 Token *token1 = (Token*)&leftBracket;



 Number number22 = {.type= NUMBER, .value=22};

 Token *token2 = (Token*)&number22;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};

 Token *token3 = (Token*)&rightBracket;



 Number answer = {.type= NUMBER, .value=22};

 Token *answerToken = (Token*)&answer;



 createStack_CMockExpectAndReturn(812, &dataStack);

 createStack_CMockExpectAndReturn(813, &operatorStack);

 stringCreate_CMockExpectAndReturn(814, "(22)", &tokenizer);





 getToken_CMockExpectAndReturn(817, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(818, token1, 0);

 isOperator_CMockExpectAndReturn(819, token1, 1);

 stackPop_CMockExpectAndReturn(820, &operatorStack, ((void *)0));

 stackPush_CMockExpect(821, token1, &operatorStack);





 getToken_CMockExpectAndReturn(824, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(825, token2, 1);

 stackPush_CMockExpect(826, token2, &dataStack);





 getToken_CMockExpectAndReturn(829, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(830, token3, 0);

 isOperator_CMockExpectAndReturn(831, token3, 1);

 stackPop_CMockExpectAndReturn(832, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(833, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(834, 22, answerToken);

 stackPush_CMockExpect(835, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(836, &operatorStack, ((void *)0));

 getToken_CMockExpectAndReturn(837, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(840, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(841, &dataStack, answerToken);

 destroyStack_CMockExpect(842, &dataStack);

 destroyStack_CMockExpect(843, &operatorStack);



 check=evaluate("(22)");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)846, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_left_bracket_2_plus_3_right_bracket(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 String tokenizer = {.rawString = "(2+3)", .startIndex = 0, .length = 5};



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};

 Token *token1 = (Token*)&leftBracket;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=60};

 Token *token3 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token4 = (Token*)&number3;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};

 Token *token5 = (Token*)&rightBracket;



 Number answer = {.type= NUMBER, .value=5};

 Token *ansToken = (Token*)&answer;



 createStack_CMockExpectAndReturn(876, &dataStack);

 createStack_CMockExpectAndReturn(877, &operatorStack);

 stringCreate_CMockExpectAndReturn(878, "(2+3)", &tokenizer);



 getToken_CMockExpectAndReturn(880, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(881, token1, 0);

 isOperator_CMockExpectAndReturn(882, token1, 1);

 stackPop_CMockExpectAndReturn(883, &operatorStack, ((void *)0));

 stackPush_CMockExpect(884, token1, &operatorStack);



 getToken_CMockExpectAndReturn(886, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(887, token2, 1);

 stackPush_CMockExpect(888, token2, &dataStack);



 getToken_CMockExpectAndReturn(890, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(891, token3, 0);

 isOperator_CMockExpectAndReturn(892, token3, 1);

 stackPop_CMockExpectAndReturn(893, &operatorStack, token1);

 stackPush_CMockExpect(894, token1, &operatorStack);

 stackPush_CMockExpect(895, token3, &operatorStack);



 getToken_CMockExpectAndReturn(897, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(898, token4, 1);

 stackPush_CMockExpect(899, token4, &dataStack);



 getToken_CMockExpectAndReturn(901, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(902, token5, 0);

 isOperator_CMockExpectAndReturn(903, token5, 1);

 stackPop_CMockExpectAndReturn(904, &operatorStack, token3);

 stackPop_CMockExpectAndReturn(905, &dataStack, token4);

 stackPop_CMockExpectAndReturn(906, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(907, 5, ansToken);

 stackPush_CMockExpect(908, ansToken, &dataStack);

 stackPop_CMockExpectAndReturn(909, &operatorStack, ((void *)0));

 getToken_CMockExpectAndReturn(910, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(913, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(914, &dataStack, ansToken);

 destroyStack_CMockExpect(915, &dataStack);

 destroyStack_CMockExpect(916, &operatorStack);



 check=evaluate("(2+3)");

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)919, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_left_bracket_20_multiply_3_subtract_50_right_bracket(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 String tokenizer = {.rawString = "(20*3-50)", .startIndex = 0, .length = 7};



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};

 Token *token1 = (Token*)&leftBracket;



 Number number20 = {.type= NUMBER, .value=20};

 Token *token2 = (Token*)&number20;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=70};

 Token *token3 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token4 = (Token*)&number3;



 Operator minus = {.type= OPERATOR, .id = SUBTRACT ,.precedence=60};

 Token *token5 = (Token*)&minus;



 Number number50 = {.type= NUMBER, .value=50};

 Token *token6 = (Token*)&number50;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};

 Token *token7 = (Token*)&rightBracket;



 Number tempAnswer = {.type= NUMBER, .value=60};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number answer = {.type= NUMBER, .value=10};

 Token *ansToken = (Token*)&answer;



 createStack_CMockExpectAndReturn(957, &dataStack);

 createStack_CMockExpectAndReturn(958, &operatorStack);

 stringCreate_CMockExpectAndReturn(959, "(20*3-50)", &tokenizer);



 getToken_CMockExpectAndReturn(961, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(962, token1, 0);

 isOperator_CMockExpectAndReturn(963, token1, 1);

 stackPop_CMockExpectAndReturn(964, &operatorStack, ((void *)0));

 stackPush_CMockExpect(965, token1, &operatorStack);



 getToken_CMockExpectAndReturn(967, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(968, token2, 1);

 stackPush_CMockExpect(969, token2, &dataStack);



 getToken_CMockExpectAndReturn(971, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(972, token3, 0);

 isOperator_CMockExpectAndReturn(973, token3, 1);

 stackPop_CMockExpectAndReturn(974, &operatorStack, token1);

 stackPush_CMockExpect(975, token1, &operatorStack);

 stackPush_CMockExpect(976, token3, &operatorStack);



 getToken_CMockExpectAndReturn(978, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(979, token4, 1);

 stackPush_CMockExpect(980, token4, &dataStack);



 getToken_CMockExpectAndReturn(982, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(983, token5, 0);

 isOperator_CMockExpectAndReturn(984, token5, 1);

 stackPop_CMockExpectAndReturn(985, &operatorStack, token3);

 stackPop_CMockExpectAndReturn(986, &dataStack, token4);

 stackPop_CMockExpectAndReturn(987, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(988, 60, tempAnsToken);

 stackPush_CMockExpect(989, tempAnsToken, &dataStack);

 stackPop_CMockExpectAndReturn(990, &operatorStack, token1);

 stackPush_CMockExpect(991, token1, &operatorStack);

 stackPush_CMockExpect(992, token5, &operatorStack);



 getToken_CMockExpectAndReturn(994, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(995, token6, 1);

 stackPush_CMockExpect(996, token6, &dataStack);



 getToken_CMockExpectAndReturn(998, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(999, token7, 0);

 isOperator_CMockExpectAndReturn(1000, token7, 1);

 stackPop_CMockExpectAndReturn(1001, &operatorStack, token5);

 stackPop_CMockExpectAndReturn(1002, &dataStack, token6);

 stackPop_CMockExpectAndReturn(1003, &dataStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(1004, 10, ansToken);

 stackPush_CMockExpect(1005, ansToken, &dataStack);

 stackPop_CMockExpectAndReturn(1006, &operatorStack, ((void *)0));

 getToken_CMockExpectAndReturn(1007, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(1010, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(1011, &dataStack, ansToken);

 destroyStack_CMockExpect(1012, &dataStack);

 destroyStack_CMockExpect(1013, &operatorStack);



 check=evaluate("(20*3-50)");

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1016, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_logic_not_12_SHOULD_RETURN_0(void){



 Stack numStack;

 Stack opeStack;

 int check;





 String tokenizer = {.rawString = "!12", .startIndex = 0, .length = 2 };



 Operator logicNot = {.type= OPERATOR, .id = LOGIC_NOT, .precedence=80};

 Token *token1 = (Token*)&logicNot;



 Number number12 = {.type= NUMBER, .value=12};

 Token *token2 = (Token*)&number12;



 Number answer = {.type=NUMBER, .value=0};

 Token *ansToken = (Token*)&answer;





 createStack_CMockExpectAndReturn(1039, &numStack);

 createStack_CMockExpectAndReturn(1040, &opeStack);

 stringCreate_CMockExpectAndReturn(1041, "!12", &tokenizer);





 getToken_CMockExpectAndReturn(1044, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1045, token1, 0);

 isOperator_CMockExpectAndReturn(1046, token1, 1);

 stackPop_CMockExpectAndReturn(1047, &opeStack, ((void *)0));

 stackPush_CMockExpect(1048, token1, &opeStack);





 getToken_CMockExpectAndReturn(1051, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1052, token2, 1);

 stackPush_CMockExpect(1053, token2, &numStack);

 getToken_CMockExpectAndReturn(1054, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(1057, &opeStack, token1);

 stackPop_CMockExpectAndReturn(1058, &numStack, token2);

 stackPop_CMockExpectAndReturn(1059, &numStack, ((void *)0));

 createNumberToken_CMockExpectAndReturn(1060, 0, ansToken);

 stackPush_CMockExpect(1061, ansToken, &numStack);

 stackPop_CMockExpectAndReturn(1062, &opeStack, ((void *)0));

 stackPop_CMockExpectAndReturn(1063, &numStack, ansToken);

 destroyStack_CMockExpect(1064, &numStack);

 destroyStack_CMockExpect(1065, &opeStack);



 check=evaluate("!12");

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1068, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_NEGATIVE_2_SHOULD_RETURN_NEGATIVE_2(void){



 Stack numStack;

 Stack opeStack;

 int check;





 String tokenizer = {.rawString = "-2", .startIndex = 0, .length = 2 };



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT, .precedence=60};

 Token *token1 = (Token*)&subtract;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Number answer = {.type=NUMBER, .value=-2};

 Token *ansToken = (Token*)&answer;





 createStack_CMockExpectAndReturn(1092, &numStack);

 createStack_CMockExpectAndReturn(1093, &opeStack);

 stringCreate_CMockExpectAndReturn(1094, "-2", &tokenizer);





 getToken_CMockExpectAndReturn(1097, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1098, token1, 0);

 isOperator_CMockExpectAndReturn(1099, token1, 1);

 stackPop_CMockExpectAndReturn(1100, &opeStack, ((void *)0));

 stackPush_CMockExpect(1101, token1, &opeStack);





 getToken_CMockExpectAndReturn(1104, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1105, token2, 1);

 stackPush_CMockExpect(1106, token2, &numStack);

 getToken_CMockExpectAndReturn(1107, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(1110, &opeStack, token1);

 stackPop_CMockExpectAndReturn(1111, &numStack, token2);

 stackPop_CMockExpectAndReturn(1112, &numStack, ((void *)0));

 createNumberToken_CMockExpectAndReturn(1113, -2, ansToken);

 stackPush_CMockExpect(1114, ansToken, &numStack);

 stackPop_CMockExpectAndReturn(1115, &opeStack, ((void *)0));

 stackPop_CMockExpectAndReturn(1116, &numStack, ansToken);

 destroyStack_CMockExpect(1117, &numStack);

 destroyStack_CMockExpect(1118, &opeStack);



 check=evaluate("-2");

 UnityAssertEqualNumber((_U_SINT)((-2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1121, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}

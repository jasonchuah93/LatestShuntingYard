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





 createStack_CMockExpectAndReturn(196, &numStack);

 createStack_CMockExpectAndReturn(197, &opeStack);

 stringCreate_CMockExpectAndReturn(198, "2*3+4", &tokenizer);





 getToken_CMockExpectAndReturn(201, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(202, token1, 1);

 stackPush_CMockExpect(203, token1, &numStack);





 getToken_CMockExpectAndReturn(206, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(207, token2, 0);

 isOperator_CMockExpectAndReturn(208, token2, 1);

 stackPop_CMockExpectAndReturn(209, &opeStack, ((void *)0));

 stackPush_CMockExpect(210, token2, &opeStack);





 getToken_CMockExpectAndReturn(213, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(214, token3, 1);

 stackPush_CMockExpect(215, token3, &numStack);





 getToken_CMockExpectAndReturn(218, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(219, token4, 0);

 isOperator_CMockExpectAndReturn(220, token4, 1);

 stackPop_CMockExpectAndReturn(221, &opeStack, token2);

 stackPop_CMockExpectAndReturn(222, &numStack, token3);

 stackPop_CMockExpectAndReturn(223, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(224, 6, tempAnsToken);

 stackPush_CMockExpect(225, tempAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(226, &opeStack, ((void *)0));

 stackPush_CMockExpect(227, token4, &opeStack);





 getToken_CMockExpectAndReturn(230, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(231, token5, 1);

 stackPush_CMockExpect(232, token5, &numStack);

 getToken_CMockExpectAndReturn(233, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(236, &opeStack, token4);

 stackPop_CMockExpectAndReturn(237, &numStack, token5);

 stackPop_CMockExpectAndReturn(238, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(239, 10, finalAnsToken);

 stackPush_CMockExpect(240, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(241, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(243, &numStack, finalAnsToken);

 check=evaluate("2*3+4");

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)245, UNITY_DISPLAY_STYLE_INT);

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







 createStack_CMockExpectAndReturn(296, &numStack);

 createStack_CMockExpectAndReturn(297, &opeStack);

 stringCreate_CMockExpectAndReturn(298, "2+3*4+5*6", &tokenizer);





 getToken_CMockExpectAndReturn(301, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(302, token1, 1);

 stackPush_CMockExpect(303, token1, &numStack);





 getToken_CMockExpectAndReturn(306, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(307, token2, 0);

 isOperator_CMockExpectAndReturn(308, token2, 1);

 stackPop_CMockExpectAndReturn(309, &opeStack, ((void *)0));

 stackPush_CMockExpect(310, token2, &opeStack);





 getToken_CMockExpectAndReturn(313, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(314, token3, 1);

 stackPush_CMockExpect(315, token3, &numStack);





 getToken_CMockExpectAndReturn(318, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(319, token4, 0);

 isOperator_CMockExpectAndReturn(320, token4, 1);

 stackPop_CMockExpectAndReturn(321, &opeStack, token2);

 stackPush_CMockExpect(322, token2, &opeStack);

 stackPush_CMockExpect(323, token4, &opeStack);





 getToken_CMockExpectAndReturn(326, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(327, token5, 1);

 stackPush_CMockExpect(328, token5, &numStack);













 getToken_CMockExpectAndReturn(335, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(336, token6, 0);

 isOperator_CMockExpectAndReturn(337, token6, 1);

 stackPop_CMockExpectAndReturn(338, &opeStack, token4);

 stackPop_CMockExpectAndReturn(339, &numStack, token5);

 stackPop_CMockExpectAndReturn(340, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(341, 12, tempAnsToken1);

 stackPush_CMockExpect(342, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(343, &opeStack, token2);

 stackPop_CMockExpectAndReturn(344, &numStack, tempAnsToken1);

 stackPop_CMockExpectAndReturn(345, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(346, 14, tempAnsToken2);

 stackPush_CMockExpect(347, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(348, &opeStack, ((void *)0));

 stackPush_CMockExpect(349, token6, &opeStack);





 getToken_CMockExpectAndReturn(352, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(353, token7, 1);

 stackPush_CMockExpect(354, token7, &numStack);





 getToken_CMockExpectAndReturn(357, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(358, token8, 0);

 isOperator_CMockExpectAndReturn(359, token8, 1);

 stackPop_CMockExpectAndReturn(360, &opeStack, token6);

 stackPush_CMockExpect(361, token6, &opeStack);

 stackPush_CMockExpect(362, token8, &opeStack);





 getToken_CMockExpectAndReturn(365, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(366, token9, 1);

 stackPush_CMockExpect(367, token9, &numStack);

 getToken_CMockExpectAndReturn(368, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(371, &opeStack, token8);

 stackPop_CMockExpectAndReturn(372, &numStack, token9);

 stackPop_CMockExpectAndReturn(373, &numStack, token7);

 createNumberToken_CMockExpectAndReturn(374, 30, tempAnsToken3);

 stackPush_CMockExpect(375, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(376, &opeStack, token6);

 stackPop_CMockExpectAndReturn(377, &numStack, tempAnsToken3);

 stackPop_CMockExpectAndReturn(378, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(379, 44, finalAnsToken);

 stackPush_CMockExpect(380, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(381, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(383, &numStack, finalAnsToken);

 check=evaluate("2+3*4+5*6");

 UnityAssertEqualNumber((_U_SINT)((44)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)385, UNITY_DISPLAY_STYLE_INT);

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





 createStack_CMockExpectAndReturn(434, &numStack);

 createStack_CMockExpectAndReturn(435, &opeStack);

 stringCreate_CMockExpectAndReturn(436, "2*3+4*5+6", &tokenizer);





 getToken_CMockExpectAndReturn(439, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(440, token1, 1);

 stackPush_CMockExpect(441, token1, &numStack);





 getToken_CMockExpectAndReturn(444, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(445, token2, 0);

 isOperator_CMockExpectAndReturn(446, token2, 1);

 stackPop_CMockExpectAndReturn(447, &opeStack, ((void *)0));

 stackPush_CMockExpect(448, token2, &opeStack);





 getToken_CMockExpectAndReturn(451, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(452, token3, 1);

 stackPush_CMockExpect(453, token3, &numStack);





 getToken_CMockExpectAndReturn(456, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(457, token4, 0);

 isOperator_CMockExpectAndReturn(458, token4, 1);

 stackPop_CMockExpectAndReturn(459, &opeStack, token2);

 stackPop_CMockExpectAndReturn(460, &numStack, token3);

 stackPop_CMockExpectAndReturn(461, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(462, 6, tempAnsToken1);

 stackPush_CMockExpect(463, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(464, &opeStack, ((void *)0));

 stackPush_CMockExpect(465, token4, &opeStack);





 getToken_CMockExpectAndReturn(468, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(469, token5, 1);

 stackPush_CMockExpect(470, token5, &numStack);





 getToken_CMockExpectAndReturn(473, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(474, token6, 0);

 isOperator_CMockExpectAndReturn(475, token6, 1);

 stackPop_CMockExpectAndReturn(476, &opeStack, token4);

 stackPush_CMockExpect(477, token4, &opeStack);

 stackPush_CMockExpect(478, token6, &opeStack);





 getToken_CMockExpectAndReturn(481, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(482, token7, 1);

 stackPush_CMockExpect(483, token7, &numStack);





 getToken_CMockExpectAndReturn(486, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(487, token8, 0);

 isOperator_CMockExpectAndReturn(488, token8, 1);

 stackPop_CMockExpectAndReturn(489, &opeStack, token6);

 stackPop_CMockExpectAndReturn(490, &numStack, token7);

 stackPop_CMockExpectAndReturn(491, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(492, 20, tempAnsToken2);

 stackPush_CMockExpect(493, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(494, &opeStack, token4);

 stackPop_CMockExpectAndReturn(495, &numStack, tempAnsToken2);

 stackPop_CMockExpectAndReturn(496, &numStack, tempAnsToken1);

 createNumberToken_CMockExpectAndReturn(497, 26, tempAnsToken3);

 stackPush_CMockExpect(498, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(499, &opeStack, ((void *)0));

 stackPush_CMockExpect(500, token8, &opeStack);





 getToken_CMockExpectAndReturn(503, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(504, token9, 1);

 stackPush_CMockExpect(505, token9, &numStack);

 getToken_CMockExpectAndReturn(506, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(509, &opeStack, token8);

 stackPop_CMockExpectAndReturn(510, &numStack, token9);

 stackPop_CMockExpectAndReturn(511, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(512, 32, finalAnsToken);

 stackPush_CMockExpect(513, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(514, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(516, &numStack, finalAnsToken);



 check=evaluate("2*3+4*5+6");

 UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)519, UNITY_DISPLAY_STYLE_INT);

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





 createStack_CMockExpectAndReturn(578, &numStack);

 createStack_CMockExpectAndReturn(579, &opeStack);

 stringCreate_CMockExpectAndReturn(580, "2|3+4*5-6-10", &tokenizer);





 getToken_CMockExpectAndReturn(583, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(584, token1, 1);

 stackPush_CMockExpect(585, token1, &numStack);





 getToken_CMockExpectAndReturn(588, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(589, token2, 0);

 isOperator_CMockExpectAndReturn(590, token2, 1);

 stackPop_CMockExpectAndReturn(591, &opeStack, ((void *)0));

 stackPush_CMockExpect(592, token2, &opeStack);





 getToken_CMockExpectAndReturn(595, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(596, token3, 1);

 stackPush_CMockExpect(597, token3, &numStack);





 getToken_CMockExpectAndReturn(600, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(601, token4, 0);

 isOperator_CMockExpectAndReturn(602, token4, 1);

 stackPop_CMockExpectAndReturn(603, &opeStack, token2);

 stackPush_CMockExpect(604, token2, &opeStack);

 stackPush_CMockExpect(605, token4, &opeStack);





 getToken_CMockExpectAndReturn(608, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(609, token5, 1);

 stackPush_CMockExpect(610, token5, &numStack);





 getToken_CMockExpectAndReturn(613, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(614, token6, 0);

 isOperator_CMockExpectAndReturn(615, token6, 1);

 stackPop_CMockExpectAndReturn(616, &opeStack, token4);

 stackPush_CMockExpect(617, token4, &opeStack);

 stackPush_CMockExpect(618, token6, &opeStack);





 getToken_CMockExpectAndReturn(621, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(622, token7, 1);

 stackPush_CMockExpect(623, token7, &numStack);





 getToken_CMockExpectAndReturn(626, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(627, token8, 0);

 isOperator_CMockExpectAndReturn(628, token8, 1);

 stackPop_CMockExpectAndReturn(629, &opeStack, token6);

 stackPop_CMockExpectAndReturn(630, &numStack, token7);

 stackPop_CMockExpectAndReturn(631, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(632, 20, tempAnsToken1);

 stackPush_CMockExpect(633, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(634, &opeStack, token4);

 stackPop_CMockExpectAndReturn(635, &numStack, tempAnsToken1);

 stackPop_CMockExpectAndReturn(636, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(637, 23, tempAnsToken2);

 stackPush_CMockExpect(638, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(639, &opeStack, token2);

 stackPush_CMockExpect(640, token2, &opeStack);

 stackPush_CMockExpect(641, token8, &opeStack);





 getToken_CMockExpectAndReturn(644, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(645, token9, 1);

 stackPush_CMockExpect(646, token9, &numStack);





 getToken_CMockExpectAndReturn(649, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(650, token10, 0);

 isOperator_CMockExpectAndReturn(651, token10, 1);

 stackPop_CMockExpectAndReturn(652, &opeStack, token8);

 stackPop_CMockExpectAndReturn(653, &numStack, token9);

 stackPop_CMockExpectAndReturn(654, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(655, 17, tempAnsToken3);

 stackPush_CMockExpect(656, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(657, &opeStack, token2);

 stackPush_CMockExpect(658, token2, &opeStack);

 stackPush_CMockExpect(659, token10, &opeStack);





 getToken_CMockExpectAndReturn(662, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(663, token11, 1);

 stackPush_CMockExpect(664, token11, &numStack);

 getToken_CMockExpectAndReturn(665, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(668, &opeStack, token10);

 stackPop_CMockExpectAndReturn(669, &numStack, token11);

 stackPop_CMockExpectAndReturn(670, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(671, 7, tempAnsToken4);

 stackPush_CMockExpect(672, tempAnsToken4, &numStack);

 stackPop_CMockExpectAndReturn(673, &opeStack, token2);

 stackPop_CMockExpectAndReturn(674, &numStack, tempAnsToken4);

 stackPop_CMockExpectAndReturn(675, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(676, 7, finalAnsToken);

 stackPush_CMockExpect(677, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(678, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(680, &numStack, finalAnsToken);



 check=evaluate("2|3+4*5-6-10");

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)683, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}

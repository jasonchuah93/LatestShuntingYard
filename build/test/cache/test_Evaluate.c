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



 createStack_CMockExpectAndReturn(45, &numberStack);

 createStack_CMockExpectAndReturn(46, &operatorStack);

 stringCreate_CMockExpectAndReturn(47, ((void *)0), &tokenizer);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  check = evaluate(((void *)0));

  UnityFail( ("Should throw Error no expression "), (_U_UINT)52);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((INVALID_EXPRESSION)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

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

 createStack_CMockExpectAndReturn(78, &dataStack);

 createStack_CMockExpectAndReturn(79, &operatorStack);

 stringCreate_CMockExpectAndReturn(80, "1+2", &tokenizer);



 getToken_CMockExpectAndReturn(82, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(83, token1, 1);

 stackPush_CMockExpect(84, token1, &dataStack);





 getToken_CMockExpectAndReturn(87, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(88, token2, 0);

 isOperator_CMockExpectAndReturn(89, token2, 1);

 stackPop_CMockExpectAndReturn(90, &operatorStack, ((void *)0));

 stackPush_CMockExpect(91, token2, &operatorStack);





 getToken_CMockExpectAndReturn(94, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(95, token3, 1);

 stackPush_CMockExpect(96, token3, &dataStack);

 getToken_CMockExpectAndReturn(97, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(100, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(101, &dataStack, token3);

 stackPop_CMockExpectAndReturn(102, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(103, 3, answerToken);

 stackPush_CMockExpect(104, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(105, &operatorStack, ((void *)0));



 stackPop_CMockExpectAndReturn(107, &dataStack, answerToken);

 destroyStack_CMockExpect(108, &dataStack);

 destroyStack_CMockExpect(109, &operatorStack);

 check=evaluate("1+2");

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(134, &dataStack);

 createStack_CMockExpectAndReturn(135, &operatorStack);

 stringCreate_CMockExpectAndReturn(136, "60/10", &tokenizer);



 getToken_CMockExpectAndReturn(138, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(139, token1, 1);

 stackPush_CMockExpect(140, token1, &dataStack);





 getToken_CMockExpectAndReturn(143, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(144, token2, 0);

 isOperator_CMockExpectAndReturn(145, token2, 1);

 stackPop_CMockExpectAndReturn(146, &operatorStack, ((void *)0));

 stackPush_CMockExpect(147, token2, &operatorStack);





 getToken_CMockExpectAndReturn(150, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(151, token3, 1);

 stackPush_CMockExpect(152, token3, &dataStack);

 getToken_CMockExpectAndReturn(153, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(156, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(157, &dataStack, token3);

 stackPop_CMockExpectAndReturn(158, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(159, 6, answerToken);

 stackPush_CMockExpect(160, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(161, &operatorStack, ((void *)0));



 stackPop_CMockExpectAndReturn(163, &dataStack, answerToken);

 destroyStack_CMockExpect(164, &dataStack);

 destroyStack_CMockExpect(165, &operatorStack);



 check=evaluate("60/10");

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

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





 createStack_CMockExpectAndReturn(200, &numStack);

 createStack_CMockExpectAndReturn(201, &opeStack);

 stringCreate_CMockExpectAndReturn(202, "2*3+4", &tokenizer);





 getToken_CMockExpectAndReturn(205, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(206, token1, 1);

 stackPush_CMockExpect(207, token1, &numStack);





 getToken_CMockExpectAndReturn(210, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(211, token2, 0);

 isOperator_CMockExpectAndReturn(212, token2, 1);

 stackPop_CMockExpectAndReturn(213, &opeStack, ((void *)0));

 stackPush_CMockExpect(214, token2, &opeStack);





 getToken_CMockExpectAndReturn(217, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(218, token3, 1);

 stackPush_CMockExpect(219, token3, &numStack);





 getToken_CMockExpectAndReturn(222, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(223, token4, 0);

 isOperator_CMockExpectAndReturn(224, token4, 1);

 stackPop_CMockExpectAndReturn(225, &opeStack, token2);

 stackPop_CMockExpectAndReturn(226, &numStack, token3);

 stackPop_CMockExpectAndReturn(227, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(228, 6, tempAnsToken);

 stackPush_CMockExpect(229, tempAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(230, &opeStack, ((void *)0));

 stackPush_CMockExpect(231, token4, &opeStack);





 getToken_CMockExpectAndReturn(234, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(235, token5, 1);

 stackPush_CMockExpect(236, token5, &numStack);

 getToken_CMockExpectAndReturn(237, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(240, &opeStack, token4);

 stackPop_CMockExpectAndReturn(241, &numStack, token5);

 stackPop_CMockExpectAndReturn(242, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(243, 10, finalAnsToken);

 stackPush_CMockExpect(244, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(245, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(247, &numStack, finalAnsToken);



 destroyStack_CMockExpect(249, &numStack);

 destroyStack_CMockExpect(250, &opeStack);



 check=evaluate("2*3+4");

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);

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







 createStack_CMockExpectAndReturn(304, &numStack);

 createStack_CMockExpectAndReturn(305, &opeStack);

 stringCreate_CMockExpectAndReturn(306, "2+3*4+5*6", &tokenizer);





 getToken_CMockExpectAndReturn(309, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(310, token1, 1);

 stackPush_CMockExpect(311, token1, &numStack);





 getToken_CMockExpectAndReturn(314, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(315, token2, 0);

 isOperator_CMockExpectAndReturn(316, token2, 1);

 stackPop_CMockExpectAndReturn(317, &opeStack, ((void *)0));

 stackPush_CMockExpect(318, token2, &opeStack);





 getToken_CMockExpectAndReturn(321, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(322, token3, 1);

 stackPush_CMockExpect(323, token3, &numStack);





 getToken_CMockExpectAndReturn(326, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(327, token4, 0);

 isOperator_CMockExpectAndReturn(328, token4, 1);

 stackPop_CMockExpectAndReturn(329, &opeStack, token2);

 stackPush_CMockExpect(330, token2, &opeStack);

 stackPush_CMockExpect(331, token4, &opeStack);





 getToken_CMockExpectAndReturn(334, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(335, token5, 1);

 stackPush_CMockExpect(336, token5, &numStack);













 getToken_CMockExpectAndReturn(343, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(344, token6, 0);

 isOperator_CMockExpectAndReturn(345, token6, 1);

 stackPop_CMockExpectAndReturn(346, &opeStack, token4);

 stackPop_CMockExpectAndReturn(347, &numStack, token5);

 stackPop_CMockExpectAndReturn(348, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(349, 12, tempAnsToken1);

 stackPush_CMockExpect(350, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(351, &opeStack, token2);

 stackPop_CMockExpectAndReturn(352, &numStack, tempAnsToken1);

 stackPop_CMockExpectAndReturn(353, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(354, 14, tempAnsToken2);

 stackPush_CMockExpect(355, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(356, &opeStack, ((void *)0));

 stackPush_CMockExpect(357, token6, &opeStack);





 getToken_CMockExpectAndReturn(360, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(361, token7, 1);

 stackPush_CMockExpect(362, token7, &numStack);





 getToken_CMockExpectAndReturn(365, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(366, token8, 0);

 isOperator_CMockExpectAndReturn(367, token8, 1);

 stackPop_CMockExpectAndReturn(368, &opeStack, token6);

 stackPush_CMockExpect(369, token6, &opeStack);

 stackPush_CMockExpect(370, token8, &opeStack);





 getToken_CMockExpectAndReturn(373, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(374, token9, 1);

 stackPush_CMockExpect(375, token9, &numStack);

 getToken_CMockExpectAndReturn(376, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(379, &opeStack, token8);

 stackPop_CMockExpectAndReturn(380, &numStack, token9);

 stackPop_CMockExpectAndReturn(381, &numStack, token7);

 createNumberToken_CMockExpectAndReturn(382, 30, tempAnsToken3);

 stackPush_CMockExpect(383, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(384, &opeStack, token6);

 stackPop_CMockExpectAndReturn(385, &numStack, tempAnsToken3);

 stackPop_CMockExpectAndReturn(386, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(387, 44, finalAnsToken);

 stackPush_CMockExpect(388, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(389, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(391, &numStack, finalAnsToken);



 destroyStack_CMockExpect(393, &numStack);

 destroyStack_CMockExpect(394, &opeStack);



 check=evaluate("2+3*4+5*6");

 UnityAssertEqualNumber((_U_SINT)((44)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_INT);

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





 createStack_CMockExpectAndReturn(446, &numStack);

 createStack_CMockExpectAndReturn(447, &opeStack);

 stringCreate_CMockExpectAndReturn(448, "2*3+4*5+6", &tokenizer);





 getToken_CMockExpectAndReturn(451, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(452, token1, 1);

 stackPush_CMockExpect(453, token1, &numStack);





 getToken_CMockExpectAndReturn(456, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(457, token2, 0);

 isOperator_CMockExpectAndReturn(458, token2, 1);

 stackPop_CMockExpectAndReturn(459, &opeStack, ((void *)0));

 stackPush_CMockExpect(460, token2, &opeStack);





 getToken_CMockExpectAndReturn(463, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(464, token3, 1);

 stackPush_CMockExpect(465, token3, &numStack);





 getToken_CMockExpectAndReturn(468, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(469, token4, 0);

 isOperator_CMockExpectAndReturn(470, token4, 1);

 stackPop_CMockExpectAndReturn(471, &opeStack, token2);

 stackPop_CMockExpectAndReturn(472, &numStack, token3);

 stackPop_CMockExpectAndReturn(473, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(474, 6, tempAnsToken1);

 stackPush_CMockExpect(475, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(476, &opeStack, ((void *)0));

 stackPush_CMockExpect(477, token4, &opeStack);





 getToken_CMockExpectAndReturn(480, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(481, token5, 1);

 stackPush_CMockExpect(482, token5, &numStack);





 getToken_CMockExpectAndReturn(485, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(486, token6, 0);

 isOperator_CMockExpectAndReturn(487, token6, 1);

 stackPop_CMockExpectAndReturn(488, &opeStack, token4);

 stackPush_CMockExpect(489, token4, &opeStack);

 stackPush_CMockExpect(490, token6, &opeStack);





 getToken_CMockExpectAndReturn(493, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(494, token7, 1);

 stackPush_CMockExpect(495, token7, &numStack);





 getToken_CMockExpectAndReturn(498, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(499, token8, 0);

 isOperator_CMockExpectAndReturn(500, token8, 1);

 stackPop_CMockExpectAndReturn(501, &opeStack, token6);

 stackPop_CMockExpectAndReturn(502, &numStack, token7);

 stackPop_CMockExpectAndReturn(503, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(504, 20, tempAnsToken2);

 stackPush_CMockExpect(505, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(506, &opeStack, token4);

 stackPop_CMockExpectAndReturn(507, &numStack, tempAnsToken2);

 stackPop_CMockExpectAndReturn(508, &numStack, tempAnsToken1);

 createNumberToken_CMockExpectAndReturn(509, 26, tempAnsToken3);

 stackPush_CMockExpect(510, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(511, &opeStack, ((void *)0));

 stackPush_CMockExpect(512, token8, &opeStack);





 getToken_CMockExpectAndReturn(515, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(516, token9, 1);

 stackPush_CMockExpect(517, token9, &numStack);

 getToken_CMockExpectAndReturn(518, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(521, &opeStack, token8);

 stackPop_CMockExpectAndReturn(522, &numStack, token9);

 stackPop_CMockExpectAndReturn(523, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(524, 32, finalAnsToken);

 stackPush_CMockExpect(525, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(526, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(528, &numStack, finalAnsToken);

 destroyStack_CMockExpect(529, &numStack);

 destroyStack_CMockExpect(530, &opeStack);



 check=evaluate("2*3+4*5+6");

 UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)533, UNITY_DISPLAY_STYLE_INT);

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





 createStack_CMockExpectAndReturn(592, &numStack);

 createStack_CMockExpectAndReturn(593, &opeStack);

 stringCreate_CMockExpectAndReturn(594, "2|3+4*5-6-10", &tokenizer);





 getToken_CMockExpectAndReturn(597, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(598, token1, 1);

 stackPush_CMockExpect(599, token1, &numStack);





 getToken_CMockExpectAndReturn(602, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(603, token2, 0);

 isOperator_CMockExpectAndReturn(604, token2, 1);

 stackPop_CMockExpectAndReturn(605, &opeStack, ((void *)0));

 stackPush_CMockExpect(606, token2, &opeStack);





 getToken_CMockExpectAndReturn(609, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(610, token3, 1);

 stackPush_CMockExpect(611, token3, &numStack);





 getToken_CMockExpectAndReturn(614, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(615, token4, 0);

 isOperator_CMockExpectAndReturn(616, token4, 1);

 stackPop_CMockExpectAndReturn(617, &opeStack, token2);

 stackPush_CMockExpect(618, token2, &opeStack);

 stackPush_CMockExpect(619, token4, &opeStack);





 getToken_CMockExpectAndReturn(622, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(623, token5, 1);

 stackPush_CMockExpect(624, token5, &numStack);





 getToken_CMockExpectAndReturn(627, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(628, token6, 0);

 isOperator_CMockExpectAndReturn(629, token6, 1);

 stackPop_CMockExpectAndReturn(630, &opeStack, token4);

 stackPush_CMockExpect(631, token4, &opeStack);

 stackPush_CMockExpect(632, token6, &opeStack);





 getToken_CMockExpectAndReturn(635, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(636, token7, 1);

 stackPush_CMockExpect(637, token7, &numStack);





 getToken_CMockExpectAndReturn(640, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(641, token8, 0);

 isOperator_CMockExpectAndReturn(642, token8, 1);

 stackPop_CMockExpectAndReturn(643, &opeStack, token6);

 stackPop_CMockExpectAndReturn(644, &numStack, token7);

 stackPop_CMockExpectAndReturn(645, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(646, 20, tempAnsToken1);

 stackPush_CMockExpect(647, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(648, &opeStack, token4);

 stackPop_CMockExpectAndReturn(649, &numStack, tempAnsToken1);

 stackPop_CMockExpectAndReturn(650, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(651, 23, tempAnsToken2);

 stackPush_CMockExpect(652, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(653, &opeStack, token2);

 stackPush_CMockExpect(654, token2, &opeStack);

 stackPush_CMockExpect(655, token8, &opeStack);





 getToken_CMockExpectAndReturn(658, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(659, token9, 1);

 stackPush_CMockExpect(660, token9, &numStack);





 getToken_CMockExpectAndReturn(663, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(664, token10, 0);

 isOperator_CMockExpectAndReturn(665, token10, 1);

 stackPop_CMockExpectAndReturn(666, &opeStack, token8);

 stackPop_CMockExpectAndReturn(667, &numStack, token9);

 stackPop_CMockExpectAndReturn(668, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(669, 17, tempAnsToken3);

 stackPush_CMockExpect(670, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(671, &opeStack, token2);

 stackPush_CMockExpect(672, token2, &opeStack);

 stackPush_CMockExpect(673, token10, &opeStack);





 getToken_CMockExpectAndReturn(676, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(677, token11, 1);

 stackPush_CMockExpect(678, token11, &numStack);

 getToken_CMockExpectAndReturn(679, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(682, &opeStack, token10);

 stackPop_CMockExpectAndReturn(683, &numStack, token11);

 stackPop_CMockExpectAndReturn(684, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(685, 7, tempAnsToken4);

 stackPush_CMockExpect(686, tempAnsToken4, &numStack);

 stackPop_CMockExpectAndReturn(687, &opeStack, token2);

 stackPop_CMockExpectAndReturn(688, &numStack, tempAnsToken4);

 stackPop_CMockExpectAndReturn(689, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(690, 7, finalAnsToken);

 stackPush_CMockExpect(691, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(692, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(694, &numStack, finalAnsToken);

 destroyStack_CMockExpect(695, &numStack);

 destroyStack_CMockExpect(696, &opeStack);



 check=evaluate("2|3+4*5-6-10");

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)699, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(721, &dataStack);

 createStack_CMockExpectAndReturn(722, &operatorStack);

 stringCreate_CMockExpectAndReturn(723, "43#42", &tokenizer);



 getToken_CMockExpectAndReturn(725, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(726, token1, 1);

 stackPush_CMockExpect(727, token1, &dataStack);



 getToken_CMockExpectAndThrow(729, &tokenizer, UNKNOWN_OPERATOR);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("43#42");

   UnityFail( ("Should throw ERR_INVALID_OPERATOR"), (_U_UINT)733);;

  }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

   UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)735, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(759, &dataStack);

 createStack_CMockExpectAndReturn(760, &operatorStack);

 stringCreate_CMockExpectAndReturn(761, "(2)", &tokenizer);





 getToken_CMockExpectAndReturn(764, &tokenizer, token1);

 isOperator_CMockExpectAndReturn(765, token1, 1);

 stackPop_CMockExpectAndReturn(766, &operatorStack, ((void *)0));

 stackPush_CMockExpect(767, token1, &operatorStack);





 getToken_CMockExpectAndReturn(770, &tokenizer, token2);

 isOperator_CMockExpectAndReturn(771, token2, 0);

 isNumber_CMockExpectAndReturn(772, token2, 1);

 stackPush_CMockExpect(773, token2, &dataStack);





 getToken_CMockExpectAndReturn(776, &tokenizer, token3);

 isOperator_CMockExpectAndReturn(777, token3, 1);

 stackPop_CMockExpectAndReturn(778, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(779, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(780, 2, answerToken);

 stackPush_CMockExpect(781, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(782, &operatorStack, ((void *)0));

 stackPush_CMockExpect(783, token3, &operatorStack);

 destroyStack_CMockExpect(784, &operatorStack);

 getToken_CMockExpectAndReturn(785, &tokenizer, ((void *)0));







 stackPop_CMockExpectAndReturn(789, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(790, &dataStack, answerToken);

 destroyStack_CMockExpect(791, &dataStack);



 check=prefixEvaluate("(2)");

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)794, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(819, &dataStack);

 createStack_CMockExpectAndReturn(820, &operatorStack);

 stringCreate_CMockExpectAndReturn(821, "(22)", &tokenizer);





 getToken_CMockExpectAndReturn(824, &tokenizer, token1);

 isOperator_CMockExpectAndReturn(825, token1, 1);

 stackPop_CMockExpectAndReturn(826, &operatorStack, ((void *)0));

 stackPush_CMockExpect(827, token1, &operatorStack);





 getToken_CMockExpectAndReturn(830, &tokenizer, token2);

 isOperator_CMockExpectAndReturn(831, token2, 0);

 isNumber_CMockExpectAndReturn(832, token2, 1);

 stackPush_CMockExpect(833, token2, &dataStack);





 getToken_CMockExpectAndReturn(836, &tokenizer, token3);

 isOperator_CMockExpectAndReturn(837, token3, 1);

 stackPop_CMockExpectAndReturn(838, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(839, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(840, 22, answerToken);

 stackPush_CMockExpect(841, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(842, &operatorStack, ((void *)0));

 stackPush_CMockExpect(843, token3, &operatorStack);

 destroyStack_CMockExpect(844, &operatorStack);

 getToken_CMockExpectAndReturn(845, &tokenizer, ((void *)0));







 stackPop_CMockExpectAndReturn(849, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(850, &dataStack, answerToken);

 destroyStack_CMockExpect(851, &dataStack);



 check=prefixEvaluate("(22)");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)854, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left__left_parenthesis_22_right_right_parenthesis(void){

 Stack dataStack;

 Stack operatorStack;

 int check;

 int e;



 String tokenizer = {.rawString = "((22))", .startIndex = 0, .length = 3};



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};

 Token *token1 = (Token*)&leftBracket;



 Operator leftBracket2 = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};

 Token *token2 = (Token*)&leftBracket2;



 Number number22 = {.type= NUMBER, .value=22};

 Token *token3 = (Token*)&number22;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};

 Token *token4 = (Token*)&rightBracket;



 Operator rightBracket2 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};

 Token *token5 = (Token*)&rightBracket2;



 Number answer = {.type= NUMBER, .value=22};

 Token *answerToken = (Token*)&answer;



 createStack_CMockExpectAndReturn(885, &dataStack);

 createStack_CMockExpectAndReturn(886, &operatorStack);

 stringCreate_CMockExpectAndReturn(887, "((22))", &tokenizer);





 getToken_CMockExpectAndReturn(890, &tokenizer, token1);

 isOperator_CMockExpectAndReturn(891, token1, 1);

 stackPop_CMockExpectAndReturn(892, &operatorStack, ((void *)0));

 stackPush_CMockExpect(893, token1, &operatorStack);





 getToken_CMockExpectAndReturn(896, &tokenizer, token2);

 isOperator_CMockExpectAndReturn(897, token1, 1);

 stackPop_CMockExpectAndReturn(898, &operatorStack, token1);

 stackPush_CMockExpect(899, token1, &operatorStack);

 stackPush_CMockExpect(900, token2, &operatorStack);

 destroyStack_CMockExpect(901, &operatorStack);





 getToken_CMockExpectAndReturn(904, &tokenizer, token3);

 isOperator_CMockExpectAndReturn(905, token3, 0);

 isNumber_CMockExpectAndReturn(906, token3, 1);

 stackPush_CMockExpect(907, token3, &dataStack);





 getToken_CMockExpectAndReturn(910, &tokenizer, token4);

 isOperator_CMockExpectAndReturn(911, token4, 1);

 stackPop_CMockExpectAndReturn(912, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(913, &dataStack, token3);

 createNumberToken_CMockExpectAndReturn(914, 22, answerToken);

 stackPush_CMockExpect(915, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(916, &operatorStack, ((void *)0));

 stackPush_CMockExpect(917, token4, &operatorStack);

 destroyStack_CMockExpect(918, &operatorStack);





 getToken_CMockExpectAndReturn(921, &tokenizer, token5);

 isOperator_CMockExpectAndReturn(922, token5, 1);

 stackPop_CMockExpectAndReturn(923, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(924, &dataStack, answerToken);

 createNumberToken_CMockExpectAndReturn(925, 22, answerToken);

 stackPush_CMockExpect(926, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(927, &operatorStack, ((void *)0));

 stackPush_CMockExpect(928, token5, &operatorStack);

 destroyStack_CMockExpect(929, &operatorStack);

 getToken_CMockExpectAndReturn(930, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(933, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(934, &dataStack, answerToken);

 destroyStack_CMockExpect(935, &dataStack);



 check=prefixEvaluate("((22))");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)938, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}

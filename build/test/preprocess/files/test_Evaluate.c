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





 createStack_CMockExpectAndReturn(591, &numStack);

 createStack_CMockExpectAndReturn(592, &opeStack);

 stringCreate_CMockExpectAndReturn(593, "2|3+4*5-6-10", &tokenizer);





 getToken_CMockExpectAndReturn(596, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(597, token1, 1);

 stackPush_CMockExpect(598, token1, &numStack);





 getToken_CMockExpectAndReturn(601, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(602, token2, 0);

 isOperator_CMockExpectAndReturn(603, token2, 1);

 stackPop_CMockExpectAndReturn(604, &opeStack, ((void *)0));

 stackPush_CMockExpect(605, token2, &opeStack);





 getToken_CMockExpectAndReturn(608, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(609, token3, 1);

 stackPush_CMockExpect(610, token3, &numStack);





 getToken_CMockExpectAndReturn(613, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(614, token4, 0);

 isOperator_CMockExpectAndReturn(615, token4, 1);

 stackPop_CMockExpectAndReturn(616, &opeStack, token2);

 stackPush_CMockExpect(617, token2, &opeStack);

 stackPush_CMockExpect(618, token4, &opeStack);





 getToken_CMockExpectAndReturn(621, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(622, token5, 1);

 stackPush_CMockExpect(623, token5, &numStack);





 getToken_CMockExpectAndReturn(626, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(627, token6, 0);

 isOperator_CMockExpectAndReturn(628, token6, 1);

 stackPop_CMockExpectAndReturn(629, &opeStack, token4);

 stackPush_CMockExpect(630, token4, &opeStack);

 stackPush_CMockExpect(631, token6, &opeStack);





 getToken_CMockExpectAndReturn(634, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(635, token7, 1);

 stackPush_CMockExpect(636, token7, &numStack);





 getToken_CMockExpectAndReturn(639, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(640, token8, 0);

 isOperator_CMockExpectAndReturn(641, token8, 1);

 stackPop_CMockExpectAndReturn(642, &opeStack, token6);

 stackPop_CMockExpectAndReturn(643, &numStack, token7);

 stackPop_CMockExpectAndReturn(644, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(645, 20, tempAnsToken1);

 stackPush_CMockExpect(646, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(647, &opeStack, token4);

 stackPop_CMockExpectAndReturn(648, &numStack, tempAnsToken1);

 stackPop_CMockExpectAndReturn(649, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(650, 23, tempAnsToken2);

 stackPush_CMockExpect(651, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(652, &opeStack, token2);

 stackPush_CMockExpect(653, token2, &opeStack);

 stackPush_CMockExpect(654, token8, &opeStack);





 getToken_CMockExpectAndReturn(657, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(658, token9, 1);

 stackPush_CMockExpect(659, token9, &numStack);





 getToken_CMockExpectAndReturn(662, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(663, token10, 0);

 isOperator_CMockExpectAndReturn(664, token10, 1);

 stackPop_CMockExpectAndReturn(665, &opeStack, token8);

 stackPop_CMockExpectAndReturn(666, &numStack, token9);

 stackPop_CMockExpectAndReturn(667, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(668, 17, tempAnsToken3);

 stackPush_CMockExpect(669, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(670, &opeStack, token2);

 stackPush_CMockExpect(671, token2, &opeStack);

 stackPush_CMockExpect(672, token10, &opeStack);





 getToken_CMockExpectAndReturn(675, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(676, token11, 1);

 stackPush_CMockExpect(677, token11, &numStack);

 getToken_CMockExpectAndReturn(678, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(681, &opeStack, token10);

 stackPop_CMockExpectAndReturn(682, &numStack, token11);

 stackPop_CMockExpectAndReturn(683, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(684, 7, tempAnsToken4);

 stackPush_CMockExpect(685, tempAnsToken4, &numStack);

 stackPop_CMockExpectAndReturn(686, &opeStack, token2);

 stackPop_CMockExpectAndReturn(687, &numStack, tempAnsToken4);

 stackPop_CMockExpectAndReturn(688, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(689, 7, finalAnsToken);

 stackPush_CMockExpect(690, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(691, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(693, &numStack, finalAnsToken);

 destroyStack_CMockExpect(694, &numStack);

 destroyStack_CMockExpect(695, &opeStack);



 check=evaluate("2|3+4*5-6-10");

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)698, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(720, &dataStack);

 createStack_CMockExpectAndReturn(721, &operatorStack);

 stringCreate_CMockExpectAndReturn(722, "43#42", &tokenizer);



 getToken_CMockExpectAndReturn(724, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(725, token1, 1);

 stackPush_CMockExpect(726, token1, &dataStack);



 getToken_CMockExpectAndThrow(728, &tokenizer, UNKNOWN_OPERATOR);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("43#42");

   UnityFail( ("Should throw ERR_INVALID_OPERATOR"), (_U_UINT)732);;

  }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

   UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)734, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(758, &dataStack);

 createStack_CMockExpectAndReturn(759, &operatorStack);

 stringCreate_CMockExpectAndReturn(760, "(2)", &tokenizer);





 getToken_CMockExpectAndReturn(763, &tokenizer, token1);

 isOperator_CMockExpectAndReturn(764, token1, 1);

 stackPop_CMockExpectAndReturn(765, &operatorStack, ((void *)0));

 stackPush_CMockExpect(766, token1, &operatorStack);





 getToken_CMockExpectAndReturn(769, &tokenizer, token2);

 isOperator_CMockExpectAndReturn(770, token2, 0);

 isNumber_CMockExpectAndReturn(771, token2, 1);

 stackPush_CMockExpect(772, token2, &dataStack);





 getToken_CMockExpectAndReturn(775, &tokenizer, token3);

 isOperator_CMockExpectAndReturn(776, token3, 1);

 stackPop_CMockExpectAndReturn(777, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(778, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(779, 2, answerToken);

 stackPush_CMockExpect(780, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(781, &operatorStack, ((void *)0));

 stackPush_CMockExpect(782, token3, &operatorStack);

 destroyStack_CMockExpect(783, &operatorStack);

 getToken_CMockExpectAndReturn(784, &tokenizer, ((void *)0));







 stackPop_CMockExpectAndReturn(788, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(789, &dataStack, answerToken);

 destroyStack_CMockExpect(790, &dataStack);



 check=prefixEvaluate("(2)");

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)793, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(818, &dataStack);

 createStack_CMockExpectAndReturn(819, &operatorStack);

 stringCreate_CMockExpectAndReturn(820, "(22)", &tokenizer);





 getToken_CMockExpectAndReturn(823, &tokenizer, token1);

 isOperator_CMockExpectAndReturn(824, token1, 1);

 stackPop_CMockExpectAndReturn(825, &operatorStack, ((void *)0));

 stackPush_CMockExpect(826, token1, &operatorStack);





 getToken_CMockExpectAndReturn(829, &tokenizer, token2);

 isOperator_CMockExpectAndReturn(830, token2, 0);

 isNumber_CMockExpectAndReturn(831, token2, 1);

 stackPush_CMockExpect(832, token2, &dataStack);





 getToken_CMockExpectAndReturn(835, &tokenizer, token3);

 isOperator_CMockExpectAndReturn(836, token3, 1);

 stackPop_CMockExpectAndReturn(837, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(838, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(839, 22, answerToken);

 stackPush_CMockExpect(840, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(841, &operatorStack, ((void *)0));

 stackPush_CMockExpect(842, token3, &operatorStack);

 destroyStack_CMockExpect(843, &operatorStack);

 getToken_CMockExpectAndReturn(844, &tokenizer, ((void *)0));







 stackPop_CMockExpectAndReturn(848, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(849, &dataStack, answerToken);

 destroyStack_CMockExpect(850, &dataStack);



 check=prefixEvaluate("(22)");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)853, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(884, &dataStack);

 createStack_CMockExpectAndReturn(885, &operatorStack);

 stringCreate_CMockExpectAndReturn(886, "((22))", &tokenizer);





 getToken_CMockExpectAndReturn(889, &tokenizer, token1);

 isOperator_CMockExpectAndReturn(890, token1, 1);

 stackPop_CMockExpectAndReturn(891, &operatorStack, ((void *)0));

 stackPush_CMockExpect(892, token1, &operatorStack);





 getToken_CMockExpectAndReturn(895, &tokenizer, token2);

 isOperator_CMockExpectAndReturn(896, token1, 1);

 stackPop_CMockExpectAndReturn(897, &operatorStack, token1);

 stackPush_CMockExpect(898, token1, &operatorStack);

 stackPush_CMockExpect(899, token2, &operatorStack);

 destroyStack_CMockExpect(900, &operatorStack);





 getToken_CMockExpectAndReturn(903, &tokenizer, token3);

 isOperator_CMockExpectAndReturn(904, token3, 0);

 isNumber_CMockExpectAndReturn(905, token3, 1);

 stackPush_CMockExpect(906, token3, &dataStack);





 getToken_CMockExpectAndReturn(909, &tokenizer, token4);

 isOperator_CMockExpectAndReturn(910, token4, 1);

 stackPop_CMockExpectAndReturn(911, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(912, &dataStack, token3);

 createNumberToken_CMockExpectAndReturn(913, 22, answerToken);

 stackPush_CMockExpect(914, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(915, &operatorStack, ((void *)0));

 stackPush_CMockExpect(916, token4, &operatorStack);

 destroyStack_CMockExpect(917, &operatorStack);





 getToken_CMockExpectAndReturn(920, &tokenizer, token5);

 isOperator_CMockExpectAndReturn(921, token5, 1);

 stackPop_CMockExpectAndReturn(922, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(923, &dataStack, answerToken);

 createNumberToken_CMockExpectAndReturn(924, 22, answerToken);

 stackPush_CMockExpect(925, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(926, &operatorStack, ((void *)0));

 stackPush_CMockExpect(927, token5, &operatorStack);

 destroyStack_CMockExpect(928, &operatorStack);

 getToken_CMockExpectAndReturn(929, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(932, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(933, &dataStack, answerToken);

 destroyStack_CMockExpect(934, &dataStack);



 check=prefixEvaluate("((22))");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)937, UNITY_DISPLAY_STYLE_INT);

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



 Number number0 = {.type= NUMBER, .value=0};

 Token *token3 = (Token*)&number0;



 Number answer = {.type=NUMBER, .value=-2};

 Token *ansToken = (Token*)&answer;





 createStack_CMockExpectAndReturn(1051, &numStack);

 createStack_CMockExpectAndReturn(1052, &opeStack);

 stringCreate_CMockExpectAndReturn(1053, "-2", &tokenizer);





 getToken_CMockExpectAndReturn(1056, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1057, token1, 0);

 isOperator_CMockExpectAndReturn(1058, token1, 1);

 stackPop_CMockExpectAndReturn(1059, &opeStack, ((void *)0));

 stackPush_CMockExpect(1060, token1, &opeStack);





 getToken_CMockExpectAndReturn(1063, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1064, token2, 1);

 stackPush_CMockExpect(1065, token2, &numStack);

 getToken_CMockExpectAndReturn(1066, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(1069, &opeStack, token1);

 stackPop_CMockExpectAndReturn(1070, &numStack, token2);

 stackPop_CMockExpectAndReturn(1071, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(1072, -2, ansToken);

 stackPush_CMockExpect(1073, ansToken, &numStack);

 stackPop_CMockExpectAndReturn(1074, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(1076, &numStack, ansToken);

 destroyStack_CMockExpect(1077, &numStack);

 destroyStack_CMockExpect(1078, &opeStack);



 check=evaluate("-2");

 UnityAssertEqualNumber((_U_SINT)((-2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1081, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}

void test_NEGATIVE_2_NEGATIVE_3_SHOULD_RETURN_NEGATIVE_5(void){



 Stack numStack;

 Stack opeStack;

 int check;





 String tokenizer = {.rawString = "-2*3", .startIndex = 0, .length = 4 };



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT, .precedence=60};

 Token *token1 = (Token*)&subtract;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY, .precedence=70};

 Token *token3 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token4 = (Token*)&number3;



 Number number0 = {.type= NUMBER, .value=0};

 Token *token5 = (Token*)&number0;



 Number tempAnswer = {.type=NUMBER, .value=6};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number answer = {.type=NUMBER, .value=-6};

 Token *ansToken = (Token*)&answer;





 createStack_CMockExpectAndReturn(1116, &numStack);

 createStack_CMockExpectAndReturn(1117, &opeStack);

 stringCreate_CMockExpectAndReturn(1118, "-2*3", &tokenizer);





 getToken_CMockExpectAndReturn(1121, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1122, token1, 0);

 isOperator_CMockExpectAndReturn(1123, token1, 1);

 stackPop_CMockExpectAndReturn(1124, &opeStack, ((void *)0));

 stackPush_CMockExpect(1125, token1, &opeStack);





 getToken_CMockExpectAndReturn(1128, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1129, token2, 1);

 stackPush_CMockExpect(1130, token2, &numStack);





 getToken_CMockExpectAndReturn(1133, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1134, token3, 0);

 isOperator_CMockExpectAndReturn(1135, token3, 1);

 stackPop_CMockExpectAndReturn(1136, &opeStack, token1);

 stackPush_CMockExpect(1137, token1, &opeStack);

 stackPush_CMockExpect(1138, token3, &opeStack);





 getToken_CMockExpectAndReturn(1141, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1142, token4, 1);

 stackPush_CMockExpect(1143, token4, &numStack);

 getToken_CMockExpectAndReturn(1144, &tokenizer, ((void *)0));







 stackPop_CMockExpectAndReturn(1148, &opeStack, token3);

 stackPop_CMockExpectAndReturn(1149, &numStack, token4);

 stackPop_CMockExpectAndReturn(1150, &numStack, token2);

 createNumberToken_CMockExpectAndReturn(1151, 6, tempAnsToken);

 stackPush_CMockExpect(1152, tempAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(1153, &opeStack, token1);

 stackPop_CMockExpectAndReturn(1154, &numStack, tempAnsToken);

 stackPop_CMockExpectAndReturn(1155, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(1156, -6, ansToken);

 stackPush_CMockExpect(1157, ansToken, &numStack);

 stackPop_CMockExpectAndReturn(1158, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(1160, &numStack, ansToken);

 destroyStack_CMockExpect(1161, &numStack);

 destroyStack_CMockExpect(1162, &opeStack);



 check=evaluate("-2*3");

 UnityAssertEqualNumber((_U_SINT)((-6)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1165, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}

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



 createStack_CMockExpectAndReturn(79, &dataStack);

 createStack_CMockExpectAndReturn(80, &operatorStack);

 stringCreate_CMockExpectAndReturn(81, "1+2", &tokenizer);



 getToken_CMockExpectAndReturn(83, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(84, token1, 1);

 stackPush_CMockExpect(85, token1, &dataStack);





 getToken_CMockExpectAndReturn(88, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(89, token2, 0);

 isOperator_CMockExpectAndReturn(90, token2, 1);

 stackPop_CMockExpectAndReturn(91, &operatorStack, ((void *)0));

 stackPush_CMockExpect(92, token2, &operatorStack);





 getToken_CMockExpectAndReturn(95, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(96, token3, 1);

 stackPush_CMockExpect(97, token3, &dataStack);

 getToken_CMockExpectAndReturn(98, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(101, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(102, &dataStack, token3);

 stackPop_CMockExpectAndReturn(103, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(104, 3, answerToken);

 stackPush_CMockExpect(105, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(106, &operatorStack, ((void *)0));



 stackPop_CMockExpectAndReturn(108, &dataStack, answerToken);

 destroyStack_CMockExpect(109, &dataStack);

 destroyStack_CMockExpect(110, &operatorStack);

 check=evaluate("1+2");

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(135, &dataStack);

 createStack_CMockExpectAndReturn(136, &operatorStack);

 stringCreate_CMockExpectAndReturn(137, "60/10", &tokenizer);



 getToken_CMockExpectAndReturn(139, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(140, token1, 1);

 stackPush_CMockExpect(141, token1, &dataStack);





 getToken_CMockExpectAndReturn(144, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(145, token2, 0);

 isOperator_CMockExpectAndReturn(146, token2, 1);

 stackPop_CMockExpectAndReturn(147, &operatorStack, ((void *)0));

 stackPush_CMockExpect(148, token2, &operatorStack);





 getToken_CMockExpectAndReturn(151, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(152, token3, 1);

 stackPush_CMockExpect(153, token3, &dataStack);

 getToken_CMockExpectAndReturn(154, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(157, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(158, &dataStack, token3);

 stackPop_CMockExpectAndReturn(159, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(160, 6, answerToken);

 stackPush_CMockExpect(161, answerToken, &dataStack);

 stackPop_CMockExpectAndReturn(162, &operatorStack, ((void *)0));



 stackPop_CMockExpectAndReturn(164, &dataStack, answerToken);

 destroyStack_CMockExpect(165, &dataStack);

 destroyStack_CMockExpect(166, &operatorStack);



 check=evaluate("60/10");

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

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





 createStack_CMockExpectAndReturn(201, &numStack);

 createStack_CMockExpectAndReturn(202, &opeStack);

 stringCreate_CMockExpectAndReturn(203, "2*3+4", &tokenizer);





 getToken_CMockExpectAndReturn(206, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(207, token1, 1);

 stackPush_CMockExpect(208, token1, &numStack);





 getToken_CMockExpectAndReturn(211, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(212, token2, 0);

 isOperator_CMockExpectAndReturn(213, token2, 1);

 stackPop_CMockExpectAndReturn(214, &opeStack, ((void *)0));

 stackPush_CMockExpect(215, token2, &opeStack);





 getToken_CMockExpectAndReturn(218, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(219, token3, 1);

 stackPush_CMockExpect(220, token3, &numStack);





 getToken_CMockExpectAndReturn(223, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(224, token4, 0);

 isOperator_CMockExpectAndReturn(225, token4, 1);

 stackPop_CMockExpectAndReturn(226, &opeStack, token2);

 stackPop_CMockExpectAndReturn(227, &numStack, token3);

 stackPop_CMockExpectAndReturn(228, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(229, 6, tempAnsToken);

 stackPush_CMockExpect(230, tempAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(231, &opeStack, ((void *)0));

 stackPush_CMockExpect(232, token4, &opeStack);





 getToken_CMockExpectAndReturn(235, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(236, token5, 1);

 stackPush_CMockExpect(237, token5, &numStack);

 getToken_CMockExpectAndReturn(238, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(241, &opeStack, token4);

 stackPop_CMockExpectAndReturn(242, &numStack, token5);

 stackPop_CMockExpectAndReturn(243, &numStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(244, 10, finalAnsToken);

 stackPush_CMockExpect(245, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(246, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(248, &numStack, finalAnsToken);



 destroyStack_CMockExpect(250, &numStack);

 destroyStack_CMockExpect(251, &opeStack);



 check=evaluate("2*3+4");

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT);

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







 createStack_CMockExpectAndReturn(305, &numStack);

 createStack_CMockExpectAndReturn(306, &opeStack);

 stringCreate_CMockExpectAndReturn(307, "2+3*4+5*6", &tokenizer);





 getToken_CMockExpectAndReturn(310, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(311, token1, 1);

 stackPush_CMockExpect(312, token1, &numStack);





 getToken_CMockExpectAndReturn(315, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(316, token2, 0);

 isOperator_CMockExpectAndReturn(317, token2, 1);

 stackPop_CMockExpectAndReturn(318, &opeStack, ((void *)0));

 stackPush_CMockExpect(319, token2, &opeStack);





 getToken_CMockExpectAndReturn(322, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(323, token3, 1);

 stackPush_CMockExpect(324, token3, &numStack);





 getToken_CMockExpectAndReturn(327, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(328, token4, 0);

 isOperator_CMockExpectAndReturn(329, token4, 1);

 stackPop_CMockExpectAndReturn(330, &opeStack, token2);

 stackPush_CMockExpect(331, token2, &opeStack);

 stackPush_CMockExpect(332, token4, &opeStack);





 getToken_CMockExpectAndReturn(335, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(336, token5, 1);

 stackPush_CMockExpect(337, token5, &numStack);













 getToken_CMockExpectAndReturn(344, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(345, token6, 0);

 isOperator_CMockExpectAndReturn(346, token6, 1);

 stackPop_CMockExpectAndReturn(347, &opeStack, token4);

 stackPop_CMockExpectAndReturn(348, &numStack, token5);

 stackPop_CMockExpectAndReturn(349, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(350, 12, tempAnsToken1);

 stackPush_CMockExpect(351, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(352, &opeStack, token2);

 stackPop_CMockExpectAndReturn(353, &numStack, tempAnsToken1);

 stackPop_CMockExpectAndReturn(354, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(355, 14, tempAnsToken2);

 stackPush_CMockExpect(356, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(357, &opeStack, ((void *)0));

 stackPush_CMockExpect(358, token6, &opeStack);





 getToken_CMockExpectAndReturn(361, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(362, token7, 1);

 stackPush_CMockExpect(363, token7, &numStack);





 getToken_CMockExpectAndReturn(366, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(367, token8, 0);

 isOperator_CMockExpectAndReturn(368, token8, 1);

 stackPop_CMockExpectAndReturn(369, &opeStack, token6);

 stackPush_CMockExpect(370, token6, &opeStack);

 stackPush_CMockExpect(371, token8, &opeStack);





 getToken_CMockExpectAndReturn(374, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(375, token9, 1);

 stackPush_CMockExpect(376, token9, &numStack);

 getToken_CMockExpectAndReturn(377, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(380, &opeStack, token8);

 stackPop_CMockExpectAndReturn(381, &numStack, token9);

 stackPop_CMockExpectAndReturn(382, &numStack, token7);

 createNumberToken_CMockExpectAndReturn(383, 30, tempAnsToken3);

 stackPush_CMockExpect(384, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(385, &opeStack, token6);

 stackPop_CMockExpectAndReturn(386, &numStack, tempAnsToken3);

 stackPop_CMockExpectAndReturn(387, &numStack, tempAnsToken2);

 createNumberToken_CMockExpectAndReturn(388, 44, finalAnsToken);

 stackPush_CMockExpect(389, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(390, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(392, &numStack, finalAnsToken);



 destroyStack_CMockExpect(394, &numStack);

 destroyStack_CMockExpect(395, &opeStack);



 check=evaluate("2+3*4+5*6");

 UnityAssertEqualNumber((_U_SINT)((44)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)398, UNITY_DISPLAY_STYLE_INT);

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





 createStack_CMockExpectAndReturn(447, &numStack);

 createStack_CMockExpectAndReturn(448, &opeStack);

 stringCreate_CMockExpectAndReturn(449, "2*3+4*5+6", &tokenizer);





 getToken_CMockExpectAndReturn(452, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(453, token1, 1);

 stackPush_CMockExpect(454, token1, &numStack);





 getToken_CMockExpectAndReturn(457, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(458, token2, 0);

 isOperator_CMockExpectAndReturn(459, token2, 1);

 stackPop_CMockExpectAndReturn(460, &opeStack, ((void *)0));

 stackPush_CMockExpect(461, token2, &opeStack);





 getToken_CMockExpectAndReturn(464, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(465, token3, 1);

 stackPush_CMockExpect(466, token3, &numStack);





 getToken_CMockExpectAndReturn(469, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(470, token4, 0);

 isOperator_CMockExpectAndReturn(471, token4, 1);

 stackPop_CMockExpectAndReturn(472, &opeStack, token2);

 stackPop_CMockExpectAndReturn(473, &numStack, token3);

 stackPop_CMockExpectAndReturn(474, &numStack, token1);

 createNumberToken_CMockExpectAndReturn(475, 6, tempAnsToken1);

 stackPush_CMockExpect(476, tempAnsToken1, &numStack);

 stackPop_CMockExpectAndReturn(477, &opeStack, ((void *)0));

 stackPush_CMockExpect(478, token4, &opeStack);





 getToken_CMockExpectAndReturn(481, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(482, token5, 1);

 stackPush_CMockExpect(483, token5, &numStack);





 getToken_CMockExpectAndReturn(486, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(487, token6, 0);

 isOperator_CMockExpectAndReturn(488, token6, 1);

 stackPop_CMockExpectAndReturn(489, &opeStack, token4);

 stackPush_CMockExpect(490, token4, &opeStack);

 stackPush_CMockExpect(491, token6, &opeStack);





 getToken_CMockExpectAndReturn(494, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(495, token7, 1);

 stackPush_CMockExpect(496, token7, &numStack);





 getToken_CMockExpectAndReturn(499, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(500, token8, 0);

 isOperator_CMockExpectAndReturn(501, token8, 1);

 stackPop_CMockExpectAndReturn(502, &opeStack, token6);

 stackPop_CMockExpectAndReturn(503, &numStack, token7);

 stackPop_CMockExpectAndReturn(504, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(505, 20, tempAnsToken2);

 stackPush_CMockExpect(506, tempAnsToken2, &numStack);

 stackPop_CMockExpectAndReturn(507, &opeStack, token4);

 stackPop_CMockExpectAndReturn(508, &numStack, tempAnsToken2);

 stackPop_CMockExpectAndReturn(509, &numStack, tempAnsToken1);

 createNumberToken_CMockExpectAndReturn(510, 26, tempAnsToken3);

 stackPush_CMockExpect(511, tempAnsToken3, &numStack);

 stackPop_CMockExpectAndReturn(512, &opeStack, ((void *)0));

 stackPush_CMockExpect(513, token8, &opeStack);





 getToken_CMockExpectAndReturn(516, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(517, token9, 1);

 stackPush_CMockExpect(518, token9, &numStack);

 getToken_CMockExpectAndReturn(519, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(522, &opeStack, token8);

 stackPop_CMockExpectAndReturn(523, &numStack, token9);

 stackPop_CMockExpectAndReturn(524, &numStack, tempAnsToken3);

 createNumberToken_CMockExpectAndReturn(525, 32, finalAnsToken);

 stackPush_CMockExpect(526, finalAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(527, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(529, &numStack, finalAnsToken);

 destroyStack_CMockExpect(530, &numStack);

 destroyStack_CMockExpect(531, &opeStack);



 check=evaluate("2*3+4*5+6");

 UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)534, UNITY_DISPLAY_STYLE_INT);

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

 isNumber_CMockExpectAndReturn(765, token1, 0);

 isOperator_CMockExpectAndReturn(766, token1, 1);

 stackPop_CMockExpectAndReturn(767, &operatorStack, ((void *)0));

 stackPush_CMockExpect(768, token1, &operatorStack);





 getToken_CMockExpectAndReturn(771, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(772, token2, 1);

 stackPush_CMockExpect(773, token2, &dataStack);





 getToken_CMockExpectAndReturn(776, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(777, token3, 0);

 isOperator_CMockExpectAndReturn(778, token3, 1);

 stackPop_CMockExpectAndReturn(779, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(780, &operatorStack, ((void *)0));

 getToken_CMockExpectAndReturn(781, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(784, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(785, &dataStack, answerToken);

 destroyStack_CMockExpect(786, &dataStack);

 destroyStack_CMockExpect(787, &operatorStack);



 check=evaluate("(2)");

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)790, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(815, &dataStack);

 createStack_CMockExpectAndReturn(816, &operatorStack);

 stringCreate_CMockExpectAndReturn(817, "(22)", &tokenizer);





 getToken_CMockExpectAndReturn(820, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(821, token1, 0);

 isOperator_CMockExpectAndReturn(822, token1, 1);

 stackPop_CMockExpectAndReturn(823, &operatorStack, ((void *)0));

 stackPush_CMockExpect(824, token1, &operatorStack);





 getToken_CMockExpectAndReturn(827, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(828, token2, 1);

 stackPush_CMockExpect(829, token2, &dataStack);





 getToken_CMockExpectAndReturn(832, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(833, token3, 0);

 isOperator_CMockExpectAndReturn(834, token3, 1);

 stackPop_CMockExpectAndReturn(835, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(836, &operatorStack, ((void *)0));

 getToken_CMockExpectAndReturn(837, &tokenizer, ((void *)0));







 stackPop_CMockExpectAndReturn(841, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(842, &dataStack, answerToken);

 destroyStack_CMockExpect(843, &dataStack);

 destroyStack_CMockExpect(844, &operatorStack);



 check=evaluate("(22)");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)847, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(878, &dataStack);

 createStack_CMockExpectAndReturn(879, &operatorStack);

 stringCreate_CMockExpectAndReturn(880, "((22))", &tokenizer);





 getToken_CMockExpectAndReturn(883, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(884, token1, 0);

 isOperator_CMockExpectAndReturn(885, token1, 1);

 stackPop_CMockExpectAndReturn(886, &operatorStack, ((void *)0));

 stackPush_CMockExpect(887, token1, &operatorStack);





 getToken_CMockExpectAndReturn(890, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(891, token1, 0);

 isOperator_CMockExpectAndReturn(892, token1, 1);

 stackPop_CMockExpectAndReturn(893, &operatorStack, token1);

 stackPush_CMockExpect(894, token1, &operatorStack);

 stackPush_CMockExpect(895, token2, &operatorStack);





 getToken_CMockExpectAndReturn(898, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(899, token3, 1);

 stackPush_CMockExpect(900, token3, &dataStack);





 getToken_CMockExpectAndReturn(903, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(904, token4, 0);

 isOperator_CMockExpectAndReturn(905, token4, 1);

 stackPop_CMockExpectAndReturn(906, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(907, &operatorStack, ((void *)0));





 getToken_CMockExpectAndReturn(910, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(911, token5, 0);

 isOperator_CMockExpectAndReturn(912, token5, 1);

 stackPop_CMockExpectAndReturn(913, &operatorStack, token1);

 stackPop_CMockExpectAndReturn(914, &operatorStack, ((void *)0));

 getToken_CMockExpectAndReturn(915, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(918, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(919, &dataStack, answerToken);

 destroyStack_CMockExpect(920, &dataStack);

 destroyStack_CMockExpect(921, &operatorStack);



 check=evaluate("((22))");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)924, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(954, &dataStack);

 createStack_CMockExpectAndReturn(955, &operatorStack);

 stringCreate_CMockExpectAndReturn(956, "(2+3)", &tokenizer);



 getToken_CMockExpectAndReturn(958, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(959, token1, 0);

 isOperator_CMockExpectAndReturn(960, token1, 1);

 stackPop_CMockExpectAndReturn(961, &operatorStack, ((void *)0));

 stackPush_CMockExpect(962, token1, &operatorStack);



 getToken_CMockExpectAndReturn(964, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(965, token2, 1);

 stackPush_CMockExpect(966, token2, &dataStack);



 getToken_CMockExpectAndReturn(968, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(969, token3, 0);

 isOperator_CMockExpectAndReturn(970, token3, 1);

 stackPop_CMockExpectAndReturn(971, &operatorStack, token1);

 stackPush_CMockExpect(972, token1, &operatorStack);

 stackPush_CMockExpect(973, token3, &operatorStack);



 getToken_CMockExpectAndReturn(975, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(976, token4, 1);

 stackPush_CMockExpect(977, token4, &dataStack);



 getToken_CMockExpectAndReturn(979, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(980, token5, 0);

 isOperator_CMockExpectAndReturn(981, token5, 1);

 stackPop_CMockExpectAndReturn(982, &operatorStack, token3);

 stackPop_CMockExpectAndReturn(983, &dataStack, token4);

 stackPop_CMockExpectAndReturn(984, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(985, 5, ansToken);

 stackPush_CMockExpect(986, ansToken, &dataStack);

 stackPop_CMockExpectAndReturn(987, &operatorStack, ((void *)0));

 getToken_CMockExpectAndReturn(988, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(991, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(992, &dataStack, ansToken);

 destroyStack_CMockExpect(993, &dataStack);

 destroyStack_CMockExpect(994, &operatorStack);



 check=evaluate("(2+3)");

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)997, UNITY_DISPLAY_STYLE_INT);

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



 createStack_CMockExpectAndReturn(1035, &dataStack);

 createStack_CMockExpectAndReturn(1036, &operatorStack);

 stringCreate_CMockExpectAndReturn(1037, "(20*3-50)", &tokenizer);



 getToken_CMockExpectAndReturn(1039, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1040, token1, 0);

 isOperator_CMockExpectAndReturn(1041, token1, 1);

 stackPop_CMockExpectAndReturn(1042, &operatorStack, ((void *)0));

 stackPush_CMockExpect(1043, token1, &operatorStack);



 getToken_CMockExpectAndReturn(1045, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1046, token2, 1);

 stackPush_CMockExpect(1047, token2, &dataStack);



 getToken_CMockExpectAndReturn(1049, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1050, token3, 0);

 isOperator_CMockExpectAndReturn(1051, token3, 1);

 stackPop_CMockExpectAndReturn(1052, &operatorStack, token1);

 stackPush_CMockExpect(1053, token1, &operatorStack);

 stackPush_CMockExpect(1054, token3, &operatorStack);



 getToken_CMockExpectAndReturn(1056, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1057, token4, 1);

 stackPush_CMockExpect(1058, token4, &dataStack);



 getToken_CMockExpectAndReturn(1060, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1061, token5, 0);

 isOperator_CMockExpectAndReturn(1062, token5, 1);

 stackPop_CMockExpectAndReturn(1063, &operatorStack, token3);

 stackPop_CMockExpectAndReturn(1064, &dataStack, token4);

 stackPop_CMockExpectAndReturn(1065, &dataStack, token2);

 createNumberToken_CMockExpectAndReturn(1066, 60, tempAnsToken);

 stackPush_CMockExpect(1067, tempAnsToken, &dataStack);

 stackPop_CMockExpectAndReturn(1068, &operatorStack, token1);

 stackPush_CMockExpect(1069, token1, &operatorStack);

 stackPush_CMockExpect(1070, token5, &operatorStack);



 getToken_CMockExpectAndReturn(1072, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(1073, token6, 1);

 stackPush_CMockExpect(1074, token6, &dataStack);



 getToken_CMockExpectAndReturn(1076, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(1077, token7, 0);

 isOperator_CMockExpectAndReturn(1078, token7, 1);

 stackPop_CMockExpectAndReturn(1079, &operatorStack, token5);

 stackPop_CMockExpectAndReturn(1080, &dataStack, token6);

 stackPop_CMockExpectAndReturn(1081, &dataStack, tempAnsToken);

 createNumberToken_CMockExpectAndReturn(1082, 10, ansToken);

 stackPush_CMockExpect(1083, ansToken, &dataStack);

 stackPop_CMockExpectAndReturn(1084, &operatorStack, ((void *)0));

 getToken_CMockExpectAndReturn(1085, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(1088, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(1089, &dataStack, ansToken);

 destroyStack_CMockExpect(1090, &dataStack);

 destroyStack_CMockExpect(1091, &operatorStack);



 check=evaluate("(20*3-50)");

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1094, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_left_left_left_bracket_20_multiply_3_subtract_50_right_right_right_bracket(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 String tokenizer = {.rawString = "(((20+60/4)))", .startIndex = 0, .length = 11};



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};

 Token *token1 = (Token*)&leftBracket;



 Operator leftBracket2 = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};

 Token *token2 = (Token*)&leftBracket2;



 Operator leftBracket3 = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};

 Token *token3 = (Token*)&leftBracket3;



 Number number20 = {.type= NUMBER, .value=20};

 Token *token4 = (Token*)&number20;



 Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=60};

 Token *token5 = (Token*)&plus;



 Number number60 = {.type= NUMBER, .value=60};

 Token *token6 = (Token*)&number60;



 Operator divide = {.type= OPERATOR, .id = DIVIDE ,.precedence=70};

 Token *token7 = (Token*)&divide;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token8 = (Token*)&number4;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};

 Token *token9 = (Token*)&rightBracket;



 Operator rightBracket2 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};

 Token *token10 = (Token*)&rightBracket2;



 Operator rightBracket3 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};

 Token *token11 = (Token*)&rightBracket3;



 Number tempAnswer = {.type= NUMBER, .value=15};

 Token *tempAnsToken = (Token*)&tempAnswer;



 Number answer = {.type= NUMBER, .value=35};

 Token *ansToken = (Token*)&answer;



 createStack_CMockExpectAndReturn(1144, &dataStack);

 createStack_CMockExpectAndReturn(1145, &operatorStack);

 stringCreate_CMockExpectAndReturn(1146, "(((20+60/4)))", &tokenizer);



 getToken_CMockExpectAndReturn(1148, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1149, token1, 0);

 isOperator_CMockExpectAndReturn(1150, token1, 1);

 stackPop_CMockExpectAndReturn(1151, &operatorStack, ((void *)0));

 stackPush_CMockExpect(1152, token1, &operatorStack);



 getToken_CMockExpectAndReturn(1154, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1155, token2, 0);

 isOperator_CMockExpectAndReturn(1156, token2, 1);

 stackPop_CMockExpectAndReturn(1157, &operatorStack, token1);

 stackPush_CMockExpect(1158, token1, &operatorStack);

 stackPush_CMockExpect(1159, token2, &operatorStack);



 getToken_CMockExpectAndReturn(1161, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1162, token3, 0);

 isOperator_CMockExpectAndReturn(1163, token3, 1);

 stackPop_CMockExpectAndReturn(1164, &operatorStack, token2);

 stackPush_CMockExpect(1165, token2, &operatorStack);

 stackPush_CMockExpect(1166, token3, &operatorStack);



 getToken_CMockExpectAndReturn(1168, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1169, token4, 1);

 stackPush_CMockExpect(1170, token4, &dataStack);



 getToken_CMockExpectAndReturn(1172, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1173, token5, 0);

 isOperator_CMockExpectAndReturn(1174, token5, 1);

 stackPop_CMockExpectAndReturn(1175, &operatorStack, token3);

 stackPush_CMockExpect(1176, token3, &operatorStack);

 stackPush_CMockExpect(1177, token5, &operatorStack);



 getToken_CMockExpectAndReturn(1179, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(1180, token6, 1);

 stackPush_CMockExpect(1181, token6, &dataStack);



 getToken_CMockExpectAndReturn(1183, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(1184, token7, 0);

 isOperator_CMockExpectAndReturn(1185, token7, 1);

 stackPop_CMockExpectAndReturn(1186, &operatorStack, token5);

 stackPush_CMockExpect(1187, token5, &operatorStack);

 stackPush_CMockExpect(1188, token7, &operatorStack);



 getToken_CMockExpectAndReturn(1190, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(1191, token8, 1);

 stackPush_CMockExpect(1192, token8, &dataStack);



 getToken_CMockExpectAndReturn(1194, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(1195, token9, 0);

 stackPop_CMockExpectAndReturn(1208, &operatorStack, ((void *)0));

 stackPop_CMockExpectAndReturn(1209, &dataStack, ansToken);

 destroyStack_CMockExpect(1210, &dataStack);

 destroyStack_CMockExpect(1211, &operatorStack);





 check=evaluate("(((20+60/4)))");

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1215, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}













void xtest_2_MULTIPLY_LEFT_PARENTHESIS_THREE_PLUS_FOUR_RIGHT_PARENTHESIS(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 String tokenizer = {.rawString = "2*(3+4)", .startIndex = 0, .length = 7 };



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token2 = (Token*)&multiply;



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token3 = (Token*)&leftBracket;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token4 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token5 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token6 = (Token*)&number4;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token7 = (Token*)&rightBracket;



 Number answer = {.type=NUMBER, .value=14};

 Token *ansToken = (Token*)&answer;





 createStack_CMockExpectAndReturn(1256, &dataStack);

 createStack_CMockExpectAndReturn(1257, &operatorStack);

 stringCreate_CMockExpectAndReturn(1258, "2*(3+4)", &tokenizer);







 getToken_CMockExpectAndReturn(1262, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1263, token1, 1);

 stackPush_CMockExpect(1264, token1, &dataStack);





 getToken_CMockExpectAndReturn(1267, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1268, token2, 0);

 isOperator_CMockExpectAndReturn(1269, token2, 1);

 stackPop_CMockExpectAndReturn(1270, &operatorStack, ((void *)0));

 stackPush_CMockExpect(1271, token2, &operatorStack);







 getToken_CMockExpectAndReturn(1275, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1276, token3, 0);

 isOperator_CMockExpectAndReturn(1277, token3, 1);

 stackPop_CMockExpectAndReturn(1278, &operatorStack, token2);

 stackPush_CMockExpect(1279, token2, &operatorStack);

 stackPush_CMockExpect(1280, token3, &operatorStack);





 getToken_CMockExpectAndReturn(1283, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1284, token4, 1);

 stackPush_CMockExpect(1285, token4, &dataStack);





 getToken_CMockExpectAndReturn(1288, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1289, token5, 0);

 isOperator_CMockExpectAndReturn(1290, token5, 1);

 stackPop_CMockExpectAndReturn(1291, &operatorStack, token2);

 stackPop_CMockExpectAndReturn(1292, &dataStack, token4);

 stackPop_CMockExpectAndReturn(1293, &dataStack, token1);

 check=evaluate("2*(3+4)");

 UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1311, UNITY_DISPLAY_STYLE_INT);

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





 createStack_CMockExpectAndReturn(1339, &numStack);

 createStack_CMockExpectAndReturn(1340, &opeStack);

 stringCreate_CMockExpectAndReturn(1341, "-2", &tokenizer);





 getToken_CMockExpectAndReturn(1344, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1345, token1, 0);

 isOperator_CMockExpectAndReturn(1346, token1, 1);

 stackPop_CMockExpectAndReturn(1347, &opeStack, ((void *)0));

 stackPush_CMockExpect(1348, token1, &opeStack);





 getToken_CMockExpectAndReturn(1351, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1352, token2, 1);

 stackPush_CMockExpect(1353, token2, &numStack);

 getToken_CMockExpectAndReturn(1354, &tokenizer, ((void *)0));





 stackPop_CMockExpectAndReturn(1357, &opeStack, token1);

 stackPop_CMockExpectAndReturn(1358, &numStack, token2);

 stackPop_CMockExpectAndReturn(1359, &numStack, token3);

 createNumberToken_CMockExpectAndReturn(1360, -2, ansToken);

 stackPush_CMockExpect(1361, ansToken, &numStack);

 stackPop_CMockExpectAndReturn(1362, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(1364, &numStack, ansToken);

 destroyStack_CMockExpect(1365, &numStack);

 destroyStack_CMockExpect(1366, &opeStack);



 check=evaluate("-2");

 UnityAssertEqualNumber((_U_SINT)((-2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1369, UNITY_DISPLAY_STYLE_INT);

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





 createStack_CMockExpectAndReturn(1405, &numStack);

 createStack_CMockExpectAndReturn(1406, &opeStack);

 stringCreate_CMockExpectAndReturn(1407, "-2*3", &tokenizer);





 getToken_CMockExpectAndReturn(1410, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1411, token1, 0);

 isOperator_CMockExpectAndReturn(1412, token1, 1);

 stackPop_CMockExpectAndReturn(1413, &opeStack, ((void *)0));

 stackPush_CMockExpect(1414, token1, &opeStack);





 getToken_CMockExpectAndReturn(1417, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1418, token2, 1);

 stackPush_CMockExpect(1419, token2, &numStack);





 getToken_CMockExpectAndReturn(1422, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1423, token3, 0);

 isOperator_CMockExpectAndReturn(1424, token3, 1);

 stackPop_CMockExpectAndReturn(1425, &opeStack, token1);

 stackPush_CMockExpect(1426, token1, &opeStack);

 stackPush_CMockExpect(1427, token3, &opeStack);





 getToken_CMockExpectAndReturn(1430, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1431, token4, 1);

 stackPush_CMockExpect(1432, token4, &numStack);

 getToken_CMockExpectAndReturn(1433, &tokenizer, ((void *)0));







 stackPop_CMockExpectAndReturn(1437, &opeStack, token3);

 stackPop_CMockExpectAndReturn(1438, &numStack, token4);

 stackPop_CMockExpectAndReturn(1439, &numStack, token2);

 createNumberToken_CMockExpectAndReturn(1440, 6, tempAnsToken);

 stackPush_CMockExpect(1441, tempAnsToken, &numStack);

 stackPop_CMockExpectAndReturn(1442, &opeStack, token1);

 stackPop_CMockExpectAndReturn(1443, &numStack, tempAnsToken);

 stackPop_CMockExpectAndReturn(1444, &numStack, token5);

 createNumberToken_CMockExpectAndReturn(1445, -6, ansToken);

 stackPush_CMockExpect(1446, ansToken, &numStack);

 stackPop_CMockExpectAndReturn(1447, &opeStack, ((void *)0));



 stackPop_CMockExpectAndReturn(1449, &numStack, ansToken);

 destroyStack_CMockExpect(1450, &numStack);

 destroyStack_CMockExpect(1451, &opeStack);



 check=evaluate("-2*3");

 UnityAssertEqualNumber((_U_SINT)((-6)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1454, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}

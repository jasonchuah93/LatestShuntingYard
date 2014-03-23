#include "unity.h"
#include "stackForEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_calculateToken.h"
#include "mock_Stack.h"
#include "Evaluate.h"


void setUp(void){}

void tearDown(void){}



void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 Tokenizer tokenizer = {.rawString = "0", .startIndex = 0, .length = 1};



 Number number2 = {.type= NUMBER, .value=0};

 Token *token1 = (Token*)&number2;



 initTokenizer_CMockExpectAndReturn(21, ((void *)0), &tokenizer);



 check=evaluate(((void *)0));

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

}





void test_evaluate_2_PLUS_3(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;







 initTokenizer_CMockExpectAndReturn(44, "2+3", &tokenizer);



 getToken_CMockExpectAndReturn(46, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(47, token1, 1);

 stackPush_CMockExpect(48, token1, &numStack);



 getToken_CMockExpectAndReturn(50, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(51, token2, 0);

 isOperator_CMockExpectAndReturn(52, token2, 1);

 tryEvaluatethenPush_CMockExpect(53, token2, &numStack, &opeStack);

 stackPush_CMockExpect(54, token2, &opeStack);



 getToken_CMockExpectAndReturn(56, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(57, token3, 1);

 stackPush_CMockExpect(58, token3, &numStack);

 getToken_CMockExpectAndReturn(59, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(61, &numStack, &opeStack);

 evaluate("2+3");

}



void test_evaluate_2_PLUS_3_MULTIPLY_4(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2+3*4", .startIndex = 0, .length = 5};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Number answer = {.type=NUMBER, .value=14};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(89, "2+3*4", &tokenizer);



 getToken_CMockExpectAndReturn(91, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(92, token1, 1);

 stackPush_CMockExpect(93, token1, &numStack);



 getToken_CMockExpectAndReturn(95, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(96, token2, 0);

 isOperator_CMockExpectAndReturn(97, token2, 1);

 tryEvaluatethenPush_CMockExpect(98, token2, &numStack, &opeStack);

 stackPush_CMockExpect(99, token2, &opeStack);



 getToken_CMockExpectAndReturn(101, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(102, token3, 1);

 stackPush_CMockExpect(103, token3, &numStack);



 getToken_CMockExpectAndReturn(105, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(106, token4, 0);

 isOperator_CMockExpectAndReturn(107, token4, 1);

 tryEvaluatethenPush_CMockExpect(108, token4, &numStack, &opeStack);

 stackPush_CMockExpect(109, token4, &opeStack);



 getToken_CMockExpectAndReturn(111, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(112, token5, 1);

 stackPush_CMockExpect(113, token5, &numStack);

 getToken_CMockExpectAndReturn(114, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(116, &numStack, &opeStack);





 evaluate("2+3*4");

}



void test_evaluate_2_MULTIPLY_3_PLUS_4(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token2 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Number answer = {.type=NUMBER, .value=10};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(146, "2*3+4", &tokenizer);



 getToken_CMockExpectAndReturn(148, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(149, token1, 1);

 stackPush_CMockExpect(150, token1, &numStack);



 getToken_CMockExpectAndReturn(152, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(153, token2, 0);

 isOperator_CMockExpectAndReturn(154, token2, 1);

 tryEvaluatethenPush_CMockExpect(155, token2, &numStack, &opeStack);

 stackPush_CMockExpect(156, token2, &opeStack);



 getToken_CMockExpectAndReturn(158, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(159, token3, 1);

 stackPush_CMockExpect(160, token3, &numStack);



 getToken_CMockExpectAndReturn(162, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(163, token4, 0);

 isOperator_CMockExpectAndReturn(164, token4, 1);

 tryEvaluatethenPush_CMockExpect(165, token4, &numStack, &opeStack);

 stackPush_CMockExpect(166, token4, &opeStack);



 getToken_CMockExpectAndReturn(168, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(169, token5, 1);

 stackPush_CMockExpect(170, token5, &numStack);

 getToken_CMockExpectAndReturn(171, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(173, &numStack, &opeStack);





 evaluate("2*3+4");

}



void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token4 = (Token*)&multiply;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Operator plus1 = {.type= OPERATOR, .id = ADD};

 Token *token6 = (Token*)&plus1;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token7 = (Token*)&number5;



 Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};

 Token *token8 = (Token*)&multiply1;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token9 = (Token*)&number6;



 Number answer = {.type=NUMBER, .value=44};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(215, "2+3*4+5*6", &tokenizer);



 getToken_CMockExpectAndReturn(217, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(218, token1, 1);

 stackPush_CMockExpect(219, token1, &numStack);



 getToken_CMockExpectAndReturn(221, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(222, token2, 0);

 isOperator_CMockExpectAndReturn(223, token2, 1);

 tryEvaluatethenPush_CMockExpect(224, token2, &numStack, &opeStack);

 stackPush_CMockExpect(225, token2, &opeStack);



 getToken_CMockExpectAndReturn(227, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(228, token3, 1);

 stackPush_CMockExpect(229, token3, &numStack);



 getToken_CMockExpectAndReturn(231, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(232, token4, 0);

 isOperator_CMockExpectAndReturn(233, token4, 1);

 tryEvaluatethenPush_CMockExpect(234, token4, &numStack, &opeStack);

 stackPush_CMockExpect(235, token4, &opeStack);



 getToken_CMockExpectAndReturn(237, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(238, token5, 1);

 stackPush_CMockExpect(239, token5, &numStack);



 getToken_CMockExpectAndReturn(241, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(242, token6, 0);

 isOperator_CMockExpectAndReturn(243, token6, 1);

 tryEvaluatethenPush_CMockExpect(244, token6, &numStack, &opeStack);

 stackPush_CMockExpect(245, token6, &opeStack);



 getToken_CMockExpectAndReturn(247, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(248, token7, 1);

 stackPush_CMockExpect(249, token7, &numStack);



 getToken_CMockExpectAndReturn(251, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(252, token8, 0);

 isOperator_CMockExpectAndReturn(253, token8, 1);

 tryEvaluatethenPush_CMockExpect(254, token8, &numStack, &opeStack);

 stackPush_CMockExpect(255, token8, &opeStack);



 getToken_CMockExpectAndReturn(257, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(258, token9, 1);

 stackPush_CMockExpect(259, token9, &numStack);

 getToken_CMockExpectAndReturn(260, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(262, &numStack, &opeStack);





 evaluate("2+3*4+5*6");

}



void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){

 int check;



 Tokenizer tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token2 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};

 Token *token6 = (Token*)&multiply1;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token7 = (Token*)&number5;



 Operator plus1 = {.type= OPERATOR, .id = ADD};

 Token *token8 = (Token*)&plus1;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token9 = (Token*)&number6;



 Number answer = {.type=NUMBER, .value=32};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(304, "2*3+4*5+6", &tokenizer);



 getToken_CMockExpectAndReturn(306, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(307, token1, 1);

 stackPush_CMockExpect(308, token1, &numStack);



 getToken_CMockExpectAndReturn(310, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(311, token2, 0);

 isOperator_CMockExpectAndReturn(312, token2, 1);

 tryEvaluatethenPush_CMockExpect(313, token2, &numStack, &opeStack);

 stackPush_CMockExpect(314, token2, &opeStack);



 getToken_CMockExpectAndReturn(316, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(317, token3, 1);

 stackPush_CMockExpect(318, token3, &numStack);



 getToken_CMockExpectAndReturn(320, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(321, token4, 0);

 isOperator_CMockExpectAndReturn(322, token4, 1);

 tryEvaluatethenPush_CMockExpect(323, token4, &numStack, &opeStack);

 stackPush_CMockExpect(324, token4, &opeStack);



 getToken_CMockExpectAndReturn(326, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(327, token5, 1);

 stackPush_CMockExpect(328, token5, &numStack);



 getToken_CMockExpectAndReturn(330, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(331, token6, 0);

 isOperator_CMockExpectAndReturn(332, token6, 1);

 tryEvaluatethenPush_CMockExpect(333, token6, &numStack, &opeStack);

 stackPush_CMockExpect(334, token6, &opeStack);



 getToken_CMockExpectAndReturn(336, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(337, token7, 1);

 stackPush_CMockExpect(338, token7, &numStack);



 getToken_CMockExpectAndReturn(340, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(341, token8, 0);

 isOperator_CMockExpectAndReturn(342, token8, 1);

 tryEvaluatethenPush_CMockExpect(343, token8, &numStack, &opeStack);

 stackPush_CMockExpect(344, token8, &opeStack);



 getToken_CMockExpectAndReturn(346, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(347, token9, 1);

 stackPush_CMockExpect(348, token9, &numStack);

 getToken_CMockExpectAndReturn(349, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(351, &numStack, &opeStack);



 evaluate("2*3+4*5+6");



}



void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){

 Tokenizer tokenizer = {.rawString = "2|3+4*5-6-10", .startIndex = 0, .length = 11};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator OR = {.type= OPERATOR, .id = BITWISE_OR};

 Token *token2 = (Token*)&OR;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token6 = (Token*)&multiply;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token7 = (Token*)&number5;



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT};

 Token *token8 = (Token*)&subtract;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token9 = (Token*)&number6;



 Operator subtract1 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token10 = (Token*)&subtract1;



 Number number10 = {.type= NUMBER, .value=10};

 Token *token11 = (Token*)&number10;



 Number answer = {.type=NUMBER, .value=7};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(397, "2|3+4*5-6-10", &tokenizer);



 getToken_CMockExpectAndReturn(399, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(400, token1, 1);

 stackPush_CMockExpect(401, token1, &numStack);



 getToken_CMockExpectAndReturn(403, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(404, token2, 0);

 isOperator_CMockExpectAndReturn(405, token2, 1);

 tryEvaluatethenPush_CMockExpect(406, token2, &numStack, &opeStack);

 stackPush_CMockExpect(407, token2, &opeStack);



 getToken_CMockExpectAndReturn(409, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(410, token3, 1);

 stackPush_CMockExpect(411, token3, &numStack);



 getToken_CMockExpectAndReturn(413, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(414, token4, 0);

 isOperator_CMockExpectAndReturn(415, token4, 1);

 tryEvaluatethenPush_CMockExpect(416, token4, &numStack, &opeStack);

 stackPush_CMockExpect(417, token4, &opeStack);



 getToken_CMockExpectAndReturn(419, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(420, token5, 1);

 stackPush_CMockExpect(421, token5, &numStack);



 getToken_CMockExpectAndReturn(423, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(424, token6, 0);

 isOperator_CMockExpectAndReturn(425, token6, 1);

 tryEvaluatethenPush_CMockExpect(426, token6, &numStack, &opeStack);

 stackPush_CMockExpect(427, token6, &opeStack);



 getToken_CMockExpectAndReturn(429, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(430, token7, 1);

 stackPush_CMockExpect(431, token7, &numStack);



 getToken_CMockExpectAndReturn(433, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(434, token8, 0);

 isOperator_CMockExpectAndReturn(435, token8, 1);

 tryEvaluatethenPush_CMockExpect(436, token8, &numStack, &opeStack);

 stackPush_CMockExpect(437, token8, &opeStack);



 getToken_CMockExpectAndReturn(439, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(440, token9, 1);

 stackPush_CMockExpect(441, token9, &numStack);



 getToken_CMockExpectAndReturn(443, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(444, token10, 0);

 isOperator_CMockExpectAndReturn(445, token10, 1);

 tryEvaluatethenPush_CMockExpect(446, token10, &numStack, &opeStack);

 stackPush_CMockExpect(447, token10, &opeStack);



 getToken_CMockExpectAndReturn(449, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(450, token11, 1);

 stackPush_CMockExpect(451, token11, &numStack);

 getToken_CMockExpectAndReturn(452, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(454, &numStack, &opeStack);





 evaluate("2|3+4*5-6-10");



}



void test_LEFT_PARENTHESIS_2_PLUS_3_RIGHT_PARENTHESIS_MULTIPLY_4(void){

 Tokenizer tokenizer = {.rawString = "(2+3)*4", .startIndex = 0, .length = 7 };



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token1 = (Token*)&leftBracket;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token3 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token4 = (Token*)&number3;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token5 = (Token*)&rightBracket;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token6 = (Token*)&multiply;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token7 = (Token*)&number4;



 Number answer = {.type=NUMBER, .value=20};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(489, "(2+3)*4", &tokenizer);



 getToken_CMockExpectAndReturn(491, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(492, token1, 0);

 isOperator_CMockExpectAndReturn(493, token1, 1);

 tryEvaluatethenPush_CMockExpect(494, token1, &numStack, &opeStack);

 stackPush_CMockExpect(495, token1, &opeStack);



 getToken_CMockExpectAndReturn(497, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(498, token2, 1);

 stackPush_CMockExpect(499, token2, &numStack);



 getToken_CMockExpectAndReturn(501, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(502, token3, 0);

 isOperator_CMockExpectAndReturn(503, token3, 1);

 tryEvaluatethenPush_CMockExpect(504, token3, &numStack, &opeStack);

 stackPush_CMockExpect(505, token3, &opeStack);



 getToken_CMockExpectAndReturn(507, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(508, token4, 1);

 stackPush_CMockExpect(509, token4, &numStack);



 getToken_CMockExpectAndReturn(511, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(512, token5, 0);

 isOperator_CMockExpectAndReturn(513, token5, 1);

 tryEvaluatethenPush_CMockExpect(514, token5, &numStack, &opeStack);

 stackPush_CMockExpect(515, token5, &opeStack);



 getToken_CMockExpectAndReturn(517, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(518, token6, 0);

 isOperator_CMockExpectAndReturn(519, token6, 1);

 tryEvaluatethenPush_CMockExpect(520, token6, &numStack, &opeStack);

 stackPush_CMockExpect(521, token6, &opeStack);



 getToken_CMockExpectAndReturn(523, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(524, token7, 1);

 stackPush_CMockExpect(525, token7, &numStack);

 getToken_CMockExpectAndReturn(526, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(528, &numStack, &opeStack);



 evaluate("(2+3)*4");

}



void test_2_MULTIPLY_LEFT_PARENTHESIS_THREE_PLUS_FOUR_RIGHT_PARENTHESIS(void){

 Tokenizer tokenizer = {.rawString = "2*(3+4)", .startIndex = 0, .length = 7 };



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





 initTokenizer_CMockExpectAndReturn(561, "2*(3+4)", &tokenizer);



 getToken_CMockExpectAndReturn(563, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(564, token1, 1);

 stackPush_CMockExpect(565, token1, &numStack);



 getToken_CMockExpectAndReturn(567, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(568, token2, 0);

 isOperator_CMockExpectAndReturn(569, token2, 1);

 tryEvaluatethenPush_CMockExpect(570, token2, &numStack, &opeStack);

 stackPush_CMockExpect(571, token2, &opeStack);



 getToken_CMockExpectAndReturn(573, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(574, token3, 0);

 isOperator_CMockExpectAndReturn(575, token3, 1);

 tryEvaluatethenPush_CMockExpect(576, token3, &numStack, &opeStack);

 stackPush_CMockExpect(577, token3, &opeStack);



 getToken_CMockExpectAndReturn(579, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(580, token4, 1);

 stackPush_CMockExpect(581, token4, &numStack);



 getToken_CMockExpectAndReturn(583, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(584, token5, 0);

 isOperator_CMockExpectAndReturn(585, token5, 1);

 tryEvaluatethenPush_CMockExpect(586, token5, &numStack, &opeStack);

 stackPush_CMockExpect(587, token5, &opeStack);



 getToken_CMockExpectAndReturn(589, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(590, token6, 1);

 stackPush_CMockExpect(591, token6, &numStack);



 getToken_CMockExpectAndReturn(593, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(594, token7, 0);

 isOperator_CMockExpectAndReturn(595, token7, 1);

 tryEvaluatethenPush_CMockExpect(596, token7, &numStack, &opeStack);

 stackPush_CMockExpect(597, token7, &opeStack);

 getToken_CMockExpectAndReturn(598, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(600, &numStack, &opeStack);



 evaluate("2*(3+4)");

}



void test_NEGATIVE_2_SHOULD_RETURN_NEGATIVE_2(void){

 Tokenizer tokenizer = {.rawString = "-2", .startIndex = 0, .length = 2 };



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&subtract;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Number answer = {.type=NUMBER, .value=-2};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(618, "-2", &tokenizer);





 getToken_CMockExpectAndReturn(621, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(622, token1, 0);

 isOperator_CMockExpectAndReturn(623, token1, 1);

 tryEvaluatethenPush_CMockExpect(624, token1, &numStack, &opeStack);

 stackPush_CMockExpect(625, token1, &opeStack);





 getToken_CMockExpectAndReturn(628, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(629, token2, 1);

 stackPush_CMockExpect(630, token2, &numStack);

 getToken_CMockExpectAndReturn(631, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(634, &numStack, &opeStack);





 evaluate("-2");

}



void test_NEGATIVE_2_PLUS_NEGATIVE_3(void){

 Tokenizer tokenizer = {.rawString = "-2+-3", .startIndex = 0, .length = 5 };



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&negative;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token3 = (Token*)&plus;



 Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token4 = (Token*)&negative2;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token5 = (Token*)&number3;



 Number answer = {.type=NUMBER, .value=-5};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(662, "-2+-3", &tokenizer);





 getToken_CMockExpectAndReturn(665, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(666, token1, 0);

 isOperator_CMockExpectAndReturn(667, token1, 1);

 tryEvaluatethenPush_CMockExpect(668, token1, &numStack, &opeStack);

 stackPush_CMockExpect(669, token1, &opeStack);





 getToken_CMockExpectAndReturn(672, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(673, token2, 1);

 stackPush_CMockExpect(674, token2, &numStack);





 getToken_CMockExpectAndReturn(677, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(678, token3, 0);

 isOperator_CMockExpectAndReturn(679, token3, 1);

 tryEvaluatethenPush_CMockExpect(680, token3, &numStack, &opeStack);

 stackPush_CMockExpect(681, token3, &opeStack);





 getToken_CMockExpectAndReturn(684, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(685, token4, 0);

 isOperator_CMockExpectAndReturn(686, token4, 1);

 tryEvaluatethenPush_CMockExpect(687, token4, &numStack, &opeStack);

 stackPush_CMockExpect(688, token4, &opeStack);





 getToken_CMockExpectAndReturn(691, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(692, token5, 1);

 stackPush_CMockExpect(693, token5, &numStack);

 getToken_CMockExpectAndReturn(694, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(697, &numStack, &opeStack);





 evaluate("-2+-3");

}



void test_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_2(void){

 Tokenizer tokenizer = {.rawString = "-----2", .startIndex = 0, .length = 6 };



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&negative;



 Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token2 = (Token*)&negative2;



 Operator negative3 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token3 = (Token*)&negative3;



 Operator negative4 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token4 = (Token*)&negative4;



 Operator negative5 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token5 = (Token*)&negative5;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token6 = (Token*)&number2;



 Number answer = {.type=NUMBER, .value=-2};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(728, "-----2", &tokenizer);





 getToken_CMockExpectAndReturn(731, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(732, token1, 0);

 isOperator_CMockExpectAndReturn(733, token1, 1);

 tryEvaluatethenPush_CMockExpect(734, token1, &numStack, &opeStack);

 stackPush_CMockExpect(735, token1, &opeStack);





 getToken_CMockExpectAndReturn(738, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(739, token2, 0);

 isOperator_CMockExpectAndReturn(740, token2, 1);

 tryEvaluatethenPush_CMockExpect(741, token2, &numStack, &opeStack);

 stackPush_CMockExpect(742, token2, &opeStack);





 getToken_CMockExpectAndReturn(745, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(746, token3, 0);

 isOperator_CMockExpectAndReturn(747, token3, 1);

 tryEvaluatethenPush_CMockExpect(748, token3, &numStack, &opeStack);

 stackPush_CMockExpect(749, token3, &opeStack);





 getToken_CMockExpectAndReturn(752, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(753, token4, 0);

 isOperator_CMockExpectAndReturn(754, token4, 1);

 tryEvaluatethenPush_CMockExpect(755, token4, &numStack, &opeStack);

 stackPush_CMockExpect(756, token4, &opeStack);





 getToken_CMockExpectAndReturn(759, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(760, token5, 0);

 isOperator_CMockExpectAndReturn(761, token5, 1);

 tryEvaluatethenPush_CMockExpect(762, token5, &numStack, &opeStack);

 stackPush_CMockExpect(763, token5, &opeStack);





 getToken_CMockExpectAndReturn(766, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(767, token5, 1);

 stackPush_CMockExpect(768, token5, &numStack);

 getToken_CMockExpectAndReturn(769, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(772, &numStack, &opeStack);





 evaluate("-----2");



}



void test_LEFT_PARENTHESIS_10_MULTIPLY_100_RIGHT_PARENTHESIS_DIVIDE_BY_LEFT_PARENTHESIS_LEFT_PARENTHESIS_NEGATIVE_5_MULTIPLY_6_RIGHT_PARENTHESIS_SUBTRACT_LEFT_PARENTHESIS_2_MINUS_30_RIGHT_PARENTHESIS_RIGHT_PARENTHESIS(void) {

 Tokenizer tokenizer = {.rawString = "(10*100)/((-5*6)-(2-30))", .startIndex = 0, .length = 24 };



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token1 = (Token*)&leftBracket;



 Number number10 = {.type= NUMBER, .value=10};

 Token *token2 = (Token*)&number10;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token3 = (Token*)&multiply;



 Number number100 = {.type= NUMBER, .value=100};

 Token *token4 = (Token*)&number100;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token5 = (Token*)&rightBracket;



 Operator divide = {.type= OPERATOR, .id = DIVIDE};

 Token *token6 = (Token*)&divide;



 Operator leftBracket2 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token7 = (Token*)&leftBracket2;



 Operator leftBracket3 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token8 = (Token*)&leftBracket3;



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token9 = (Token*)&negative;



 Number number5 = {.type= NUMBER, .value=5};

 Token *token10 = (Token*)&number5;



 Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY};

 Token *token11 = (Token*)&multiply1;



 Number number6 = {.type= NUMBER, .value=6};

 Token *token12 = (Token*)&number6;



 Operator rightBracket1 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token13 = (Token*)&rightBracket1;



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT};

 Token *token14 = (Token*)&subtract;



 Operator leftBracket4 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token15 = (Token*)&leftBracket4;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token16 = (Token*)&number2;



 Operator subtract2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token17 = (Token*)&subtract2;



 Number number30 = {.type= NUMBER, .value=30};

 Token *token18 = (Token*)&number30;



 Operator rightBracket2 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token19 = (Token*)&rightBracket2;



 Operator rightBracket3 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token20 = (Token*)&rightBracket3;



 Number answer = {.type=NUMBER, .value=-500};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(846, "(10*100)/((-5*6)-(2-30))", &tokenizer);





 getToken_CMockExpectAndReturn(849, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(850, token1, 0);

 isOperator_CMockExpectAndReturn(851, token1, 1);

 tryEvaluatethenPush_CMockExpect(852, token1, &numStack, &opeStack);

 stackPush_CMockExpect(853, token1, &opeStack);





 getToken_CMockExpectAndReturn(856, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(857, token2, 1);

 stackPush_CMockExpect(858, token2, &numStack);





 getToken_CMockExpectAndReturn(861, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(862, token3, 0);

 isOperator_CMockExpectAndReturn(863, token3, 1);

 tryEvaluatethenPush_CMockExpect(864, token3, &numStack, &opeStack);

 stackPush_CMockExpect(865, token3, &opeStack);





 getToken_CMockExpectAndReturn(868, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(869, token4, 1);

 stackPush_CMockExpect(870, token4, &numStack);





 getToken_CMockExpectAndReturn(873, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(874, token5, 0);

 isOperator_CMockExpectAndReturn(875, token5, 1);

 tryEvaluatethenPush_CMockExpect(876, token5, &numStack, &opeStack);

 stackPush_CMockExpect(877, token5, &opeStack);





 getToken_CMockExpectAndReturn(880, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(881, token6, 0);

 isOperator_CMockExpectAndReturn(882, token6, 1);

 tryEvaluatethenPush_CMockExpect(883, token6, &numStack, &opeStack);

 stackPush_CMockExpect(884, token6, &opeStack);





 getToken_CMockExpectAndReturn(887, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(888, token7, 0);

 isOperator_CMockExpectAndReturn(889, token7, 1);

 tryEvaluatethenPush_CMockExpect(890, token7, &numStack, &opeStack);

 stackPush_CMockExpect(891, token7, &opeStack);





 getToken_CMockExpectAndReturn(894, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(895, token8, 0);

 isOperator_CMockExpectAndReturn(896, token8, 1);

 tryEvaluatethenPush_CMockExpect(897, token8, &numStack, &opeStack);

 stackPush_CMockExpect(898, token8, &opeStack);





 getToken_CMockExpectAndReturn(901, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(902, token9, 0);

 isOperator_CMockExpectAndReturn(903, token9, 1);

 tryEvaluatethenPush_CMockExpect(904, token9, &numStack, &opeStack);

 stackPush_CMockExpect(905, token9, &opeStack);





 getToken_CMockExpectAndReturn(908, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(909, token10, 1);

 stackPush_CMockExpect(910, token10, &numStack);





 getToken_CMockExpectAndReturn(913, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(914, token11, 0);

 isOperator_CMockExpectAndReturn(915, token11, 1);

 tryEvaluatethenPush_CMockExpect(916, token11, &numStack, &opeStack);

 stackPush_CMockExpect(917, token11, &opeStack);





 getToken_CMockExpectAndReturn(920, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(921, token12, 1);

 stackPush_CMockExpect(922, token12, &numStack);





 getToken_CMockExpectAndReturn(925, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(926, token13, 0);

 isOperator_CMockExpectAndReturn(927, token13, 1);

 tryEvaluatethenPush_CMockExpect(928, token13, &numStack, &opeStack);

 stackPush_CMockExpect(929, token13, &opeStack);





 getToken_CMockExpectAndReturn(932, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(933, token14, 0);

 isOperator_CMockExpectAndReturn(934, token14, 1);

 tryEvaluatethenPush_CMockExpect(935, token14, &numStack, &opeStack);

 stackPush_CMockExpect(936, token14, &opeStack);





 getToken_CMockExpectAndReturn(939, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(940, token15, 0);

 isOperator_CMockExpectAndReturn(941, token15, 1);

 tryEvaluatethenPush_CMockExpect(942, token15, &numStack, &opeStack);

 stackPush_CMockExpect(943, token15, &opeStack);





 getToken_CMockExpectAndReturn(946, &tokenizer, token16);

 isNumber_CMockExpectAndReturn(947, token16, 1);

 stackPush_CMockExpect(948, token16, &numStack);





 getToken_CMockExpectAndReturn(951, &tokenizer, token17);

 isNumber_CMockExpectAndReturn(952, token17, 0);

 isOperator_CMockExpectAndReturn(953, token17, 1);

 tryEvaluatethenPush_CMockExpect(954, token17, &numStack, &opeStack);

 stackPush_CMockExpect(955, token17, &opeStack);





 getToken_CMockExpectAndReturn(958, &tokenizer, token18);

 isNumber_CMockExpectAndReturn(959, token18, 1);

 stackPush_CMockExpect(960, token18, &numStack);





 getToken_CMockExpectAndReturn(963, &tokenizer, token19);

 isNumber_CMockExpectAndReturn(964, token19, 0);

 isOperator_CMockExpectAndReturn(965, token19, 1);

 tryEvaluatethenPush_CMockExpect(966, token19, &numStack, &opeStack);

 stackPush_CMockExpect(967, token19, &opeStack);





 getToken_CMockExpectAndReturn(970, &tokenizer, token20);

 isNumber_CMockExpectAndReturn(971, token20, 0);

 isOperator_CMockExpectAndReturn(972, token20, 1);

 tryEvaluatethenPush_CMockExpect(973, token20, &numStack, &opeStack);

 stackPush_CMockExpect(974, token20, &opeStack);

 getToken_CMockExpectAndReturn(975, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(978, &numStack, &opeStack);





 evaluate("(10*100)/((-5*6)-(2-30))");

}



void test_NEGATIVE_LEFT_PARENTHESIS_NEGATIVE_2_RIGHT_PARENTHESIS(void){

 Tokenizer tokenizer = {.rawString = "-(-2)", .startIndex = 0, .length = 5 };



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&negative;



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token2 = (Token*)&leftBracket;



 Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token3 = (Token*)&negative2;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token4 = (Token*)&number2;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token5 = (Token*)&rightBracket;



 Number answer = {.type=NUMBER, .value=2};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(1006, "-(-2)", &tokenizer);





 getToken_CMockExpectAndReturn(1009, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1010, token1, 0);

 isOperator_CMockExpectAndReturn(1011, token1, 1);

 tryEvaluatethenPush_CMockExpect(1012, token1, &numStack, &opeStack);

 stackPush_CMockExpect(1013, token1, &opeStack);





 getToken_CMockExpectAndReturn(1016, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1017, token2, 0);

 isOperator_CMockExpectAndReturn(1018, token2, 1);

 tryEvaluatethenPush_CMockExpect(1019, token2, &numStack, &opeStack);

 stackPush_CMockExpect(1020, token2, &opeStack);





 getToken_CMockExpectAndReturn(1023, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1024, token3, 0);

 isOperator_CMockExpectAndReturn(1025, token3, 1);

 tryEvaluatethenPush_CMockExpect(1026, token3, &numStack, &opeStack);

 stackPush_CMockExpect(1027, token3, &opeStack);





 getToken_CMockExpectAndReturn(1030, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1031, token4, 1);

 stackPush_CMockExpect(1032, token4, &numStack);





 getToken_CMockExpectAndReturn(1035, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1036, token5, 0);

 isOperator_CMockExpectAndReturn(1037, token5, 1);

 tryEvaluatethenPush_CMockExpect(1038, token5, &numStack, &opeStack);

 stackPush_CMockExpect(1039, token5, &opeStack);

 getToken_CMockExpectAndReturn(1040, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1043, &numStack, &opeStack);





 evaluate("-(-2)");





}



void test_NEGATIVE_LEFT_PARENTHESIS_POSITIVE_LEFT_PARENTHESIS_NEGATIVE_LEFT_PARENTHESIS__NEGATIVE_1_RIGHT_PARENTHESIS_MULTIPLY_3_RIGHT_PARENTHESIS_SUBTRACT_FOUR_RIGHT_PARENTHESIS(void){

 Tokenizer tokenizer = {.rawString = "-(+(-(-1)*3)-4)", .startIndex = 0, .length = 15 };



 Operator negative = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&negative;



 Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token2 = (Token*)&leftBracket;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token3 = (Token*)&plus;



 Operator leftBracket2 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token4 = (Token*)&leftBracket2;



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT};

 Token *token5 = (Token*)&subtract;



 Operator leftBracket3 = {.type= OPERATOR, .id = LEFT_PARENTHESIS};

 Token *token6 = (Token*)&leftBracket3;



 Operator negative2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token7 = (Token*)&negative2;



 Number number1 = {.type= NUMBER, .value=1};

 Token *token8 = (Token*)&number1;



 Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token9 = (Token*)&rightBracket;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token10 = (Token*)&multiply;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token11 = (Token*)&number3;



 Operator rightBracket1 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token12 = (Token*)&rightBracket1;



 Operator subtract2 = {.type= OPERATOR, .id = SUBTRACT};

 Token *token13 = (Token*)&subtract2;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token14 = (Token*)&number4;



 Operator rightBracket2 = {.type= OPERATOR, .id = RIGHT_PARENTHESIS};

 Token *token15 = (Token*)&rightBracket2;



 Number answer = {.type=NUMBER, .value=1};

 Token *ansToken = (Token*)&answer;





 initTokenizer_CMockExpectAndReturn(1103, "-(+(-(-1)*3)-4)", &tokenizer);





 getToken_CMockExpectAndReturn(1106, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1107, token1, 0);

 isOperator_CMockExpectAndReturn(1108, token1, 1);

 tryEvaluatethenPush_CMockExpect(1109, token1, &numStack, &opeStack);

 stackPush_CMockExpect(1110, token1, &opeStack);





 getToken_CMockExpectAndReturn(1113, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1114, token2, 0);

 isOperator_CMockExpectAndReturn(1115, token2, 1);

 tryEvaluatethenPush_CMockExpect(1116, token2, &numStack, &opeStack);

 stackPush_CMockExpect(1117, token2, &opeStack);





 getToken_CMockExpectAndReturn(1120, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1121, token3, 0);

 isOperator_CMockExpectAndReturn(1122, token3, 1);

 tryEvaluatethenPush_CMockExpect(1123, token3, &numStack, &opeStack);

 stackPush_CMockExpect(1124, token3, &opeStack);





 getToken_CMockExpectAndReturn(1127, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1128, token4, 0);

 isOperator_CMockExpectAndReturn(1129, token4, 1);

 tryEvaluatethenPush_CMockExpect(1130, token4, &numStack, &opeStack);

 stackPush_CMockExpect(1131, token4, &opeStack);





 getToken_CMockExpectAndReturn(1134, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1135, token5, 0);

 isOperator_CMockExpectAndReturn(1136, token5, 1);

 tryEvaluatethenPush_CMockExpect(1137, token5, &numStack, &opeStack);

 stackPush_CMockExpect(1138, token5, &opeStack);





 getToken_CMockExpectAndReturn(1141, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(1142, token6, 0);

 isOperator_CMockExpectAndReturn(1143, token6, 1);

 tryEvaluatethenPush_CMockExpect(1144, token6, &numStack, &opeStack);

 stackPush_CMockExpect(1145, token6, &opeStack);





 getToken_CMockExpectAndReturn(1148, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(1149, token7, 0);

 isOperator_CMockExpectAndReturn(1150, token7, 1);

 tryEvaluatethenPush_CMockExpect(1151, token7, &numStack, &opeStack);

 stackPush_CMockExpect(1152, token7, &opeStack);





 getToken_CMockExpectAndReturn(1155, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(1156, token8, 1);

 stackPush_CMockExpect(1157, token8, &numStack);





 getToken_CMockExpectAndReturn(1160, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(1161, token9, 0);

 isOperator_CMockExpectAndReturn(1162, token9, 1);

 tryEvaluatethenPush_CMockExpect(1163, token9, &numStack, &opeStack);

 stackPush_CMockExpect(1164, token9, &opeStack);





 getToken_CMockExpectAndReturn(1167, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(1168, token10, 0);

 isOperator_CMockExpectAndReturn(1169, token10, 1);

 tryEvaluatethenPush_CMockExpect(1170, token10, &numStack, &opeStack);

 stackPush_CMockExpect(1171, token10, &opeStack);





 getToken_CMockExpectAndReturn(1174, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(1175, token11, 1);

 stackPush_CMockExpect(1176, token11, &numStack);





 getToken_CMockExpectAndReturn(1179, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(1180, token12, 0);

 isOperator_CMockExpectAndReturn(1181, token12, 1);

 tryEvaluatethenPush_CMockExpect(1182, token12, &numStack, &opeStack);

 stackPush_CMockExpect(1183, token12, &opeStack);





 getToken_CMockExpectAndReturn(1186, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(1187, token13, 0);

 isOperator_CMockExpectAndReturn(1188, token13, 1);

 tryEvaluatethenPush_CMockExpect(1189, token13, &numStack, &opeStack);

 stackPush_CMockExpect(1190, token13, &opeStack);





 getToken_CMockExpectAndReturn(1193, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(1194, token14, 1);

 stackPush_CMockExpect(1195, token14, &numStack);





 getToken_CMockExpectAndReturn(1198, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(1199, token15, 0);

 isOperator_CMockExpectAndReturn(1200, token15, 1);

 tryEvaluatethenPush_CMockExpect(1201, token15, &numStack, &opeStack);

 stackPush_CMockExpect(1202, token15, &opeStack);

 getToken_CMockExpectAndReturn(1203, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1206, &numStack, &opeStack);



 evaluate("-(+(-(-1)*3)-4)");

}

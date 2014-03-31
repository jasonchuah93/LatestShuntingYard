#include "unity.h"
#include "stackForEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_getToken.h"
#include "mock_calculateToken.h"
#include "mock_StringObject.h"
#include "mock_Stack.h"
#include "Evaluate.h"


void setUp(void){}

void tearDown(void){}



void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 String tokenizer = {.rawString = "0", .startIndex = 0, .length = 1};



 Number number2 = {.type= NUMBER, .value=0};

 Token *token1 = (Token*)&number2;



 stringCreate_CMockExpectAndReturn(21, ((void *)0), &tokenizer);



 check=evaluate(((void *)0));

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

}





void test_evaluate_2_PLUS_3(void){

 int check;



 String tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;







 stringCreate_CMockExpectAndReturn(44, "2+3", &tokenizer);





 getToken_CMockExpectAndReturn(47, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(48, token1, 1);

 stackPush_CMockExpect(49, token1, &numStack);





 getToken_CMockExpectAndReturn(52, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(53, token2, 0);

 isOperator_CMockExpectAndReturn(54, token2, 1);

 tryEvaluatethenPush_CMockExpect(55, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(59, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(60, token3, 1);

 stackPush_CMockExpect(61, token3, &numStack);

 getToken_CMockExpectAndReturn(62, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(64, &numStack, &opeStack);

 destroyStack_CMockExpect(65, &numStack);

 evaluate("2+3");

}



void test_evaluate_2_PLUS_3_MULTIPLY_4(void){

 int check;



 String tokenizer = {.rawString = "2+3*4", .startIndex = 0, .length = 5};



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





 stringCreate_CMockExpectAndReturn(93, "2+3*4", &tokenizer);





 getToken_CMockExpectAndReturn(96, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(97, token1, 1);

 stackPush_CMockExpect(98, token1, &numStack);





 getToken_CMockExpectAndReturn(101, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(102, token2, 0);

 isOperator_CMockExpectAndReturn(103, token2, 1);

 tryEvaluatethenPush_CMockExpect(104, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(108, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(109, token3, 1);

 stackPush_CMockExpect(110, token3, &numStack);





 getToken_CMockExpectAndReturn(113, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(114, token4, 0);

 isOperator_CMockExpectAndReturn(115, token4, 1);

 tryEvaluatethenPush_CMockExpect(116, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(120, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(121, token5, 1);

 stackPush_CMockExpect(122, token5, &numStack);

 getToken_CMockExpectAndReturn(123, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(125, &numStack, &opeStack);

 destroyStack_CMockExpect(126, &numStack);

 evaluate("2+3*4");

}





void test_evaluate_2_MULTIPLY_3_PLUS_4(void){

 int check;



 String tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};



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





 stringCreate_CMockExpectAndReturn(155, "2*3+4", &tokenizer);





 getToken_CMockExpectAndReturn(158, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(159, token1, 1);

 stackPush_CMockExpect(160, token1, &numStack);





 getToken_CMockExpectAndReturn(163, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(164, token2, 0);

 isOperator_CMockExpectAndReturn(165, token2, 1);

 tryEvaluatethenPush_CMockExpect(166, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(170, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(171, token3, 1);

 stackPush_CMockExpect(172, token3, &numStack);





 getToken_CMockExpectAndReturn(175, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(176, token4, 0);

 isOperator_CMockExpectAndReturn(177, token4, 1);

 tryEvaluatethenPush_CMockExpect(178, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(182, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(183, token5, 1);

 stackPush_CMockExpect(184, token5, &numStack);

 getToken_CMockExpectAndReturn(185, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(187, &numStack, &opeStack);

 destroyStack_CMockExpect(188, &numStack);

 evaluate("2*3+4");

}



void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){

 int check;



 String tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};



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





 stringCreate_CMockExpectAndReturn(228, "2+3*4+5*6", &tokenizer);





 getToken_CMockExpectAndReturn(231, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(232, token1, 1);

 stackPush_CMockExpect(233, token1, &numStack);





 getToken_CMockExpectAndReturn(236, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(237, token2, 0);

 isOperator_CMockExpectAndReturn(238, token2, 1);

 tryEvaluatethenPush_CMockExpect(239, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(243, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(244, token3, 1);

 stackPush_CMockExpect(245, token3, &numStack);





 getToken_CMockExpectAndReturn(248, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(249, token4, 0);

 isOperator_CMockExpectAndReturn(250, token4, 1);

 tryEvaluatethenPush_CMockExpect(251, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(255, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(256, token5, 1);

 stackPush_CMockExpect(257, token5, &numStack);





 getToken_CMockExpectAndReturn(260, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(261, token6, 0);

 isOperator_CMockExpectAndReturn(262, token6, 1);

 tryEvaluatethenPush_CMockExpect(263, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(267, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(268, token7, 1);

 stackPush_CMockExpect(269, token7, &numStack);





 getToken_CMockExpectAndReturn(272, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(273, token8, 0);

 isOperator_CMockExpectAndReturn(274, token8, 1);

 tryEvaluatethenPush_CMockExpect(275, token8, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(279, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(280, token9, 1);

 stackPush_CMockExpect(281, token9, &numStack);

 getToken_CMockExpectAndReturn(282, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(284, &numStack, &opeStack);

 destroyStack_CMockExpect(285, &numStack);

 evaluate("2+3*4+5*6");

}



void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){

 int check;



 String tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};



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





 stringCreate_CMockExpectAndReturn(325, "2*3+4*5+6", &tokenizer);





 getToken_CMockExpectAndReturn(328, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(329, token1, 1);

 stackPush_CMockExpect(330, token1, &numStack);





 getToken_CMockExpectAndReturn(333, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(334, token2, 0);

 isOperator_CMockExpectAndReturn(335, token2, 1);

 tryEvaluatethenPush_CMockExpect(336, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(340, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(341, token3, 1);

 stackPush_CMockExpect(342, token3, &numStack);





 getToken_CMockExpectAndReturn(345, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(346, token4, 0);

 isOperator_CMockExpectAndReturn(347, token4, 1);

 tryEvaluatethenPush_CMockExpect(348, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(352, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(353, token5, 1);

 stackPush_CMockExpect(354, token5, &numStack);





 getToken_CMockExpectAndReturn(357, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(358, token6, 0);

 isOperator_CMockExpectAndReturn(359, token6, 1);

 tryEvaluatethenPush_CMockExpect(360, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(364, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(365, token7, 1);

 stackPush_CMockExpect(366, token7, &numStack);





 getToken_CMockExpectAndReturn(369, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(370, token8, 0);

 isOperator_CMockExpectAndReturn(371, token8, 1);

 tryEvaluatethenPush_CMockExpect(372, token8, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(376, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(377, token9, 1);

 stackPush_CMockExpect(378, token9, &numStack);

 getToken_CMockExpectAndReturn(379, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(381, &numStack, &opeStack);

 destroyStack_CMockExpect(382, &numStack);

 evaluate("2*3+4*5+6");



}



void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){

 String tokenizer = {.rawString = "2|3+4*5-6-10", .startIndex = 0, .length = 11};



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





 stringCreate_CMockExpectAndReturn(427, "2|3+4*5-6-10", &tokenizer);





 getToken_CMockExpectAndReturn(430, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(431, token1, 1);

 stackPush_CMockExpect(432, token1, &numStack);





 getToken_CMockExpectAndReturn(435, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(436, token2, 0);

 isOperator_CMockExpectAndReturn(437, token2, 1);

 tryEvaluatethenPush_CMockExpect(438, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(442, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(443, token3, 1);

 stackPush_CMockExpect(444, token3, &numStack);





 getToken_CMockExpectAndReturn(447, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(448, token4, 0);

 isOperator_CMockExpectAndReturn(449, token4, 1);

 tryEvaluatethenPush_CMockExpect(450, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(454, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(455, token5, 1);

 stackPush_CMockExpect(456, token5, &numStack);





 getToken_CMockExpectAndReturn(459, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(460, token6, 0);

 isOperator_CMockExpectAndReturn(461, token6, 1);

 tryEvaluatethenPush_CMockExpect(462, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(466, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(467, token7, 1);

 stackPush_CMockExpect(468, token7, &numStack);





 getToken_CMockExpectAndReturn(471, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(472, token8, 0);

 isOperator_CMockExpectAndReturn(473, token8, 1);

 tryEvaluatethenPush_CMockExpect(474, token8, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(478, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(479, token9, 1);

 stackPush_CMockExpect(480, token9, &numStack);





 getToken_CMockExpectAndReturn(483, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(484, token10, 0);

 isOperator_CMockExpectAndReturn(485, token10, 1);

 tryEvaluatethenPush_CMockExpect(486, token10, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(490, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(491, token11, 1);

 stackPush_CMockExpect(492, token11, &numStack);

 getToken_CMockExpectAndReturn(493, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(495, &numStack, &opeStack);

 destroyStack_CMockExpect(496, &numStack);

 evaluate("2|3+4*5-6-10");



}



void test_LEFT_PARENTHESIS_2_PLUS_3_RIGHT_PARENTHESIS_MULTIPLY_4(void){

 String tokenizer = {.rawString = "(2+3)*4", .startIndex = 0, .length = 7 };



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





 stringCreate_CMockExpectAndReturn(529, "(2+3)*4", &tokenizer);





 getToken_CMockExpectAndReturn(532, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(533, token1, 0);

 isOperator_CMockExpectAndReturn(534, token1, 1);

 tryEvaluatethenPush_CMockExpect(535, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(539, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(540, token2, 1);

 stackPush_CMockExpect(541, token2, &numStack);





 getToken_CMockExpectAndReturn(544, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(545, token3, 0);

 isOperator_CMockExpectAndReturn(546, token3, 1);

 tryEvaluatethenPush_CMockExpect(547, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(551, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(552, token4, 1);

 stackPush_CMockExpect(553, token4, &numStack);





 getToken_CMockExpectAndReturn(556, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(557, token5, 0);

 isOperator_CMockExpectAndReturn(558, token5, 1);

 tryEvaluatethenPush_CMockExpect(559, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(563, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(564, token6, 0);

 isOperator_CMockExpectAndReturn(565, token6, 1);

 tryEvaluatethenPush_CMockExpect(566, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(570, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(571, token7, 1);

 stackPush_CMockExpect(572, token7, &numStack);

 getToken_CMockExpectAndReturn(573, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(575, &numStack, &opeStack);

 destroyStack_CMockExpect(576, &numStack);

 evaluate("(2+3)*4");

}



void test_2_MULTIPLY_LEFT_PARENTHESIS_THREE_PLUS_FOUR_RIGHT_PARENTHESIS(void){

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





 stringCreate_CMockExpectAndReturn(608, "2*(3+4)", &tokenizer);





 getToken_CMockExpectAndReturn(611, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(612, token1, 1);

 stackPush_CMockExpect(613, token1, &numStack);





 getToken_CMockExpectAndReturn(616, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(617, token2, 0);

 isOperator_CMockExpectAndReturn(618, token2, 1);

 tryEvaluatethenPush_CMockExpect(619, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(623, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(624, token3, 0);

 isOperator_CMockExpectAndReturn(625, token3, 1);

 tryEvaluatethenPush_CMockExpect(626, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(630, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(631, token4, 1);

 stackPush_CMockExpect(632, token4, &numStack);





 getToken_CMockExpectAndReturn(635, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(636, token5, 0);

 isOperator_CMockExpectAndReturn(637, token5, 1);

 tryEvaluatethenPush_CMockExpect(638, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(642, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(643, token6, 1);

 stackPush_CMockExpect(644, token6, &numStack);





 getToken_CMockExpectAndReturn(647, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(648, token7, 0);

 isOperator_CMockExpectAndReturn(649, token7, 1);

 tryEvaluatethenPush_CMockExpect(650, token7, &numStack, &opeStack);



 getToken_CMockExpectAndReturn(652, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(655, &numStack, &opeStack);

 destroyStack_CMockExpect(656, &numStack);

 evaluate("2*(3+4)");

}



void test_NEGATIVE_2_SHOULD_RETURN_NEGATIVE_2(void){

 String tokenizer = {.rawString = "-2", .startIndex = 0, .length = 2 };



 Operator subtract = {.type= OPERATOR, .id = SUBTRACT};

 Token *token1 = (Token*)&subtract;



 Number number2 = {.type= NUMBER, .value=2};

 Token *token2 = (Token*)&number2;



 Number answer = {.type=NUMBER, .value=-2};

 Token *ansToken = (Token*)&answer;





 stringCreate_CMockExpectAndReturn(673, "-2", &tokenizer);





 getToken_CMockExpectAndReturn(676, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(677, token1, 0);

 isOperator_CMockExpectAndReturn(678, token1, 1);

 tryEvaluatethenPush_CMockExpect(679, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(683, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(684, token2, 1);

 stackPush_CMockExpect(685, token2, &numStack);

 getToken_CMockExpectAndReturn(686, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(689, &numStack, &opeStack);

 destroyStack_CMockExpect(690, &numStack);

 evaluate("-2");

}



void test_NEGATIVE_2_PLUS_NEGATIVE_3(void){

 String tokenizer = {.rawString = "-2+-3", .startIndex = 0, .length = 5 };



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





 stringCreate_CMockExpectAndReturn(716, "-2+-3", &tokenizer);





 getToken_CMockExpectAndReturn(719, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(720, token1, 0);

 isOperator_CMockExpectAndReturn(721, token1, 1);

 tryEvaluatethenPush_CMockExpect(722, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(726, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(727, token2, 1);

 stackPush_CMockExpect(728, token2, &numStack);





 getToken_CMockExpectAndReturn(731, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(732, token3, 0);

 isOperator_CMockExpectAndReturn(733, token3, 1);

 tryEvaluatethenPush_CMockExpect(734, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(738, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(739, token4, 0);

 isOperator_CMockExpectAndReturn(740, token4, 1);

 tryEvaluatethenPush_CMockExpect(741, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(745, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(746, token5, 1);

 stackPush_CMockExpect(747, token5, &numStack);

 getToken_CMockExpectAndReturn(748, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(751, &numStack, &opeStack);

 destroyStack_CMockExpect(752, &numStack);

 evaluate("-2+-3");

}





void test_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_NEGATIVE_2(void){

 String tokenizer = {.rawString = "-----2", .startIndex = 0, .length = 6 };



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





 stringCreate_CMockExpectAndReturn(782, "-----2", &tokenizer);





 getToken_CMockExpectAndReturn(785, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(786, token1, 0);

 isOperator_CMockExpectAndReturn(787, token1, 1);

 tryEvaluatethenPush_CMockExpect(788, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(792, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(793, token2, 0);

 isOperator_CMockExpectAndReturn(794, token2, 1);

 tryEvaluatethenPush_CMockExpect(795, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(799, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(800, token3, 0);

 isOperator_CMockExpectAndReturn(801, token3, 1);

 tryEvaluatethenPush_CMockExpect(802, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(806, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(807, token4, 0);

 isOperator_CMockExpectAndReturn(808, token4, 1);

 tryEvaluatethenPush_CMockExpect(809, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(813, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(814, token5, 0);

 isOperator_CMockExpectAndReturn(815, token5, 1);

 tryEvaluatethenPush_CMockExpect(816, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(820, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(821, token5, 1);

 stackPush_CMockExpect(822, token5, &numStack);

 getToken_CMockExpectAndReturn(823, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(826, &numStack, &opeStack);

 destroyStack_CMockExpect(827, &numStack);

 evaluate("-----2");



}



void test_LEFT_PARENTHESIS_10_MULTIPLY_100_RIGHT_PARENTHESIS_DIVIDE_BY_LEFT_PARENTHESIS_LEFT_PARENTHESIS_NEGATIVE_5_MULTIPLY_6_RIGHT_PARENTHESIS_SUBTRACT_LEFT_PARENTHESIS_2_MINUS_30_RIGHT_PARENTHESIS_RIGHT_PARENTHESIS(void) {

 String tokenizer = {.rawString = "(10*100)/((-5*6)-(2-30))", .startIndex = 0, .length = 24 };



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





 stringCreate_CMockExpectAndReturn(899, "(10*100)/((-5*6)-(2-30))", &tokenizer);





 getToken_CMockExpectAndReturn(902, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(903, token1, 0);

 isOperator_CMockExpectAndReturn(904, token1, 1);

 tryEvaluatethenPush_CMockExpect(905, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(909, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(910, token2, 1);

 stackPush_CMockExpect(911, token2, &numStack);





 getToken_CMockExpectAndReturn(914, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(915, token3, 0);

 isOperator_CMockExpectAndReturn(916, token3, 1);

 tryEvaluatethenPush_CMockExpect(917, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(921, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(922, token4, 1);

 stackPush_CMockExpect(923, token4, &numStack);





 getToken_CMockExpectAndReturn(926, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(927, token5, 0);

 isOperator_CMockExpectAndReturn(928, token5, 1);

 tryEvaluatethenPush_CMockExpect(929, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(933, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(934, token6, 0);

 isOperator_CMockExpectAndReturn(935, token6, 1);

 tryEvaluatethenPush_CMockExpect(936, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(940, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(941, token7, 0);

 isOperator_CMockExpectAndReturn(942, token7, 1);

 tryEvaluatethenPush_CMockExpect(943, token7, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(947, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(948, token8, 0);

 isOperator_CMockExpectAndReturn(949, token8, 1);

 tryEvaluatethenPush_CMockExpect(950, token8, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(954, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(955, token9, 0);

 isOperator_CMockExpectAndReturn(956, token9, 1);

 tryEvaluatethenPush_CMockExpect(957, token9, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(961, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(962, token10, 1);

 stackPush_CMockExpect(963, token10, &numStack);





 getToken_CMockExpectAndReturn(966, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(967, token11, 0);

 isOperator_CMockExpectAndReturn(968, token11, 1);

 tryEvaluatethenPush_CMockExpect(969, token11, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(973, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(974, token12, 1);

 stackPush_CMockExpect(975, token12, &numStack);





 getToken_CMockExpectAndReturn(978, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(979, token13, 0);

 isOperator_CMockExpectAndReturn(980, token13, 1);

 tryEvaluatethenPush_CMockExpect(981, token13, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(985, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(986, token14, 0);

 isOperator_CMockExpectAndReturn(987, token14, 1);

 tryEvaluatethenPush_CMockExpect(988, token14, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(992, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(993, token15, 0);

 isOperator_CMockExpectAndReturn(994, token15, 1);

 tryEvaluatethenPush_CMockExpect(995, token15, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(999, &tokenizer, token16);

 isNumber_CMockExpectAndReturn(1000, token16, 1);

 stackPush_CMockExpect(1001, token16, &numStack);





 getToken_CMockExpectAndReturn(1004, &tokenizer, token17);

 isNumber_CMockExpectAndReturn(1005, token17, 0);

 isOperator_CMockExpectAndReturn(1006, token17, 1);

 tryEvaluatethenPush_CMockExpect(1007, token17, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1011, &tokenizer, token18);

 isNumber_CMockExpectAndReturn(1012, token18, 1);

 stackPush_CMockExpect(1013, token18, &numStack);





 getToken_CMockExpectAndReturn(1016, &tokenizer, token19);

 isNumber_CMockExpectAndReturn(1017, token19, 0);

 isOperator_CMockExpectAndReturn(1018, token19, 1);

 tryEvaluatethenPush_CMockExpect(1019, token19, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1023, &tokenizer, token20);

 isNumber_CMockExpectAndReturn(1024, token20, 0);

 isOperator_CMockExpectAndReturn(1025, token20, 1);

 tryEvaluatethenPush_CMockExpect(1026, token20, &numStack, &opeStack);



 getToken_CMockExpectAndReturn(1028, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1031, &numStack, &opeStack);

 destroyStack_CMockExpect(1032, &numStack);

 evaluate("(10*100)/((-5*6)-(2-30))");

}



void test_NEGATIVE_LEFT_PARENTHESIS_NEGATIVE_2_RIGHT_PARENTHESIS(void){

 String tokenizer = {.rawString = "-(-2)", .startIndex = 0, .length = 5 };



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





 stringCreate_CMockExpectAndReturn(1058, "-(-2)", &tokenizer);





 getToken_CMockExpectAndReturn(1061, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1062, token1, 0);

 isOperator_CMockExpectAndReturn(1063, token1, 1);

 tryEvaluatethenPush_CMockExpect(1064, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1068, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1069, token2, 0);

 isOperator_CMockExpectAndReturn(1070, token2, 1);

 tryEvaluatethenPush_CMockExpect(1071, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1075, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1076, token3, 0);

 isOperator_CMockExpectAndReturn(1077, token3, 1);

 tryEvaluatethenPush_CMockExpect(1078, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1082, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1083, token4, 1);

 stackPush_CMockExpect(1084, token4, &numStack);





 getToken_CMockExpectAndReturn(1087, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1088, token5, 0);

 isOperator_CMockExpectAndReturn(1089, token5, 1);

 tryEvaluatethenPush_CMockExpect(1090, token5, &numStack, &opeStack);



 getToken_CMockExpectAndReturn(1092, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1095, &numStack, &opeStack);

 destroyStack_CMockExpect(1096, &numStack);

 evaluate("-(-2)");

}



void test_NEGATIVE_LEFT_PARENTHESIS_POSITIVE_LEFT_PARENTHESIS_NEGATIVE_LEFT_PARENTHESIS__NEGATIVE_1_RIGHT_PARENTHESIS_MULTIPLY_3_RIGHT_PARENTHESIS_SUBTRACT_FOUR_RIGHT_PARENTHESIS(void){

 String tokenizer = {.rawString = "-(+(-(-1)*3)-4)", .startIndex = 0, .length = 15 };



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





 stringCreate_CMockExpectAndReturn(1152, "-(+(-(-1)*3)-4)", &tokenizer);





 getToken_CMockExpectAndReturn(1155, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1156, token1, 0);

 isOperator_CMockExpectAndReturn(1157, token1, 1);

 tryEvaluatethenPush_CMockExpect(1158, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1162, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1163, token2, 0);

 isOperator_CMockExpectAndReturn(1164, token2, 1);

 tryEvaluatethenPush_CMockExpect(1165, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1169, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1170, token3, 0);

 isOperator_CMockExpectAndReturn(1171, token3, 1);

 tryEvaluatethenPush_CMockExpect(1172, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1176, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1177, token4, 0);

 isOperator_CMockExpectAndReturn(1178, token4, 1);

 tryEvaluatethenPush_CMockExpect(1179, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1183, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1184, token5, 0);

 isOperator_CMockExpectAndReturn(1185, token5, 1);

 tryEvaluatethenPush_CMockExpect(1186, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1190, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(1191, token6, 0);

 isOperator_CMockExpectAndReturn(1192, token6, 1);

 tryEvaluatethenPush_CMockExpect(1193, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1197, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(1198, token7, 0);

 isOperator_CMockExpectAndReturn(1199, token7, 1);

 tryEvaluatethenPush_CMockExpect(1200, token7, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1204, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(1205, token8, 1);

 stackPush_CMockExpect(1206, token8, &numStack);





 getToken_CMockExpectAndReturn(1209, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(1210, token9, 0);

 isOperator_CMockExpectAndReturn(1211, token9, 1);

 tryEvaluatethenPush_CMockExpect(1212, token9, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1216, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(1217, token10, 0);

 isOperator_CMockExpectAndReturn(1218, token10, 1);

 tryEvaluatethenPush_CMockExpect(1219, token10, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1223, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(1224, token11, 1);

 stackPush_CMockExpect(1225, token11, &numStack);





 getToken_CMockExpectAndReturn(1228, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(1229, token12, 0);

 isOperator_CMockExpectAndReturn(1230, token12, 1);

 tryEvaluatethenPush_CMockExpect(1231, token12, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1235, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(1236, token13, 0);

 isOperator_CMockExpectAndReturn(1237, token13, 1);

 tryEvaluatethenPush_CMockExpect(1238, token13, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1242, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(1243, token14, 1);

 stackPush_CMockExpect(1244, token14, &numStack);





 getToken_CMockExpectAndReturn(1247, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(1248, token15, 0);

 isOperator_CMockExpectAndReturn(1249, token15, 1);

 tryEvaluatethenPush_CMockExpect(1250, token15, &numStack, &opeStack);



 getToken_CMockExpectAndReturn(1252, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1255, &numStack, &opeStack);

 destroyStack_CMockExpect(1256, &numStack);

 evaluate("-(+(-(-1)*3)-4)");

}

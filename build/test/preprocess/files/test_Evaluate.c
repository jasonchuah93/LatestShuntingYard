#include "unity.h"
#include "stackForEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_getToken.h"
#include "mock_calculateToken.h"
#include "mock_StringObject.h"
#include "mock_Stack.h"
#include "LinkedList.h"
#include "Evaluate.h"




void setUp(void){}

void tearDown(void){}



void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 String tokenizer = {.rawString = "0", .startIndex = 0, .length = 1};



 Number number2 = {.type= NUMBER, .value=0};

 Token *token1 = (Token*)&number2;



 stringCreate_CMockExpectAndReturn(23, ((void *)0), &tokenizer);



 check=evaluate(((void *)0));

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

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







 stringCreate_CMockExpectAndReturn(46, "2+3", &tokenizer);





 getToken_CMockExpectAndReturn(49, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(50, token1, 1);

 stackPush_CMockExpect(51, token1, &numStack);





 getToken_CMockExpectAndReturn(54, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(55, token2, 0);

 isOperator_CMockExpectAndReturn(56, token2, 1);

 tryEvaluatethenPush_CMockExpect(57, token2, &numStack, &opeStack);





 getToken_CMockExpectAndReturn(60, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(61, token3, 1);

 stackPush_CMockExpect(62, token3, &numStack);

 getToken_CMockExpectAndReturn(63, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(65, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(94, "2+3*4", &tokenizer);





 getToken_CMockExpectAndReturn(97, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(98, token1, 1);

 stackPush_CMockExpect(99, token1, &numStack);





 getToken_CMockExpectAndReturn(102, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(103, token2, 0);

 isOperator_CMockExpectAndReturn(104, token2, 1);

 tryEvaluatethenPush_CMockExpect(105, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(109, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(110, token3, 1);

 stackPush_CMockExpect(111, token3, &numStack);





 getToken_CMockExpectAndReturn(114, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(115, token4, 0);

 isOperator_CMockExpectAndReturn(116, token4, 1);

 tryEvaluatethenPush_CMockExpect(117, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(121, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(122, token5, 1);

 stackPush_CMockExpect(123, token5, &numStack);

 getToken_CMockExpectAndReturn(124, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(126, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(156, "2*3+4", &tokenizer);





 getToken_CMockExpectAndReturn(159, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(160, token1, 1);

 stackPush_CMockExpect(161, token1, &numStack);





 getToken_CMockExpectAndReturn(164, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(165, token2, 0);

 isOperator_CMockExpectAndReturn(166, token2, 1);

 tryEvaluatethenPush_CMockExpect(167, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(171, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(172, token3, 1);

 stackPush_CMockExpect(173, token3, &numStack);





 getToken_CMockExpectAndReturn(176, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(177, token4, 0);

 isOperator_CMockExpectAndReturn(178, token4, 1);

 tryEvaluatethenPush_CMockExpect(179, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(183, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(184, token5, 1);

 stackPush_CMockExpect(185, token5, &numStack);

 getToken_CMockExpectAndReturn(186, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(188, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(229, "2+3*4+5*6", &tokenizer);





 getToken_CMockExpectAndReturn(232, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(233, token1, 1);

 stackPush_CMockExpect(234, token1, &numStack);





 getToken_CMockExpectAndReturn(237, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(238, token2, 0);

 isOperator_CMockExpectAndReturn(239, token2, 1);

 tryEvaluatethenPush_CMockExpect(240, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(244, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(245, token3, 1);

 stackPush_CMockExpect(246, token3, &numStack);





 getToken_CMockExpectAndReturn(249, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(250, token4, 0);

 isOperator_CMockExpectAndReturn(251, token4, 1);

 tryEvaluatethenPush_CMockExpect(252, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(256, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(257, token5, 1);

 stackPush_CMockExpect(258, token5, &numStack);





 getToken_CMockExpectAndReturn(261, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(262, token6, 0);

 isOperator_CMockExpectAndReturn(263, token6, 1);

 tryEvaluatethenPush_CMockExpect(264, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(268, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(269, token7, 1);

 stackPush_CMockExpect(270, token7, &numStack);





 getToken_CMockExpectAndReturn(273, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(274, token8, 0);

 isOperator_CMockExpectAndReturn(275, token8, 1);

 tryEvaluatethenPush_CMockExpect(276, token8, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(280, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(281, token9, 1);

 stackPush_CMockExpect(282, token9, &numStack);

 getToken_CMockExpectAndReturn(283, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(285, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(326, "2*3+4*5+6", &tokenizer);





 getToken_CMockExpectAndReturn(329, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(330, token1, 1);

 stackPush_CMockExpect(331, token1, &numStack);





 getToken_CMockExpectAndReturn(334, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(335, token2, 0);

 isOperator_CMockExpectAndReturn(336, token2, 1);

 tryEvaluatethenPush_CMockExpect(337, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(341, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(342, token3, 1);

 stackPush_CMockExpect(343, token3, &numStack);





 getToken_CMockExpectAndReturn(346, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(347, token4, 0);

 isOperator_CMockExpectAndReturn(348, token4, 1);

 tryEvaluatethenPush_CMockExpect(349, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(353, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(354, token5, 1);

 stackPush_CMockExpect(355, token5, &numStack);





 getToken_CMockExpectAndReturn(358, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(359, token6, 0);

 isOperator_CMockExpectAndReturn(360, token6, 1);

 tryEvaluatethenPush_CMockExpect(361, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(365, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(366, token7, 1);

 stackPush_CMockExpect(367, token7, &numStack);





 getToken_CMockExpectAndReturn(370, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(371, token8, 0);

 isOperator_CMockExpectAndReturn(372, token8, 1);

 tryEvaluatethenPush_CMockExpect(373, token8, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(377, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(378, token9, 1);

 stackPush_CMockExpect(379, token9, &numStack);

 getToken_CMockExpectAndReturn(380, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(382, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(428, "2|3+4*5-6-10", &tokenizer);





 getToken_CMockExpectAndReturn(431, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(432, token1, 1);

 stackPush_CMockExpect(433, token1, &numStack);





 getToken_CMockExpectAndReturn(436, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(437, token2, 0);

 isOperator_CMockExpectAndReturn(438, token2, 1);

 tryEvaluatethenPush_CMockExpect(439, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(443, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(444, token3, 1);

 stackPush_CMockExpect(445, token3, &numStack);





 getToken_CMockExpectAndReturn(448, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(449, token4, 0);

 isOperator_CMockExpectAndReturn(450, token4, 1);

 tryEvaluatethenPush_CMockExpect(451, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(455, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(456, token5, 1);

 stackPush_CMockExpect(457, token5, &numStack);





 getToken_CMockExpectAndReturn(460, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(461, token6, 0);

 isOperator_CMockExpectAndReturn(462, token6, 1);

 tryEvaluatethenPush_CMockExpect(463, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(467, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(468, token7, 1);

 stackPush_CMockExpect(469, token7, &numStack);





 getToken_CMockExpectAndReturn(472, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(473, token8, 0);

 isOperator_CMockExpectAndReturn(474, token8, 1);

 tryEvaluatethenPush_CMockExpect(475, token8, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(479, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(480, token9, 1);

 stackPush_CMockExpect(481, token9, &numStack);





 getToken_CMockExpectAndReturn(484, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(485, token10, 0);

 isOperator_CMockExpectAndReturn(486, token10, 1);

 tryEvaluatethenPush_CMockExpect(487, token10, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(491, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(492, token11, 1);

 stackPush_CMockExpect(493, token11, &numStack);

 getToken_CMockExpectAndReturn(494, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(496, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(530, "(2+3)*4", &tokenizer);





 getToken_CMockExpectAndReturn(533, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(534, token1, 0);

 isOperator_CMockExpectAndReturn(535, token1, 1);

 tryEvaluatethenPush_CMockExpect(536, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(540, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(541, token2, 1);

 stackPush_CMockExpect(542, token2, &numStack);





 getToken_CMockExpectAndReturn(545, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(546, token3, 0);

 isOperator_CMockExpectAndReturn(547, token3, 1);

 tryEvaluatethenPush_CMockExpect(548, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(552, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(553, token4, 1);

 stackPush_CMockExpect(554, token4, &numStack);





 getToken_CMockExpectAndReturn(557, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(558, token5, 0);

 isOperator_CMockExpectAndReturn(559, token5, 1);

 tryEvaluatethenPush_CMockExpect(560, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(564, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(565, token6, 0);

 isOperator_CMockExpectAndReturn(566, token6, 1);

 tryEvaluatethenPush_CMockExpect(567, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(571, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(572, token7, 1);

 stackPush_CMockExpect(573, token7, &numStack);

 getToken_CMockExpectAndReturn(574, &tokenizer, ((void *)0));



 operatorEvaluate_CMockExpect(576, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(609, "2*(3+4)", &tokenizer);





 getToken_CMockExpectAndReturn(612, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(613, token1, 1);

 stackPush_CMockExpect(614, token1, &numStack);





 getToken_CMockExpectAndReturn(617, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(618, token2, 0);

 isOperator_CMockExpectAndReturn(619, token2, 1);

 tryEvaluatethenPush_CMockExpect(620, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(624, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(625, token3, 0);

 isOperator_CMockExpectAndReturn(626, token3, 1);

 tryEvaluatethenPush_CMockExpect(627, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(631, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(632, token4, 1);

 stackPush_CMockExpect(633, token4, &numStack);





 getToken_CMockExpectAndReturn(636, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(637, token5, 0);

 isOperator_CMockExpectAndReturn(638, token5, 1);

 tryEvaluatethenPush_CMockExpect(639, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(643, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(644, token6, 1);

 stackPush_CMockExpect(645, token6, &numStack);





 getToken_CMockExpectAndReturn(648, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(649, token7, 0);

 isOperator_CMockExpectAndReturn(650, token7, 1);

 tryEvaluatethenPush_CMockExpect(651, token7, &numStack, &opeStack);



 getToken_CMockExpectAndReturn(653, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(656, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(674, "-2", &tokenizer);





 getToken_CMockExpectAndReturn(677, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(678, token1, 0);

 isOperator_CMockExpectAndReturn(679, token1, 1);

 tryEvaluatethenPush_CMockExpect(680, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(684, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(685, token2, 1);

 stackPush_CMockExpect(686, token2, &numStack);

 getToken_CMockExpectAndReturn(687, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(690, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(717, "-2+-3", &tokenizer);





 getToken_CMockExpectAndReturn(720, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(721, token1, 0);

 isOperator_CMockExpectAndReturn(722, token1, 1);

 tryEvaluatethenPush_CMockExpect(723, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(727, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(728, token2, 1);

 stackPush_CMockExpect(729, token2, &numStack);





 getToken_CMockExpectAndReturn(732, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(733, token3, 0);

 isOperator_CMockExpectAndReturn(734, token3, 1);

 tryEvaluatethenPush_CMockExpect(735, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(739, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(740, token4, 0);

 isOperator_CMockExpectAndReturn(741, token4, 1);

 tryEvaluatethenPush_CMockExpect(742, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(746, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(747, token5, 1);

 stackPush_CMockExpect(748, token5, &numStack);

 getToken_CMockExpectAndReturn(749, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(752, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(783, "-----2", &tokenizer);





 getToken_CMockExpectAndReturn(786, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(787, token1, 0);

 isOperator_CMockExpectAndReturn(788, token1, 1);

 tryEvaluatethenPush_CMockExpect(789, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(793, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(794, token2, 0);

 isOperator_CMockExpectAndReturn(795, token2, 1);

 tryEvaluatethenPush_CMockExpect(796, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(800, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(801, token3, 0);

 isOperator_CMockExpectAndReturn(802, token3, 1);

 tryEvaluatethenPush_CMockExpect(803, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(807, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(808, token4, 0);

 isOperator_CMockExpectAndReturn(809, token4, 1);

 tryEvaluatethenPush_CMockExpect(810, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(814, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(815, token5, 0);

 isOperator_CMockExpectAndReturn(816, token5, 1);

 tryEvaluatethenPush_CMockExpect(817, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(821, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(822, token5, 1);

 stackPush_CMockExpect(823, token5, &numStack);

 getToken_CMockExpectAndReturn(824, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(827, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(900, "(10*100)/((-5*6)-(2-30))", &tokenizer);





 getToken_CMockExpectAndReturn(903, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(904, token1, 0);

 isOperator_CMockExpectAndReturn(905, token1, 1);

 tryEvaluatethenPush_CMockExpect(906, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(910, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(911, token2, 1);

 stackPush_CMockExpect(912, token2, &numStack);





 getToken_CMockExpectAndReturn(915, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(916, token3, 0);

 isOperator_CMockExpectAndReturn(917, token3, 1);

 tryEvaluatethenPush_CMockExpect(918, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(922, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(923, token4, 1);

 stackPush_CMockExpect(924, token4, &numStack);





 getToken_CMockExpectAndReturn(927, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(928, token5, 0);

 isOperator_CMockExpectAndReturn(929, token5, 1);

 tryEvaluatethenPush_CMockExpect(930, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(934, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(935, token6, 0);

 isOperator_CMockExpectAndReturn(936, token6, 1);

 tryEvaluatethenPush_CMockExpect(937, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(941, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(942, token7, 0);

 isOperator_CMockExpectAndReturn(943, token7, 1);

 tryEvaluatethenPush_CMockExpect(944, token7, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(948, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(949, token8, 0);

 isOperator_CMockExpectAndReturn(950, token8, 1);

 tryEvaluatethenPush_CMockExpect(951, token8, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(955, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(956, token9, 0);

 isOperator_CMockExpectAndReturn(957, token9, 1);

 tryEvaluatethenPush_CMockExpect(958, token9, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(962, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(963, token10, 1);

 stackPush_CMockExpect(964, token10, &numStack);





 getToken_CMockExpectAndReturn(967, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(968, token11, 0);

 isOperator_CMockExpectAndReturn(969, token11, 1);

 tryEvaluatethenPush_CMockExpect(970, token11, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(974, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(975, token12, 1);

 stackPush_CMockExpect(976, token12, &numStack);





 getToken_CMockExpectAndReturn(979, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(980, token13, 0);

 isOperator_CMockExpectAndReturn(981, token13, 1);

 tryEvaluatethenPush_CMockExpect(982, token13, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(986, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(987, token14, 0);

 isOperator_CMockExpectAndReturn(988, token14, 1);

 tryEvaluatethenPush_CMockExpect(989, token14, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(993, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(994, token15, 0);

 isOperator_CMockExpectAndReturn(995, token15, 1);

 tryEvaluatethenPush_CMockExpect(996, token15, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1000, &tokenizer, token16);

 isNumber_CMockExpectAndReturn(1001, token16, 1);

 stackPush_CMockExpect(1002, token16, &numStack);





 getToken_CMockExpectAndReturn(1005, &tokenizer, token17);

 isNumber_CMockExpectAndReturn(1006, token17, 0);

 isOperator_CMockExpectAndReturn(1007, token17, 1);

 tryEvaluatethenPush_CMockExpect(1008, token17, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1012, &tokenizer, token18);

 isNumber_CMockExpectAndReturn(1013, token18, 1);

 stackPush_CMockExpect(1014, token18, &numStack);





 getToken_CMockExpectAndReturn(1017, &tokenizer, token19);

 isNumber_CMockExpectAndReturn(1018, token19, 0);

 isOperator_CMockExpectAndReturn(1019, token19, 1);

 tryEvaluatethenPush_CMockExpect(1020, token19, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1024, &tokenizer, token20);

 isNumber_CMockExpectAndReturn(1025, token20, 0);

 isOperator_CMockExpectAndReturn(1026, token20, 1);

 tryEvaluatethenPush_CMockExpect(1027, token20, &numStack, &opeStack);



 getToken_CMockExpectAndReturn(1029, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1032, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(1059, "-(-2)", &tokenizer);





 getToken_CMockExpectAndReturn(1062, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1063, token1, 0);

 isOperator_CMockExpectAndReturn(1064, token1, 1);

 tryEvaluatethenPush_CMockExpect(1065, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1069, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1070, token2, 0);

 isOperator_CMockExpectAndReturn(1071, token2, 1);

 tryEvaluatethenPush_CMockExpect(1072, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1076, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1077, token3, 0);

 isOperator_CMockExpectAndReturn(1078, token3, 1);

 tryEvaluatethenPush_CMockExpect(1079, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1083, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1084, token4, 1);

 stackPush_CMockExpect(1085, token4, &numStack);





 getToken_CMockExpectAndReturn(1088, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1089, token5, 0);

 isOperator_CMockExpectAndReturn(1090, token5, 1);

 tryEvaluatethenPush_CMockExpect(1091, token5, &numStack, &opeStack);



 getToken_CMockExpectAndReturn(1093, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1096, &numStack, &opeStack);



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





 stringCreate_CMockExpectAndReturn(1153, "-(+(-(-1)*3)-4)", &tokenizer);





 getToken_CMockExpectAndReturn(1156, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1157, token1, 0);

 isOperator_CMockExpectAndReturn(1158, token1, 1);

 tryEvaluatethenPush_CMockExpect(1159, token1, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1163, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1164, token2, 0);

 isOperator_CMockExpectAndReturn(1165, token2, 1);

 tryEvaluatethenPush_CMockExpect(1166, token2, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1170, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1171, token3, 0);

 isOperator_CMockExpectAndReturn(1172, token3, 1);

 tryEvaluatethenPush_CMockExpect(1173, token3, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1177, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1178, token4, 0);

 isOperator_CMockExpectAndReturn(1179, token4, 1);

 tryEvaluatethenPush_CMockExpect(1180, token4, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1184, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1185, token5, 0);

 isOperator_CMockExpectAndReturn(1186, token5, 1);

 tryEvaluatethenPush_CMockExpect(1187, token5, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1191, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(1192, token6, 0);

 isOperator_CMockExpectAndReturn(1193, token6, 1);

 tryEvaluatethenPush_CMockExpect(1194, token6, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1198, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(1199, token7, 0);

 isOperator_CMockExpectAndReturn(1200, token7, 1);

 tryEvaluatethenPush_CMockExpect(1201, token7, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1205, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(1206, token8, 1);

 stackPush_CMockExpect(1207, token8, &numStack);





 getToken_CMockExpectAndReturn(1210, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(1211, token9, 0);

 isOperator_CMockExpectAndReturn(1212, token9, 1);

 tryEvaluatethenPush_CMockExpect(1213, token9, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1217, &tokenizer, token10);

 isNumber_CMockExpectAndReturn(1218, token10, 0);

 isOperator_CMockExpectAndReturn(1219, token10, 1);

 tryEvaluatethenPush_CMockExpect(1220, token10, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1224, &tokenizer, token11);

 isNumber_CMockExpectAndReturn(1225, token11, 1);

 stackPush_CMockExpect(1226, token11, &numStack);





 getToken_CMockExpectAndReturn(1229, &tokenizer, token12);

 isNumber_CMockExpectAndReturn(1230, token12, 0);

 isOperator_CMockExpectAndReturn(1231, token12, 1);

 tryEvaluatethenPush_CMockExpect(1232, token12, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1236, &tokenizer, token13);

 isNumber_CMockExpectAndReturn(1237, token13, 0);

 isOperator_CMockExpectAndReturn(1238, token13, 1);

 tryEvaluatethenPush_CMockExpect(1239, token13, &numStack, &opeStack);







 getToken_CMockExpectAndReturn(1243, &tokenizer, token14);

 isNumber_CMockExpectAndReturn(1244, token14, 1);

 stackPush_CMockExpect(1245, token14, &numStack);





 getToken_CMockExpectAndReturn(1248, &tokenizer, token15);

 isNumber_CMockExpectAndReturn(1249, token15, 0);

 isOperator_CMockExpectAndReturn(1250, token15, 1);

 tryEvaluatethenPush_CMockExpect(1251, token15, &numStack, &opeStack);



 getToken_CMockExpectAndReturn(1253, &tokenizer, ((void *)0));





 operatorEvaluate_CMockExpect(1256, &numStack, &opeStack);



 evaluate("-(+(-(-1)*3)-4)");

}

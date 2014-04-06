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


void setUp(void){}

void tearDown(void){}

 void test_tryEvaluateOperatorOnStackThenPush_will_push_OperatorToken_if_Operator_Stack_is_empty(void){

 Stack numberStack;

 Stack operatorStack;

 Operator *opeToken;



 stackPop_CMockExpectAndReturn(38, &operatorStack, ((void *)0));

 stackPush_CMockExpect(39, opeToken, &operatorStack);

 tryEvaluateOperatorOnStackThenPush(opeToken,&numberStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStaclThenPush_will_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_higher_than_previousToken(void)

{

 Stack numberStack;

 Stack operatorStack;



 Operator plus = {.type= OPERATOR, .id=ADD , .precedence =70};

 Operator multiply = {.type= OPERATOR, .id=MULTIPLY , .precedence =100};



 stackPop_CMockExpectAndReturn(51, &operatorStack, &plus);

 stackPush_CMockExpect(52, &plus, &operatorStack);

 stackPush_CMockExpect(53, &multiply, &operatorStack);

 tryEvaluateOperatorOnStackThenPush(&multiply,&numberStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStackThenPush_will_not_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_lower_than_previousToken(void)

{

 Stack numberStack;

 Stack operatorStack;





 Number number1 = {.type= NUMBER, .value=1};

 Operator multiply = {.type= OPERATOR, .id=MULTIPLY, .precedence=100};

 Number number2 = {.type= NUMBER, .value=2};

 Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};

 Number number3 = {.type= NUMBER, .value=3};



 Number tempAns = {.type= NUMBER, .value=2};

 Token *tempAnsToken =(Token*)&tempAns;

 stackPop_CMockExpectAndReturn(71, &operatorStack, &multiply);

 stackPop_CMockExpectAndReturn(72, &numberStack, &number2);

 stackPop_CMockExpectAndReturn(73, &numberStack, &number1);

 createNumberToken_CMockExpectAndReturn(74, 2, tempAnsToken);

 stackPush_CMockExpect(75, &tempAns, &numberStack);

 stackPop_CMockExpectAndReturn(76, &operatorStack, ((void *)0));

 stackPush_CMockExpect(77, &plus, &operatorStack);



 tryEvaluateOperatorOnStackThenPush(&plus,&numberStack,&operatorStack);

}



 void test_tryEvaluateOperatorOnStackThenPush_evaluate_newToke_and_previousToken_if_both_have_same_precedence(void)

{

 Stack numberStack;

 Stack operatorStack;





 Number number100 = {.type= NUMBER, .value=100};

 Operator minus = {.type= OPERATOR, .id=SUBTRACT, .precedence=70};

 Number number20 = {.type= NUMBER, .value=20};

 Operator minusA = {.type= OPERATOR, .id=SUBTRACT , .precedence=70};

 Number number16 = {.type= NUMBER, .value=16};

 Number tempAns = {.type= NUMBER, .value=80};

 Token *tempAnsToken =(Token*)&tempAns;



 stackPop_CMockExpectAndReturn(96, &operatorStack, &minus);

 stackPop_CMockExpectAndReturn(97, &numberStack, &number20);

 stackPop_CMockExpectAndReturn(98, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(99, 80, tempAnsToken);

 stackPush_CMockExpect(100, &tempAns, &numberStack);

 stackPop_CMockExpectAndReturn(101, &operatorStack, ((void *)0));

 stackPush_CMockExpect(102, &minusA, &operatorStack);



 tryEvaluateOperatorOnStackThenPush(&minusA,&numberStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_1(void)

{

 Stack numberStack;

 Stack operatorStack;



 Number number21 = {.type= NUMBER, .value=21};

 Operator multiply = {.type= OPERATOR, .id=MULTIPLY, .precedence=100};

 Number number22 = {.type= NUMBER, .value=22};



 Number tempAns = {.type= NUMBER, .value=462};

 Token *tempAnsToken =(Token*)&tempAns;



 Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};

 Number number30 = {.type= NUMBER, .value=30};

 Operator divide = {.type= OPERATOR, .id=DIVIDE, .precedence=100};

 Number number6 = {.type= NUMBER, .value=6};





 stackPop_CMockExpectAndReturn(125, &operatorStack, &multiply);

 stackPop_CMockExpectAndReturn(126, &numberStack, &number22);

 stackPop_CMockExpectAndReturn(127, &numberStack, &number21);

 createNumberToken_CMockExpectAndReturn(128, 462, tempAnsToken);

 stackPush_CMockExpect(129, tempAnsToken, &numberStack);



 stackPop_CMockExpectAndReturn(131, &operatorStack, &plus);

 stackPush_CMockExpect(132, &plus, &operatorStack);

 stackPush_CMockExpect(133, &divide, &operatorStack);



 tryEvaluateOperatorOnStackThenPush(&divide,&numberStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_2(void)

{

 Stack dataStack;

 Stack operatorStack;



 Number number21 = {.type= NUMBER, .value=21};

 Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};

 Number number22 = {.type= NUMBER, .value=22};



 Number tempAns1 = {.type= NUMBER, .value=43};

 Token *tempAnsToken1 =(Token*)&tempAns1;



 Operator bitwiseAND = {.type= OPERATOR, .id=BITWISE_AND, .precedence=20};

 Number number30 = {.type= NUMBER, .value=30};

 Operator bitwiseOR = {.type= OPERATOR, .id=BITWISE_OR, .precedence=10};

 Number number6 = {.type= NUMBER, .value=6};



 Number tempAns2 = {.type= NUMBER, .value=6};

 Token *tempAnsToken2 =(Token*)&tempAns2;



 stackPop_CMockExpectAndReturn(158, &operatorStack, &plus);

 stackPop_CMockExpectAndReturn(159, &dataStack, &number22);

 stackPop_CMockExpectAndReturn(160, &dataStack, &number21);

 createNumberToken_CMockExpectAndReturn(161, 43, tempAnsToken1);

 stackPush_CMockExpect(162, tempAnsToken1, &dataStack);



 stackPop_CMockExpectAndReturn(164, &operatorStack, &bitwiseAND);

 stackPop_CMockExpectAndReturn(165, &dataStack, &number30);

 stackPop_CMockExpectAndReturn(166, &dataStack, &number6);

 createNumberToken_CMockExpectAndReturn(167, 6, tempAnsToken2);

 stackPush_CMockExpect(168, tempAnsToken2, &dataStack);



 stackPop_CMockExpectAndReturn(170, &operatorStack, ((void *)0));

 stackPush_CMockExpect(171, &bitwiseOR, &operatorStack);



 tryEvaluateOperatorOnStackThenPush(&bitwiseOR,&dataStack,&operatorStack);

}

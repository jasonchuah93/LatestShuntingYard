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
#include "CException.h"




void setUp(void){}

void tearDown(void){}

 void test_tryEvaluateOperatorOnStackThenPush_will_push_OperatorToken_if_Operator_Stack_is_empty(void){

 Stack numberStack;

 Stack operatorStack;

 Operator *opeToken;



 stackPop_CMockExpectAndReturn(39, &operatorStack, ((void *)0));

 stackPush_CMockExpect(40, opeToken, &operatorStack);

 tryEvaluateOperatorOnStackThenPush(opeToken,&numberStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStackThenPush_will_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_higher_than_previousToken(void)

{

 Stack numberStack;

 Stack operatorStack;



 Operator plus = {.type= OPERATOR, .id=ADD , .precedence =70};

 Operator multiply = {.type= OPERATOR, .id=MULTIPLY , .precedence =100};



 stackPop_CMockExpectAndReturn(52, &operatorStack, &plus);

 stackPush_CMockExpect(53, &plus, &operatorStack);

 stackPush_CMockExpect(54, &multiply, &operatorStack);

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



 stackPop_CMockExpectAndReturn(72, &operatorStack, &multiply);

 stackPop_CMockExpectAndReturn(73, &numberStack, &number2);

 stackPop_CMockExpectAndReturn(74, &numberStack, &number1);

 createNumberToken_CMockExpectAndReturn(75, 2, tempAnsToken);

 stackPush_CMockExpect(76, &tempAns, &numberStack);

 stackPop_CMockExpectAndReturn(77, &operatorStack, ((void *)0));

 stackPush_CMockExpect(78, &plus, &operatorStack);



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



 stackPop_CMockExpectAndReturn(97, &operatorStack, &minus);

 stackPop_CMockExpectAndReturn(98, &numberStack, &number20);

 stackPop_CMockExpectAndReturn(99, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(100, 80, tempAnsToken);

 stackPush_CMockExpect(101, &tempAns, &numberStack);

 stackPop_CMockExpectAndReturn(102, &operatorStack, ((void *)0));

 stackPush_CMockExpect(103, &minusA, &operatorStack);



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





 stackPop_CMockExpectAndReturn(126, &operatorStack, &multiply);

 stackPop_CMockExpectAndReturn(127, &numberStack, &number22);

 stackPop_CMockExpectAndReturn(128, &numberStack, &number21);

 createNumberToken_CMockExpectAndReturn(129, 462, tempAnsToken);

 stackPush_CMockExpect(130, tempAnsToken, &numberStack);



 stackPop_CMockExpectAndReturn(132, &operatorStack, &plus);

 stackPush_CMockExpect(133, &plus, &operatorStack);

 stackPush_CMockExpect(134, &divide, &operatorStack);



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



 stackPop_CMockExpectAndReturn(159, &operatorStack, &plus);

 stackPop_CMockExpectAndReturn(160, &dataStack, &number22);

 stackPop_CMockExpectAndReturn(161, &dataStack, &number21);

 createNumberToken_CMockExpectAndReturn(162, 43, tempAnsToken1);

 stackPush_CMockExpect(163, tempAnsToken1, &dataStack);



 stackPop_CMockExpectAndReturn(165, &operatorStack, &bitwiseAND);

 stackPop_CMockExpectAndReturn(166, &dataStack, &number30);

 stackPop_CMockExpectAndReturn(167, &dataStack, &number6);

 createNumberToken_CMockExpectAndReturn(168, 6, tempAnsToken2);

 stackPush_CMockExpect(169, tempAnsToken2, &dataStack);



 stackPop_CMockExpectAndReturn(171, &operatorStack, ((void *)0));

 stackPush_CMockExpect(172, &bitwiseOR, &operatorStack);



 tryEvaluateOperatorOnStackThenPush(&bitwiseOR,&dataStack,&operatorStack);

}

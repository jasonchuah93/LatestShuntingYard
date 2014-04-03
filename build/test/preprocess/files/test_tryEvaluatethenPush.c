#include "unity.h"
#include "tryEvaluatethenPush.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "mock_getToken.h"
#include "mock_StringObject.h"
#include "createNumberToken.h"
#include "calculateToken.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Evaluate.h"


void setUp(void){}

void tearDown(void){}



void test_try_evaluate_2_PLUS_3_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD, .precedence=30};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)36);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)37);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)38);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)39);;};



 stackPush(token1,numberStack);

 tryEvaluatethenPush(token2,numberStack,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

}



void test_try_evaluate_2_PLUS_3_MULTIPLY_4_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD, .precedence=30};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY, .precedence=60};

 Token *token4 = (Token*)&plus;



 Number number4 = {.type= NUMBER, .value=4};

 Token *token5 = (Token*)&number4;



 Stack *numberStack = createStack();

 Stack *operatorStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)77);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)78);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)79);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)80);;};



 stackPush(token1,numberStack);

 tryEvaluatethenPush(token2,numberStack,operatorStack);

 stackPush(token3,numberStack);

 tryEvaluatethenPush(token4,numberStack,operatorStack);

 stackPush(token5,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

}

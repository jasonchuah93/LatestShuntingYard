#include "unity.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_getToken.h"
#include "mock_StringObject.h"
#include "createNumberToken.h"
#include "calculateToken.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Evaluate.h"


void setUp(void){}

void tearDown(void){}



void test_operator_evaluate_should_evaluate_99_PLUS_99(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "99+99", .startIndex = 0, .length = 3};



 Number numberA99 = {.type= NUMBER, .value=99};

 Token *token1 = (Token*)&numberA99;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number numberB99 = {.type= NUMBER, .value=99};

 Token *token3 = (Token*)&numberB99;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)36);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)37);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)38);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)39);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((198)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_2_PLUS_3(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "2+3", .startIndex = 0, .length = 3};



 Number number2 = {.type= NUMBER, .value=2};

 Token *token1 = (Token*)&number2;



 Operator plus = {.type= OPERATOR, .id = ADD};

 Token *token2 = (Token*)&plus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)71);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)72);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)73);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)74);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_20_MINUS_15(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "20-15", .startIndex = 0, .length = 3};



 Number number20 = {.type= NUMBER, .value=20};

 Token *token1 = (Token*)&number20;



 Operator minus = {.type= OPERATOR, .id = SUBTRACT};

 Token *token2 = (Token*)&minus;



 Number number15 = {.type= NUMBER, .value=15};

 Token *token3 = (Token*)&number15;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)106);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)107);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)108);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)109);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_100_MINUS_67(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "100-67", .startIndex = 0, .length = 3};



 Number number100 = {.type= NUMBER, .value=100};

 Token *token1 = (Token*)&number100;



 Operator minus = {.type= OPERATOR, .id = SUBTRACT};

 Token *token2 = (Token*)&minus;



 Number number67 = {.type= NUMBER, .value=67};

 Token *token3 = (Token*)&number67;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)141);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)142);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)143);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)144);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((33)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_100_MULTIPLY_67(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "100*67", .startIndex = 0, .length = 3};



 Number number100 = {.type= NUMBER, .value=100};

 Token *token1 = (Token*)&number100;



 Operator multiply = {.type= OPERATOR, .id = MULTIPLY};

 Token *token2 = (Token*)&multiply;



 Number number67 = {.type= NUMBER, .value=67};

 Token *token3 = (Token*)&number67;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)176);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)177);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)178);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)179);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((6700)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_100_DIVIDE_67(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "100*10", .startIndex = 0, .length = 3};



 Number number100 = {.type= NUMBER, .value=100};

 Token *token1 = (Token*)&number100;



 Operator divide = {.type= OPERATOR, .id = DIVIDE};

 Token *token2 = (Token*)&divide;



 Number number10 = {.type= NUMBER, .value=10};

 Token *token3 = (Token*)&number10;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)211);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)212);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)213);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)214);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_10000_DIVIDE_20(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "10000*20", .startIndex = 0, .length = 3};



 Number number10000 = {.type= NUMBER, .value=10000};

 Token *token1 = (Token*)&number10000;



 Operator divide = {.type= OPERATOR, .id = DIVIDE};

 Token *token2 = (Token*)&divide;



 Number number20 = {.type= NUMBER, .value=20};

 Token *token3 = (Token*)&number20;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)246);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)247);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)248);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)249);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((500)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)258, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_56_BITWISE_AND_30(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "56&30", .startIndex = 0, .length = 3};



 Number number56 = {.type= NUMBER, .value=56};

 Token *token1 = (Token*)&number56;



 Operator bitwizeAND = {.type= OPERATOR, .id = BITWISE_AND};

 Token *token2 = (Token*)&bitwizeAND;



 Number number30 = {.type= NUMBER, .value=30};

 Token *token3 = (Token*)&number30;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)281);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)282);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)283);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)284);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((24)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_90_BITWISE_OR_20(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "90|20", .startIndex = 0, .length = 3};



 Number number90 = {.type= NUMBER, .value=90};

 Token *token1 = (Token*)&number90;



 Operator bitwizeOR = {.type= OPERATOR, .id = BITWISE_OR};

 Token *token2 = (Token*)&bitwizeOR;



 Number number20 = {.type= NUMBER, .value=20};

 Token *token3 = (Token*)&number20;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)316);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)317);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)318);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)319);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((94)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)328, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_99_BITWISE_XOR_66(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "99^66", .startIndex = 0, .length = 3};



 Number number99 = {.type= NUMBER, .value=99};

 Token *token1 = (Token*)&number99;



 Operator bitwizeXOR = {.type= OPERATOR, .id = BITWISE_XOR};

 Token *token2 = (Token*)&bitwizeXOR;



 Number number66 = {.type= NUMBER, .value=66};

 Token *token3 = (Token*)&number66;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)351);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)352);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)353);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)354);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((33)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)363, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_55_MUDULUS_3(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "55^3", .startIndex = 0, .length = 3};



 Number number55 = {.type= NUMBER, .value=55};

 Token *token1 = (Token*)&number55;



 Operator modulus = {.type= OPERATOR, .id = MODULUS};

 Token *token2 = (Token*)&modulus;



 Number number3 = {.type= NUMBER, .value=3};

 Token *token3 = (Token*)&number3;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)386);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)387);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)388);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)389);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)398, UNITY_DISPLAY_STYLE_INT);

}



void test_operator_evaluate_should_evaluate_68_MUDULUS_7(void){

 int check;

 int tempAnswer;

 Token *tempToken;

 Number *tempAns;



 String tokenizer = {.rawString = "68^7", .startIndex = 0, .length = 3};



 Number number68 = {.type= NUMBER, .value=68};

 Token *token1 = (Token*)&number68;



 Operator modulus = {.type= OPERATOR, .id = MODULUS};

 Token *token2 = (Token*)&modulus;



 Number number7 = {.type= NUMBER, .value=7};

 Token *token3 = (Token*)&number7;



 Stack *operatorStack = createStack();

 Stack *numberStack = createStack();



 if ((((operatorStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)421);;};

 if ((((numberStack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)422);;};

 if ((((operatorStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)423);;};

 if ((((numberStack->topOfStack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)424);;};



 stackPush(token1,numberStack);

 stackPush(token2,operatorStack);

 stackPush(token3,numberStack);



 operatorEvaluate(numberStack ,operatorStack);

 tempToken=(Token*)stackPop(numberStack);

 tempAns=(Number*)tempToken;

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tempAns->value)), (((void *)0)), (_U_UINT)433, UNITY_DISPLAY_STYLE_INT);

}

#include "unity.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_getToken.h"
#include "mock_createNumberToken.h"
#include "mock_StringObject.h"
#include "mock_Stack.h"
#include "calculateToken.h"
#include "LinkedList.h"
#include "Evaluate.h"
#include "Error.h"


void setUp(void){}

void tearDown(void){}









 void test_operatorEvaluate_should_throw_error_when_encounter_invalid_operator(void){



 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 ErrorCode exception;





 String tokenizer = {.rawString = "1$2", .startIndex = 0, .length=3};

 Number number1 = {.type= NUMBER, .value=1};

 Operator currentProgramCounter = {.type= OPERATOR, .id=CURRENT_PROGRAM_COUNTER , .precedence =0};

 Number number2 = {.type= NUMBER, .value=2};



 stackPop_CMockExpectAndReturn(33, &numberStack, &number1);

 stackPop_CMockExpectAndReturn(34, &numberStack, &number2);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

   operatorEvaluate(&numberStack,&currentProgramCounter);

  UnityFail( ("Invalid Operator should throw Error Not Operator"), (_U_UINT)38);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_operatorEvaluate_3_PLUS_7(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "3+7", .startIndex = 0, .length=3};

 Number number3 = {.type= NUMBER, .value=3};

 Operator plus = {.type= OPERATOR, .id=ADD , .precedence=70};

 Number number7 = {.type= NUMBER, .value=7};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(59, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(60, &numberStack, &number3);

 createNumberToken_CMockExpectAndReturn(61, 10, answerToken);

 stackPush_CMockExpect(62, &answer, &numberStack);



 operatorEvaluate(&numberStack,&plus);

}



void test_operatorEvaluate_100_MINUS_37(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "100-37", .startIndex = 0, .length=3};

 Number number100 = {.type= NUMBER, .value=100};

 Operator minus = {.type= OPERATOR, .id=SUBTRACT , .precedence=70};

 Number number37 = {.type= NUMBER, .value=37};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(81, &numberStack, &number37);

 stackPop_CMockExpectAndReturn(82, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(83, 63, answerToken);

 stackPush_CMockExpect(84, &answer, &numberStack);



 operatorEvaluate(&numberStack,&minus);

}



void test_operatorEvaluate_100_MULTIPLY_50(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "100*50", .startIndex = 0, .length=3};

 Number number100 = {.type= NUMBER, .value=100};

 Operator multiply = {.type= OPERATOR, .id=MULTIPLY , .precedence=100};

 Number number50 = {.type= NUMBER, .value=50};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(103, &numberStack, &number50);

 stackPop_CMockExpectAndReturn(104, &numberStack, &number100);

 createNumberToken_CMockExpectAndReturn(105, 5000, answerToken);

 stackPush_CMockExpect(106, &answer, &numberStack);



 operatorEvaluate(&numberStack,&multiply);

}



void test_operatorEvaluate_99_DIVIDE_3(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "99/3", .startIndex = 0, .length=3};

 Number number99 = {.type= NUMBER, .value=99};

 Operator divide = {.type= OPERATOR, .id=DIVIDE , .precedence=100};

 Number number3 = {.type= NUMBER, .value=3};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(125, &numberStack, &number3);

 stackPop_CMockExpectAndReturn(126, &numberStack, &number99);

 createNumberToken_CMockExpectAndReturn(127, 33, answerToken);

 stackPush_CMockExpect(128, &answer, &numberStack);



 operatorEvaluate(&numberStack,&divide);

}



void test_operatorEvaluate_60_MODULUS_7(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "60%7", .startIndex = 0, .length=3};

 Number number60 = {.type= NUMBER, .value=60};

 Operator modulus = {.type= OPERATOR, .id=MODULUS , .precedence=100};

 Number number7 = {.type= NUMBER, .value=7};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(147, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(148, &numberStack, &number60);

 createNumberToken_CMockExpectAndReturn(149, 4, answerToken);

 stackPush_CMockExpect(150, &answer, &numberStack);



 operatorEvaluate(&numberStack,&modulus);

}



void test_operatorEvaluate_45_BITWISEAND_54(void)

{

 Stack numberStack;

 Token *tempToken;

 Number *tempAns;

 int check;



 String tokenizer = {.rawString = "45&54", .startIndex = 0, .length=3};

 Number number45 = {.type= NUMBER, .value=45};

 Operator bitwiseAND = {.type= OPERATOR, .id=BITWISE_AND , .precedence=20};

 Number number54 = {.type= NUMBER, .value=54};

 Number answer;

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(169, &numberStack, &number54);

 stackPop_CMockExpectAndReturn(170, &numberStack, &number45);

 createNumberToken_CMockExpectAndReturn(171, 36, answerToken);

 stackPush_CMockExpect(172, &answer, &numberStack);



 operatorEvaluate(&numberStack,&bitwiseAND);

}

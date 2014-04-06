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

 Number answer = {.type= NUMBER, .value=10};

 Token *answerToken=(Token*)&answer;



 stackPop_CMockExpectAndReturn(59, &numberStack, &number7);

 stackPop_CMockExpectAndReturn(60, &numberStack, &number3);

 createNumberToken_CMockExpectAndReturn(61, 10, answerToken);

 stackPush_CMockExpect(62, &answer, &numberStack);



 operatorEvaluate(&numberStack,&plus);

}

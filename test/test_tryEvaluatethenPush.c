#include "unity.h"
#include "Evaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "stackForEvaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_Stack.h"
#include "mock_operatorEvaluate.h"
#include "mock_calculateToken.h"


void setUp(void){}
void tearDown(void){}

void xtest_try_evaluate_then_push_for_2_PLUS_3(void){
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Number answer = {.type=NUMBER, .value=5};
	Token *ansToken = (Token*)&answer;

	//stackPush_Expect(token2,&opeStack);
	
	tryEvaluatethenPush_Expect(token2,&numStack,&opeStack);
}
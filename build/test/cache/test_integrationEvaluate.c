#include "unity.h"
#include "tryEvaluatethenPush.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "getToken.h"
#include "createNumberToken.h"
#include "calculateToken.h"
#include "StringObject.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Iterator.h"
#include "Evaluate.h"
#include "Error.h"


void setUp(void){}

void tearDown(void){}

void test_evaluate_2_PLUS_3(void){

 int check;

 check=evaluate("2+3");

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

}

/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      CMock_Init(); \
      setUp(); \
      TestFunc(); \
      CMock_Verify(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  CMock_Destroy(); \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"
#include "mock_Stack.h"
#include "mock_StringObject.h"
#include "mock_createNumberToken.h"
#include "mock_getToken.h"
#include "mock_tryEvaluatethenPush.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_operatorEvaluate_should_throw_error_when_encounter_invalid_operator(void);
extern void test_operatorEvaluate_3_PLUS_7(void);
extern void test_operatorEvaluate_100_MINUS_37(void);
extern void test_operatorEvaluate_100_MULTIPLY_50(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_Stack_Init();
  mock_StringObject_Init();
  mock_createNumberToken_Init();
  mock_getToken_Init();
  mock_tryEvaluatethenPush_Init();
}
static void CMock_Verify(void)
{
  mock_Stack_Verify();
  mock_StringObject_Verify();
  mock_createNumberToken_Verify();
  mock_getToken_Verify();
  mock_tryEvaluatethenPush_Verify();
}
static void CMock_Destroy(void)
{
  mock_Stack_Destroy();
  mock_StringObject_Destroy();
  mock_createNumberToken_Destroy();
  mock_getToken_Destroy();
  mock_tryEvaluatethenPush_Destroy();
}

//=======Test Reset Option=====
void resetTest()
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_OperatorEvaluate.c";
  UnityBegin();
  RUN_TEST(test_operatorEvaluate_should_throw_error_when_encounter_invalid_operator, 20);
  RUN_TEST(test_operatorEvaluate_3_PLUS_7, 45);
  RUN_TEST(test_operatorEvaluate_100_MINUS_37, 67);
  RUN_TEST(test_operatorEvaluate_100_MULTIPLY_50, 89);

  return (UnityEnd());
}

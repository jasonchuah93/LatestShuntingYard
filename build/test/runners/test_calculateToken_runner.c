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
#include "mock_StringObject.h"
#include "mock_getToken.h"
#include "mock_initializeToken.h"
#include "mock_operatorEvaluate.h"
#include "mock_tryEvaluatethenPush.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_should_calculate_2_PLUS_3(void);
extern void test_should_calculate_10_MINUS_3(void);
extern void test_should_calculate_10_MULTIPLY_10(void);
extern void test_should_calculate_1000_DIVIDE_10(void);
extern void test_should_calculate_56_BITWISE_AND_30(void);
extern void test_should_calculate_90_BITWISE_OR_20(void);
extern void test_should_calculate_99_BITWISE_XOR_66(void);
extern void test_should_calculate_55_MODULUS_3(void);
extern void test_should_calculate_68_MODULUS_7(void);
extern void test_should_complement_78(void);
extern void test_should_complement_2(void);
extern void test_should_PLUS_PLUS_3(void);
extern void test_should_PLUS_PLUS_100(void);
extern void test_should_MINUS_MINUS_10(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_StringObject_Init();
  mock_getToken_Init();
  mock_initializeToken_Init();
  mock_operatorEvaluate_Init();
  mock_tryEvaluatethenPush_Init();
}
static void CMock_Verify(void)
{
  mock_StringObject_Verify();
  mock_getToken_Verify();
  mock_initializeToken_Verify();
  mock_operatorEvaluate_Verify();
  mock_tryEvaluatethenPush_Verify();
}
static void CMock_Destroy(void)
{
  mock_StringObject_Destroy();
  mock_getToken_Destroy();
  mock_initializeToken_Destroy();
  mock_operatorEvaluate_Destroy();
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
  Unity.TestFile = "test_calculateToken.c";
  UnityBegin();
  RUN_TEST(test_should_calculate_2_PLUS_3, 18);
  RUN_TEST(test_should_calculate_10_MINUS_3, 30);
  RUN_TEST(test_should_calculate_10_MULTIPLY_10, 42);
  RUN_TEST(test_should_calculate_1000_DIVIDE_10, 54);
  RUN_TEST(test_should_calculate_56_BITWISE_AND_30, 66);
  RUN_TEST(test_should_calculate_90_BITWISE_OR_20, 78);
  RUN_TEST(test_should_calculate_99_BITWISE_XOR_66, 90);
  RUN_TEST(test_should_calculate_55_MODULUS_3, 102);
  RUN_TEST(test_should_calculate_68_MODULUS_7, 114);
  RUN_TEST(test_should_complement_78, 126);
  RUN_TEST(test_should_complement_2, 136);
  RUN_TEST(test_should_PLUS_PLUS_3, 146);
  RUN_TEST(test_should_PLUS_PLUS_100, 156);
  RUN_TEST(test_should_MINUS_MINUS_10, 166);

  return (UnityEnd());
}

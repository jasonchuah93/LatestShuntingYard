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

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_shunting_yard_should_return_0_if_the_expression_is_null(void);
extern void test_should_return_3_for_1_plus_2(void);
extern void test_should_return_6_for_60_divide_10(void);
extern void test_evaluate_2_MULTIPLY_3_PLUS_4(void);
extern void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void);
extern void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void);
extern void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void);
extern void test_should_evaluate_43_HASHTAG_42_and_throw_error_invalid_operator(void);
extern void test_should_evaluate_left_parenthesis_2_right_parenthesis(void);
extern void test_should_evaluate_left_parenthesis_22_right_parenthesis(void);
extern void test_should_evaluate_left__left_parenthesis_22_right_right_parenthesis(void);
extern void test_left_bracket_2_plus_3_right_bracket(void);
extern void test_left_bracket_20_multiply_3_subtract_50_right_bracket(void);
extern void test_left_left_left_bracket_20_multiply_3_subtract_50_right_right_right_bracket(void);
extern void test_2_MULTIPLY_LEFT_PARENTHESIS_THREE_PLUS_FOUR_RIGHT_PARENTHESIS(void);
extern void test_NEGATIVE_2_SHOULD_RETURN_NEGATIVE_2(void);
extern void test_NEGATIVE_2_NEGATIVE_3_SHOULD_RETURN_NEGATIVE_5(void);


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
}
static void CMock_Verify(void)
{
  mock_Stack_Verify();
  mock_StringObject_Verify();
  mock_createNumberToken_Verify();
  mock_getToken_Verify();
}
static void CMock_Destroy(void)
{
  mock_Stack_Destroy();
  mock_StringObject_Destroy();
  mock_createNumberToken_Destroy();
  mock_getToken_Destroy();
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
  Unity.TestFile = "test_Evaluate.c";
  UnityBegin();
  RUN_TEST(test_shunting_yard_should_return_0_if_the_expression_is_null, 35);
  RUN_TEST(test_should_return_3_for_1_plus_2, 60);
  RUN_TEST(test_should_return_6_for_60_divide_10, 116);
  RUN_TEST(test_evaluate_2_MULTIPLY_3_PLUS_4, 173);
  RUN_TEST(test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6, 259);
  RUN_TEST(test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6, 402);
  RUN_TEST(test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10, 538);
  RUN_TEST(test_should_evaluate_43_HASHTAG_42_and_throw_error_invalid_operator, 703);
  RUN_TEST(test_should_evaluate_left_parenthesis_2_right_parenthesis, 739);
  RUN_TEST(test_should_evaluate_left_parenthesis_22_right_parenthesis, 795);
  RUN_TEST(test_should_evaluate_left__left_parenthesis_22_right_right_parenthesis, 852);
  RUN_TEST(test_left_bracket_2_plus_3_right_bracket, 929);
  RUN_TEST(test_left_bracket_20_multiply_3_subtract_50_right_bracket, 1001);
  RUN_TEST(test_left_left_left_bracket_20_multiply_3_subtract_50_right_right_right_bracket, 1098);
  RUN_TEST(test_2_MULTIPLY_LEFT_PARENTHESIS_THREE_PLUS_FOUR_RIGHT_PARENTHESIS, 1241);
  RUN_TEST(test_NEGATIVE_2_SHOULD_RETURN_NEGATIVE_2, 1348);
  RUN_TEST(test_NEGATIVE_2_NEGATIVE_3_SHOULD_RETURN_NEGATIVE_5, 1405);

  return (UnityEnd());
}

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

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_should_return_3_for_1_plus_2(void);
extern void test_should_return_6_for_60_divide_10(void);
extern void test_evaluate_2_MULTIPLY_3_PLUS_4(void);
extern void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void);
extern void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void);
extern void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void);
extern void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10_OR_10_AND_53_XOR_21(void);
extern void test_evaluate_with_different_expression(void);
extern void test_evaluate_with_longer_expression(void);
extern void test_should_evaluate_left_parenthesis_2_right_parenthesis(void);
extern void test_should_evaluate_left_parenthesis_100_right_parenthesis(void);
extern void test_should_evaluate_left_parenthesis_100_plus_100_divide_20_right_parenthesis(void);
extern void test_should_evaluate_left_left_parenthesis_22_right_right_parenthesis(void);
extern void test_should_evaluate_left_left_left_parenthesis_55_right_right_right_parenthesis(void);
extern void test_should_evaluate_10_multiply_left_parenthesis_6_plus_2_right_parenthesis(void);
extern void test_should_evaluate_left_parenthesis_10_divide_5_right_parenthesis_multiply_left_parenthesis_6_plus_2_right_parenthesis(void);
extern void test_left_left_left_bracket_20_plus_60_divide_4_right_right_right_bracket(void);
extern void test_left_bracket_6_plus_97_right_bracket_multiply_30(void);
extern void test_one_minus_hundred(void);
extern void test_evaluate_positive_fifty(void);
extern void test_evaluate_negative_hundred(void);
extern void test_evaluate_multiply_ten_should_return_error(void);
extern void test_evaluate_80_multiply_should_return_error(void);
extern void test_evaluate_50_add_should_return_error(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_StringObject_Init();
}
static void CMock_Verify(void)
{
  mock_StringObject_Verify();
}
static void CMock_Destroy(void)
{
  mock_StringObject_Destroy();
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
  Unity.TestFile = "test_integrationEvaluate.c";
  UnityBegin();
  RUN_TEST(test_should_return_3_for_1_plus_2, 41);
  RUN_TEST(test_should_return_6_for_60_divide_10, 53);
  RUN_TEST(test_evaluate_2_MULTIPLY_3_PLUS_4, 66);
  RUN_TEST(test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6, 84);
  RUN_TEST(test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6, 97);
  RUN_TEST(test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10, 110);
  RUN_TEST(test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10_OR_10_AND_53_XOR_21, 124);
  RUN_TEST(test_evaluate_with_different_expression, 138);
  RUN_TEST(test_evaluate_with_longer_expression, 151);
  RUN_TEST(test_should_evaluate_left_parenthesis_2_right_parenthesis, 164);
  RUN_TEST(test_should_evaluate_left_parenthesis_100_right_parenthesis, 180);
  RUN_TEST(test_should_evaluate_left_parenthesis_100_plus_100_divide_20_right_parenthesis, 194);
  RUN_TEST(test_should_evaluate_left_left_parenthesis_22_right_right_parenthesis, 208);
  RUN_TEST(test_should_evaluate_left_left_left_parenthesis_55_right_right_right_parenthesis, 222);
  RUN_TEST(test_should_evaluate_10_multiply_left_parenthesis_6_plus_2_right_parenthesis, 236);
  RUN_TEST(test_should_evaluate_left_parenthesis_10_divide_5_right_parenthesis_multiply_left_parenthesis_6_plus_2_right_parenthesis, 250);
  RUN_TEST(test_left_left_left_bracket_20_plus_60_divide_4_right_right_right_bracket, 264);
  RUN_TEST(test_left_bracket_6_plus_97_right_bracket_multiply_30, 276);
  RUN_TEST(test_one_minus_hundred, 288);
  RUN_TEST(test_evaluate_positive_fifty, 300);
  RUN_TEST(test_evaluate_negative_hundred, 312);
  RUN_TEST(test_evaluate_multiply_ten_should_return_error, 324);
  RUN_TEST(test_evaluate_80_multiply_should_return_error, 340);
  RUN_TEST(test_evaluate_50_add_should_return_error, 356);

  return (UnityEnd());
}

/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_calculateToken.h"

typedef struct _CMOCK_calculate_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  void* ReturnVal;
  int CallOrder;
  Operator* Expected_opeToken;
  Number* Expected_first;
  Number* Expected_second;

} CMOCK_calculate_CALL_INSTANCE;

static struct mock_calculateTokenInstance
{
  int calculate_IgnoreBool;
  void* calculate_FinalReturn;
  CMOCK_calculate_CALLBACK calculate_CallbackFunctionPointer;
  int calculate_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE calculate_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_calculateToken_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.calculate_IgnoreBool)
    Mock.calculate_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.calculate_CallInstance, cmock_line, "Function 'calculate' called less times than expected.");
  if (Mock.calculate_CallbackFunctionPointer != NULL)
    Mock.calculate_CallInstance = CMOCK_GUTS_NONE;
}

void mock_calculateToken_Init(void)
{
  mock_calculateToken_Destroy();
}

void mock_calculateToken_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.calculate_CallbackFunctionPointer = NULL;
  Mock.calculate_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void* calculate(Operator* opeToken, Number* first, Number* second)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_calculate_CALL_INSTANCE* cmock_call_instance = (CMOCK_calculate_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.calculate_CallInstance);
  Mock.calculate_CallInstance = CMock_Guts_MemNext(Mock.calculate_CallInstance);
  if (Mock.calculate_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.calculate_FinalReturn;
    Mock.calculate_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.calculate_CallbackFunctionPointer != NULL)
  {
    return Mock.calculate_CallbackFunctionPointer(opeToken, first, second, Mock.calculate_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'calculate' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'calculate' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'calculate' called later than expected.");
  UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_opeToken), (void*)(opeToken), sizeof(Operator), cmock_line, "Function 'calculate' called with unexpected value for argument 'opeToken'.");
  UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_first), (void*)(first), sizeof(Number), cmock_line, "Function 'calculate' called with unexpected value for argument 'first'.");
  UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_second), (void*)(second), sizeof(Number), cmock_line, "Function 'calculate' called with unexpected value for argument 'second'.");
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_calculate(CMOCK_calculate_CALL_INSTANCE* cmock_call_instance, Operator* opeToken, Number* first, Number* second)
{
  cmock_call_instance->Expected_opeToken = opeToken;
  cmock_call_instance->Expected_first = first;
  cmock_call_instance->Expected_second = second;
}

void calculate_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, void* cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_calculate_CALL_INSTANCE));
  CMOCK_calculate_CALL_INSTANCE* cmock_call_instance = (CMOCK_calculate_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.calculate_CallInstance = CMock_Guts_MemChain(Mock.calculate_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.calculate_IgnoreBool = (int)1;
}

void calculate_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, Operator* opeToken, Number* first, Number* second, void* cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_calculate_CALL_INSTANCE));
  CMOCK_calculate_CALL_INSTANCE* cmock_call_instance = (CMOCK_calculate_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.calculate_CallInstance = CMock_Guts_MemChain(Mock.calculate_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_calculate(cmock_call_instance, opeToken, first, second);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void calculate_StubWithCallback(CMOCK_calculate_CALLBACK Callback)
{
  Mock.calculate_CallbackFunctionPointer = Callback;
}


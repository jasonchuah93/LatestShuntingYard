/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_STACK_H
#define _MOCK_STACK_H

#include "Stack.h"
#include "CException.h"

void mock_Stack_Init(void);
void mock_Stack_Destroy(void);
void mock_Stack_Verify(void);




#define createStack_IgnoreAndReturn(cmock_retval) createStack_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void createStack_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, Stack* cmock_to_return);
#define createStack_ExpectAndReturn(cmock_retval) createStack_CMockExpectAndReturn(__LINE__, cmock_retval)
void createStack_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, Stack* cmock_to_return);
typedef Stack* (* CMOCK_createStack_CALLBACK)(int cmock_num_calls);
void createStack_StubWithCallback(CMOCK_createStack_CALLBACK Callback);
#define createStack_ExpectAndThrow(cmock_to_throw) createStack_CMockExpectAndThrow(__LINE__, cmock_to_throw)
void createStack_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, CEXCEPTION_T cmock_to_throw);
#define stackPush_Ignore() stackPush_CMockIgnore()
void stackPush_CMockIgnore(void);
#define stackPush_Expect(data, stack) stackPush_CMockExpect(__LINE__, data, stack)
void stackPush_CMockExpect(UNITY_LINE_TYPE cmock_line, void* data, Stack* stack);
typedef void (* CMOCK_stackPush_CALLBACK)(void* data, Stack* stack, int cmock_num_calls);
void stackPush_StubWithCallback(CMOCK_stackPush_CALLBACK Callback);
#define stackPush_ExpectAndThrow(data, stack, cmock_to_throw) stackPush_CMockExpectAndThrow(__LINE__, data, stack, cmock_to_throw)
void stackPush_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, void* data, Stack* stack, CEXCEPTION_T cmock_to_throw);
#define stackPop_IgnoreAndReturn(cmock_retval) stackPop_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void stackPop_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, void* cmock_to_return);
#define stackPop_ExpectAndReturn(stack, cmock_retval) stackPop_CMockExpectAndReturn(__LINE__, stack, cmock_retval)
void stackPop_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, Stack* stack, void* cmock_to_return);
typedef void* (* CMOCK_stackPop_CALLBACK)(Stack* stack, int cmock_num_calls);
void stackPop_StubWithCallback(CMOCK_stackPop_CALLBACK Callback);
#define stackPop_ExpectAndThrow(stack, cmock_to_throw) stackPop_CMockExpectAndThrow(__LINE__, stack, cmock_to_throw)
void stackPop_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, Stack* stack, CEXCEPTION_T cmock_to_throw);
#define destroyStack_Ignore() destroyStack_CMockIgnore()
void destroyStack_CMockIgnore(void);
#define destroyStack_Expect(stack) destroyStack_CMockExpect(__LINE__, stack)
void destroyStack_CMockExpect(UNITY_LINE_TYPE cmock_line, Stack* stack);
typedef void (* CMOCK_destroyStack_CALLBACK)(Stack* stack, int cmock_num_calls);
void destroyStack_StubWithCallback(CMOCK_destroyStack_CALLBACK Callback);
#define destroyStack_ExpectAndThrow(stack, cmock_to_throw) destroyStack_CMockExpectAndThrow(__LINE__, stack, cmock_to_throw)
void destroyStack_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, Stack* stack, CEXCEPTION_T cmock_to_throw);

#endif

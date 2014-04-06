/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_OPERATOREVALUATE_H
#define _MOCK_OPERATOREVALUATE_H

#include "operatorEvaluate.h"
#include "CException.h"

void mock_operatorEvaluate_Init(void);
void mock_operatorEvaluate_Destroy(void);
void mock_operatorEvaluate_Verify(void);




#define operatorEvaluate_Ignore() operatorEvaluate_CMockIgnore()
void operatorEvaluate_CMockIgnore(void);
#define operatorEvaluate_Expect(numberStack, opeToken) operatorEvaluate_CMockExpect(__LINE__, numberStack, opeToken)
void operatorEvaluate_CMockExpect(UNITY_LINE_TYPE cmock_line, Stack* numberStack, Operator* opeToken);
typedef void (* CMOCK_operatorEvaluate_CALLBACK)(Stack* numberStack, Operator* opeToken, int cmock_num_calls);
void operatorEvaluate_StubWithCallback(CMOCK_operatorEvaluate_CALLBACK Callback);
#define operatorEvaluate_ExpectAndThrow(numberStack, opeToken, cmock_to_throw) operatorEvaluate_CMockExpectAndThrow(__LINE__, numberStack, opeToken, cmock_to_throw)
void operatorEvaluate_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, Stack* numberStack, Operator* opeToken, CEXCEPTION_T cmock_to_throw);
#define evaluateAllOperatorOnStack_Ignore() evaluateAllOperatorOnStack_CMockIgnore()
void evaluateAllOperatorOnStack_CMockIgnore(void);
#define evaluateAllOperatorOnStack_Expect(numberStack, operatorStack) evaluateAllOperatorOnStack_CMockExpect(__LINE__, numberStack, operatorStack)
void evaluateAllOperatorOnStack_CMockExpect(UNITY_LINE_TYPE cmock_line, Stack* numberStack, Stack* operatorStack);
typedef void (* CMOCK_evaluateAllOperatorOnStack_CALLBACK)(Stack* numberStack, Stack* operatorStack, int cmock_num_calls);
void evaluateAllOperatorOnStack_StubWithCallback(CMOCK_evaluateAllOperatorOnStack_CALLBACK Callback);
#define evaluateAllOperatorOnStack_ExpectAndThrow(numberStack, operatorStack, cmock_to_throw) evaluateAllOperatorOnStack_CMockExpectAndThrow(__LINE__, numberStack, operatorStack, cmock_to_throw)
void evaluateAllOperatorOnStack_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, Stack* numberStack, Stack* operatorStack, CEXCEPTION_T cmock_to_throw);

#endif

/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_TRYEVALUATETHENPUSH_H
#define _MOCK_TRYEVALUATETHENPUSH_H

#include "tryEvaluatethenPush.h"

void mock_tryEvaluatethenPush_Init(void);
void mock_tryEvaluatethenPush_Destroy(void);
void mock_tryEvaluatethenPush_Verify(void);




#define tryEvaluatethenPush_Ignore() tryEvaluatethenPush_CMockIgnore()
void tryEvaluatethenPush_CMockIgnore(void);
#define tryEvaluatethenPush_Expect(token, numberStack, operatorStack) tryEvaluatethenPush_CMockExpect(__LINE__, token, numberStack, operatorStack)
void tryEvaluatethenPush_CMockExpect(UNITY_LINE_TYPE cmock_line, Token* token, Stack* numberStack, Stack* operatorStack);
typedef void (* CMOCK_tryEvaluatethenPush_CALLBACK)(Token* token, Stack* numberStack, Stack* operatorStack, int cmock_num_calls);
void tryEvaluatethenPush_StubWithCallback(CMOCK_tryEvaluatethenPush_CALLBACK Callback);

#endif

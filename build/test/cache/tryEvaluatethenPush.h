#include "Stack.h"
#include "Evaluate.h"










void tryEvaluateOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack);

void tryEvaluatePrefixOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack);

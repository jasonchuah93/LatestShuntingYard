#include "Stack.h"
#include "Evaluate.h"










void operatorEvaluate(Stack *numberStack , Operator *opeToken);

void evaluateAllOperatorOnStack(Stack *numberStack,Stack *operatorStack);

void operatorPrefixEvaluate(Stack *numberStack , Operator *opeToken1);

void evaluatePrefixOperatorOnStack(Stack *numberStack,Stack *operatorStack);

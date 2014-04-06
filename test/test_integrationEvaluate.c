#include "unity.h"

void setUp(void){}
void tearDown(void){}

/*********************************************************************************************************************************
 Test on function evaluate
 Input parameter : 
					1)char *expression

 Using following real function : 

								1)stringCreate()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
								6)operatorEvaluate(Stack *numberStack , Operator *opeToken);
								7)evaluateAllOperatorOnStack(Stack *numberStack,Stack *operatorStack);
								8)tryEvaluateOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack);
								9)calculate(Operator *opeToken, Number *first , Number *second);

********************************************************************************************************************************/	


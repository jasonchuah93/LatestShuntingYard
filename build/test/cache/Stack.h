#include "LinkedList.h"








typedef struct

{



 Element *topOfStack;



}Stack;





Stack *createStack();

void stackPush(void * data,Stack *stack);

void *stackPop(Stack *stack);

void destroyStack(Stack *stack);

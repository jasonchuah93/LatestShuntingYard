









typedef struct

{

 void *topOfStack;



}Stack;



Stack *createStack();

void stackPush(void *newMember,Stack *stack);

void * stackPop(Stack *stack);

void destroyStack(Stack *stack);







typedef struct Element_t

{

 struct Element_t *next;

 void *data;

}Element;





typedef struct

{



 Element *topOfStack;



}Stack;





Stack *createStack();

void stackPush(void * data,Stack *stack);

void *stackPop(Stack *stack);

void destroyStack(Stack *stack);

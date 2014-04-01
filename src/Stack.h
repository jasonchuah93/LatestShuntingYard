#ifndef __STACK_H__
#define __STACK_H__

typedef struct Element_t
{
	struct Element_t *next;
	void *data;
}Element;


typedef struct
{
	
	Element *topOfStack;

}Stack;

//Function declaration
Stack *createStack();
void stackPush(void * data,Stack *stack);
void *stackPop(Stack *stack);
void destroyStack(Stack *stack);
#endif //__STACK_H__
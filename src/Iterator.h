#ifndef Iterator_H
#define Iterator_H
#include "LinkedList.h"

typedef struct {
	LinkedList *list;
	Element *current;
	Element *(*next)(Element *);
} Iterator;

typedef struct DefineElement_t{
	struct DefineElement_t *next;
	char *ID;
	char *actualID;
}DefineElement;

void *getIterator(LinkedList *list);
void *getNext(void);

#endif // Iterator_H

#ifndef Iterator_H
#define Iterator_H

#include "LinkedList.h"

typedef struct {
	LinkedList *list;
	void *current;
	void *(*next)(void);
} Iterator;

//Element that Ee pak use to store identifier value.
typedef struct DefineElement_t{
	struct DefineElement_t *next;
	char *ID;
	char *actualID;
}DefineElement;

LinkedList  *createLinkedList();
void List_Add(Element *newElement , LinkedList *list);
Element *List_removeLast(LinkedList *list);
Element List_addFirst(Element *newElement,LinkedList *list);
Element *List_removeFirst(LinkedList *list);
void List_DestroyList(LinkedList *list);

#endif // Iterator_H


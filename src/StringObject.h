#ifndef __STRING_OBJECT_H__
#define __STRING_OBJECT_H__

#include "Evaluate.h"
// Function Prototype
String *stringCreate(char *expression);
void stringCopy(char *source, char*destination, int startLocation, int length);

#endif // __STRING_OBJECT_H__

 
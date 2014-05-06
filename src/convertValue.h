#ifndef convertValue_H
#define convertValue_H


#include "Evaluate.h"
#include "Iterator.h"
#include "StringObject.h"
#include "GetElement.h"

String* getFromListAndUpdate(String *beforeUpdate, char *name);
String * convertBasedNumberToBase10Number(String *input);

#endif // convertValue_H

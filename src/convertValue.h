#ifndef convertValue_H
#define convertValue_H


#include "Evaluate.h"
#include "Iterator.h"
#include "GetElement.h"
#include "StringObject.h"

String* getFromListAndUpdate(String *beforeUpdate, char *name);
String * convertBasedNumberToBase10Number(String *input);

#endif // convertValue_H

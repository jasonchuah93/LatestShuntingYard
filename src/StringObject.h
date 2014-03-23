#ifndef __STRING_OBJECT_H__
#define __STRING_OBJECT_H__

typedef struct {
	char *rawString;
	int startIndex;
	int length;
} String;

// Function Prototype
String *stringCreate(char *expression);


#endif // __STRING_OBJECT_H__

 
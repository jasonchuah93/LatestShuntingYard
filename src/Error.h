#ifndef __ERROR_H__
#define __ERROR_H__


typedef enum {INVALID_IDENTIFIER,UNKNOWN_OPERATOR,UNDEFINED_IDENTIFIER,ERR_INVALID_EXPRESSION,UNKNOWN_DATA} ErrorCode;

typedef struct{
	char *rawString;
	int position;
	char *message;
	
}ErrorMessage;

extern ErrorMessage errorMessage;
#endif //__ERROR_H__
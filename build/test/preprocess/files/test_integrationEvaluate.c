#include "unity.h"
#include "tryEvaluatethenPush.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "mock_StringObject.h"
#include "getToken.h"
#include "createNumberToken.h"
#include "calculateToken.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Evaluate.h"
#include "Error.h"
#include "CException.h"








void setUp(void){}

void tearDown(void){}

void test_should_return_3_for_1_plus_2(void){

 int check;



 String tokenizer = {.rawString = "1+2", .startIndex = 0, .length=3};



 stringCreate_CMockExpectAndReturn(46, "1+2", &tokenizer);



 check=evaluate("1+2");

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_should_return_6_for_60_divide_10(void){



 int check;



 String tokenizer = {.rawString = "60/10", .startIndex = 0, .length=3};



 stringCreate_CMockExpectAndReturn(59, "60/10", &tokenizer);



 check=evaluate("60/10");

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_evaluate_2_MULTIPLY_3_PLUS_4(void){



 int check;



 String tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};









 stringCreate_CMockExpectAndReturn(75, "2*3+4", &tokenizer);





 check=evaluate("2*3+4");

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){

 int check;



 String tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};





 stringCreate_CMockExpectAndReturn(90, "2+3*4+5*6", &tokenizer);



 check=evaluate("2+3*4+5*6");

 UnityAssertEqualNumber((_U_SINT)((44)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){

 int check;



 String tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};





 stringCreate_CMockExpectAndReturn(103, "2*3+4*5+6", &tokenizer);



 check=evaluate("2*3+4*5+6");

 UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){



 int check;

 String tokenizer = {.rawString = "2|3+4*5-6-10", .startIndex = 0, .length = 11};





 stringCreate_CMockExpectAndReturn(116, "2|3+4*5-6-10", &tokenizer);





 check=evaluate("2|3+4*5-6-10");

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10_OR_10_AND_53_XOR_21(void){



 int check;

 String tokenizer = {.rawString = "2|3+4*5-6-10|10&53^21", .startIndex = 0, .length = 17};





 stringCreate_CMockExpectAndReturn(130, "2|3+4*5-6-10|10&53^21", &tokenizer);





 check=evaluate("2|3+4*5-6-10|10&53^21");

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_evaluate_with_different_expression(void){

 int check;

 String tokenizer = {.rawString = "2|3+4*5-6-10|10&53^21+95%6^200%5*80", .startIndex = 0, .length = 27};





 stringCreate_CMockExpectAndReturn(143, "2|3+4*5-6-10|10&53^21+95%6^200%5*80", &tokenizer);





 check=evaluate("2|3+4*5-6-10|10&53^21+95%6^200%5*80");

 UnityAssertEqualNumber((_U_SINT)((31)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_evaluate_with_longer_expression(void){

 int check;

 String tokenizer = {.rawString = "2|3&4^5|6^10|10&53^21&95|6^200&5|80", .startIndex = 0, .length = 27};





 stringCreate_CMockExpectAndReturn(156, "2|3&4^5|6^10|10&53^21&95|6^200&5|80", &tokenizer);





 check=evaluate("2|3&4^5|6^10|10&53^21&95|6^200&5|80");

 UnityAssertEqualNumber((_U_SINT)((84)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_should_evaluate_left_parenthesis_2_right_parenthesis(void){



 int check;

 int e;



 String tokenizer = {.rawString = "(2)", .startIndex = 0, .length = 3};



 stringCreate_CMockExpectAndReturn(171, "(2)", &tokenizer);





 check=prefixEvaluate("(2)");

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left_parenthesis_22_right_parenthesis(void){

 int check;

 int e;



 String tokenizer = {.rawString = "(22)", .startIndex = 0, .length = 3};



 stringCreate_CMockExpectAndReturn(186, "(22)", &tokenizer);



 check=prefixEvaluate("(22)");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left__left_parenthesis_22_right_right_parenthesis(void){

 int check;

 int e;



 String tokenizer = {.rawString = "((22))", .startIndex = 0, .length = 5};



 stringCreate_CMockExpectAndReturn(200, "((22))", &tokenizer);



 check=prefixEvaluate("((22))");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left__left_left_parenthesis_16_right_right_right_parenthesis(void){

 int check;

 int e;



 String tokenizer = {.rawString = "(((16)))", .startIndex = 0, .length = 6};



 stringCreate_CMockExpectAndReturn(214, "(((16)))", &tokenizer);



 check=prefixEvaluate("(((16)))");

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)217, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}

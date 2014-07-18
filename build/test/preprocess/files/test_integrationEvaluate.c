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

 String tokenizer = {.rawString = "2|3&4^5|6^10|10&53^21&95|6^200&5|80"};





 stringCreate_CMockExpectAndReturn(156, "2|3&4^5|6^10|10&53^21&95|6^200&5|80", &tokenizer);





 check=evaluate("2|3&4^5|6^10|10&53^21&95|6^200&5|80");

 UnityAssertEqualNumber((_U_SINT)((84)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_should_evaluate_left_parenthesis_2_right_parenthesis(void){



 int check;

 int e;



 String tokenizer = {.rawString = "(2)"};



 stringCreate_CMockExpectAndReturn(171, "(2)", &tokenizer);





 check=evaluate("(2)");

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left_parenthesis_100_right_parenthesis(void){

 int check;

 int e;



 String tokenizer = {.rawString = "(100)"};



 stringCreate_CMockExpectAndReturn(186, "(100)", &tokenizer);



 check=evaluate("(100)");

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left_parenthesis_100_plus_100_divide_20_right_parenthesis(void){

 int check;

 int e;



 String tokenizer = {.rawString = "(100-60/20)"};



 stringCreate_CMockExpectAndReturn(200, "(100-60/20)", &tokenizer);



 check=evaluate("(100-60/20)");

 UnityAssertEqualNumber((_U_SINT)((97)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left_left_parenthesis_22_right_right_parenthesis(void){

 int check;

 int e;



 String tokenizer = {.rawString = "((22))"};



 stringCreate_CMockExpectAndReturn(214, "((22))", &tokenizer);



 check=evaluate("((22))");

 UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)217, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left_left_left_parenthesis_55_right_right_right_parenthesis(void){

 int check;

 int e;



 String tokenizer = {.rawString = "(((55)))", .startIndex = 0, .length = 6};



 stringCreate_CMockExpectAndReturn(228, "(((55)))", &tokenizer);



 check=evaluate("(((55)))");

 UnityAssertEqualNumber((_U_SINT)((55)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_10_multiply_left_parenthesis_6_plus_2_right_parenthesis(void){

 int check;

 int e;



 String tokenizer = {.rawString = "10*(6+2)", };



 stringCreate_CMockExpectAndReturn(242, "10*(6+2)", &tokenizer);



 check=evaluate("10*(6+2)");

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)245, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_should_evaluate_left_parenthesis_10_divide_5_right_parenthesis_multiply_left_parenthesis_6_plus_2_right_parenthesis(void){

 int check;

 int e;



 String tokenizer = {.rawString = "(10/5)*(6+2)", };



 stringCreate_CMockExpectAndReturn(256, "(10/5)*(6+2)", &tokenizer);



 check=evaluate("(10/5)*(6+2)");

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_left_left_left_bracket_20_plus_60_divide_4_right_right_right_bracket(void){

 int check;



 String tokenizer = {.rawString = "(((20+60/4)))"};



 stringCreate_CMockExpectAndReturn(269, "(((20+60/4)))", &tokenizer);



 check=evaluate("(((20+60/4)))");

 UnityAssertEqualNumber((_U_SINT)((35)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)272, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_left_bracket_6_plus_97_right_bracket_multiply_30(void){

 int check;



 String tokenizer = {.rawString = "(6+97)*30"};



 stringCreate_CMockExpectAndReturn(281, "(6+97)*30", &tokenizer);



 check=evaluate("(6+97)*30");

 UnityAssertEqualNumber((_U_SINT)((3090)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_one_minus_hundred(void){

 int check;



 String tokenizer = {.rawString = "1-100"};



 stringCreate_CMockExpectAndReturn(293, "1-100", &tokenizer);



 check=evaluate("1-100");

 UnityAssertEqualNumber((_U_SINT)((-99)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)296, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_evaluate_positive_fifty(void){

 int check;



 String tokenizer = {.rawString = "+50"};



 stringCreate_CMockExpectAndReturn(305, "+50", &tokenizer);



 check=evaluate("+50");

 UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)308, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_evaluate_negative_hundred(void){

 int check;



 String tokenizer = {.rawString = "-100"};



 stringCreate_CMockExpectAndReturn(317, "-100", &tokenizer);



 check=evaluate("-100");

 UnityAssertEqualNumber((_U_SINT)((-100)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)320, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_evaluate_multiply_ten_should_return_error(void){

 int check,e;



 String tokenizer = {.rawString = "*10"};



 stringCreate_CMockExpectAndReturn(329, "*10", &tokenizer);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("*10");

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)334, UNITY_DISPLAY_STYLE_INT);

  return;

 }



}



void test_evaluate_80_multiply_should_return_error(void){

 int check,e;



 String tokenizer = {.rawString = "80*"};



 stringCreate_CMockExpectAndReturn(345, "80*", &tokenizer);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("80*");

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT);

  return;

 }



}



void test_evaluate_50_add_should_return_error(void){

 int check,e;



 String tokenizer = {.rawString = "50+"};



 stringCreate_CMockExpectAndReturn(361, "50+", &tokenizer);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("50+");

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((UNKNOWN_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)366, UNITY_DISPLAY_STYLE_INT);

  return;

 }



}



void test_NEGATIVE_2_NEGATIVE_3_SHOULD_RETURN_NEGATIVE_6(void){



 Stack numStack;

 Stack opeStack;

 int check;





 String tokenizer = {.rawString = "-2*3", .startIndex = 0, .length = 4 };



 stringCreate_CMockExpectAndReturn(381, "-2*3", &tokenizer);



 check=evaluate("-2*3");

 UnityAssertEqualNumber((_U_SINT)((-6)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)384, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}



void test_LEFT_PARENTHESIS_10_MULTIPLY_100_RIGHT_PARENTHESIS_DIVIDE_BY_LEFT_PARENTHESIS_LEFT_PARENTHESIS_NEGATIVE_5_MULTIPLY_6_RIGHT_PARENTHESIS_SUBTRACT_LEFT_PARENTHESIS_2_MINUS_30_RIGHT_PARENTHESIS_RIGHT_PARENTHESIS(void) {



 Stack numStack;

 Stack opeStack;

 int check;



 String tokenizer = {.rawString = "(10*100)/((5*6)-(2-30))", .startIndex = 0, .length = 24 };





 stringCreate_CMockExpectAndReturn(398, "(10*100)/((5*6)-(2-30))", &tokenizer);



 check=evaluate("(10*100)/((5*6)-(2-30))");

 UnityAssertEqualNumber((_U_SINT)((17)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)401, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);







}



void test_NEGATIVE_LEFT_PARENTHESIS_NEGATIVE_2_RIGHT_PARENTHESIS(void){



 Stack numStack;

 Stack opeStack;

 int check;



 String tokenizer = {.rawString = "-(-2)", .startIndex = 0, .length = 5 };





 stringCreate_CMockExpectAndReturn(417, "-(-2)", &tokenizer);



 check=evaluate("-(-2)");

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)420, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_NEGATIVE_LEFT_PARENTHESIS_POSITIVE_LEFT_PARENTHESIS_NEGATIVE_LEFT_PARENTHESIS__NEGATIVE_1_RIGHT_PARENTHESIS_MULTIPLY_3_RIGHT_PARENTHESIS_SUBTRACT_FOUR_RIGHT_PARENTHESIS(void){



 Stack numStack;

 Stack opeStack;

 int check;



 String tokenizer = {.rawString = "-(+(-(-1)*3)-4)", .startIndex = 0, .length = 15 };





 stringCreate_CMockExpectAndReturn(433, "-(+(-(-1)*3)-4)", &tokenizer);



 check=evaluate("-(+(-(-1)*3)-4)");

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)436, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_negative_space_two(void){

 Stack numStack;

 Stack opeStack;

 int check;



 String tokenizer = {.rawString = "-     14"};





 stringCreate_CMockExpectAndReturn(448, "-     14", &tokenizer);



 check=evaluate("-     14");

 UnityAssertEqualNumber((_U_SINT)((-14)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)451, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_LOGIC_NOT_twelve(void){

 Stack numStack;

 Stack opeStack;

 int check;



 String tokenizer = {.rawString = "!12"};





 stringCreate_CMockExpectAndReturn(463, "!12", &tokenizer);



 check=evaluate("!12");

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)466, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void xtest_LOGIC_NOT_LOGIC_NOT_twelve(void){

 Stack numStack;

 Stack opeStack;

 int check;



 String tokenizer = {.rawString = "!!12"};





 stringCreate_CMockExpectAndReturn(478, "!!12", &tokenizer);



 check=evaluate("!!12");

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)481, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void xtest_minus_minus_five(void){

 Stack numStack;

 Stack opeStack;

 int check;



 String tokenizer = {.rawString = "--5"};





 stringCreate_CMockExpectAndReturn(493, "--5", &tokenizer);



 check=evaluate("--5");

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)496, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}

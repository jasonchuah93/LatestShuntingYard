#include "unity.h"
#include "stackForEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_operatorEvaluate.h"
#include "mock_initializeToken.h"
#include "mock_getToken.h"
#include "mock_Stack.h"
#include "createNumberToken.h"
#include "calculateToken.h"
#include "Evaluate.h"




void setUp(void){}

void tearDown(void){}







void test_should_calculate_2_PLUS_3()

{

 int check;

 Operator plus={.type=OPERATOR,.id=ADD};

 Number two={.type=NUMBER,.value=2};

 Number three={.type=NUMBER,.value=3};



 check=calculate(&plus,&two,&three);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);



}



void test_should_calculate_10_MINUS_3()

{

 int check;

 Operator subtract={.type=OPERATOR,.id=SUBTRACT};

 Number ten={.type=NUMBER,.value=10};

 Number three={.type=NUMBER,.value=3};



 check=calculate(&subtract,&ten,&three);



 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

}



void test_should_calculate_10_MULTIPLY_10()

{

 int check;

 Operator multiply={.type=OPERATOR,.id=MULTIPLY};

 Number ten={.type=NUMBER,.value=10};

 Number ten1={.type=NUMBER,.value=10};



 check=calculate(&multiply,&ten,&ten1);



 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

}



void test_should_calculate_1000_DIVIDE_10()

{

 int check;

 Operator divide={.type=OPERATOR,.id=DIVIDE};

 Number thousand={.type=NUMBER,.value=1000};

 Number ten={.type=NUMBER,.value=10};



 check=calculate(&divide,&thousand,&ten);



 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

}

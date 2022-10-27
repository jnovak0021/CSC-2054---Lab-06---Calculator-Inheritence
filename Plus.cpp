#include "Plus.h"
#include <string>


//override operator of Operator class -- tkaes in two numbers, returns sum of two pointers
Number * Plus::operate(Number* num1, Number* num2)
{
	//set numSum to hold value of sum of Number *
	num1->setValue(num1->getValue() + num2->getValue());
	return num1;
}

int Plus::getValue()
{
	return 0;
}

//toString
string Plus::toString()
{
	return "+";
}

void Plus::setValue(int numIn) 
{

}
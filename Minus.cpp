#include "Minus.h"
#include <string>


//overridden operator function -- takes in two Number* parameters -- returns difference of two parameters
Number* Minus::operate(Number* num1, Number* num2)
{
	num1->setValue(num1->getValue() - num2->getValue());
	return num1;
}

int Minus::getValue()
{
	return 1;
}

string Minus::toString()
{
	return "-";
}

void Minus:: setValue(int numIn) 
{

}
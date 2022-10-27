#include "Number.h"
#include <string>

//Numebr constructer, sets value to param input
Number::Number(int valueIn): Token()
{
	value = valueIn;
}

//to string method to return value of Number -- return string representation of number
string Number::toString()
{
	return to_string(value);
}

//decleartion of getValue()
int Number::getValue()
{
	return value;
}

//decleration of setValue()
void Number::setValue(int valueIn)
{
	value = valueIn;
}
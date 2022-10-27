#pragma once
#include "Token.h"
#include "Number.h"

class Operator: public Token
{
public:
	
	//abstract function which takes in two Number * and retunrs a Number *
	virtual Number* operate(Number* num1, Number* num2) = 0;

	//overridden setValue function
	void setValue(int numIn);
	//overrden getValue
	int getValue();
};
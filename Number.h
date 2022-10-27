#pragma once
#include "Token.h"

//clas Number and function declerations
class Number: public Token
{
public:
	//constructor that takes in and int
	Number(int valueIn);

	//overriden toString function 
	string toString();

	//decleartion of overridden getValue()
	int getValue();

	//decleration of ovverriden setValue()
	void setValue(int valueIn);
private:
	//private int to store value of number
	int value = 0;
};
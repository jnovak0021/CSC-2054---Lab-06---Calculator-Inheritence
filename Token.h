#pragma once
#include <iostream>
#include <string>

using namespace std;

class Token
{
public:
	//decleration of abstract toString class -- return a string representation of the token
	virtual string toString() = 0;

	//decleration of abstract getValue function
	virtual int getValue() = 0;

	//decleration of abstract function  setVlaue which takes in an int param
	virtual void setValue(int numIn) = 0;
private:
};
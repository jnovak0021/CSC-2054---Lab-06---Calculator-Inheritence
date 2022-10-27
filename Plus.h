#include "Operator.h"


class Plus : public Operator
{
public:
	//overidden function operate of Operator class -- return Number *
	Number* operate(Number* num1, Number* num2);

	//overridden toString method - return string
	string toString();

	//overridden functions of token
	int getValue();
	void setValue(int numIn);
private:
};
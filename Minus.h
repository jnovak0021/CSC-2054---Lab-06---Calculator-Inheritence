#include "Operator.h"

//decleration of Minus class and members and functions -- inherets from Operator
class Minus : public Operator
{
public:
	//overridden operator function -- takes in two Number* parameters -- returns difference of two parameters
	Number* operate(Number* num1, Number* num2);

	//overridden toString function
	string toString();

	//overridden functions of token
	int getValue();
	void setValue(int numIn);
private:
};

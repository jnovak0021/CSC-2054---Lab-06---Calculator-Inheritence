#include <iostream>
#include <vector>
#include <string>
#include "Token.h"
#include "Plus.h"
#include "Minus.h"

using namespace std;

//polymorhism vector to hold numbers and operators
vector <Token*>  tokenVector;
//decleration of printExpression
void printExpression();
//decleration of isValidExpression
bool isValidExpression();
//decleration of calculateResult
void calculateResult();
//decleration of getResult
void getResult();
int main()
{
	//store user input 
	string userEquation = " ";

	//store value read in by user input
	string tempStr = " ";
	//char eqChar to store value of userEquation at i
	char eqChar = ' ';
	//ask user to enter in an expression terminated by a ; with spaces between numbers and operators
	cout << "Enter a list of tokens, terminate by entering ;" << endl;
	//SENTINAL SEMICOLON loop -- loop until semi colon inputted
	while (1 == 1)
	{
		//read in string and store in tempStr
		cin >> tempStr;
		//if tempStr is semicolon, break loop
		if (tempStr == ";")
			break;
		//add tempStr to end of string userEquation
		userEquation += tempStr + " ";
	}


	//for loop to loop through array to populate tokenVector with objects 
	for (int i = 0; i < userEquation.size(); i++)
	{

			//store char at i of userEqation at eqChar
			eqChar = userEquation.at(i);
			//if char is a +, add a new Plus instance to end of tokenVector
			if (eqChar == '+')
			{
				tokenVector.push_back(new Plus());
			}
			//if char is a -, add a new Minus instance to end of tokenVector
			else if (eqChar == '-')
			{
				tokenVector.push_back(new Minus());
			}
			//convert char to a number and add Number token to vector
			else if(eqChar != ' ')
			{
			
				//int to keep track of while loop
				int count = 0;

				//temporary string variable to store the value of the int
				string tmpStr;
				
				//set eqChar to char of userEquation.at(i)
				eqChar = userEquation.at(i);
				
				//while eqChar is not a space, keep appending chars of int 
				while(eqChar != ' ')
				{
					//add eqChar to end of tmpStr
					tmpStr.push_back(eqChar);
					//increment count
					count++;
					//set eqChar equal to next char of userEquation
					eqChar = userEquation.at(i + count);
				}
				
				//icrement i by count - 1 so values aren't reread
				i += count - 1;
		
				//add Number object to end of Token * vector tokenVector
				tokenVector.push_back(new Number(stoi(tmpStr)));
			}

	} 

	//print out expression by calling printExpression function
	printExpression();

	//if expression if valid calculate total, otherwise tell user it is bad and do not perform operations
		if (isValidExpression())
		{
		
			//calculate the result of the expression
			calculateResult();
			//get result
			getResult();
		}
		else
			cout << "Not A valid expression" << endl;
	//DEALLOCATE VECTOR
	//for loop to deallocate tokenVector
	for (int i = 0; i < tokenVector.size(); i++)
	{
		delete (Token *)tokenVector.at(i);
	}
}
//function to print out the expression
void printExpression()
{
	//for loop to print vector
	for (int i = 0; i < tokenVector.size(); i++)
	{
		cout << tokenVector.at(i)->toString() << " ";
	}
	cout << endl;
}
//function to determine if token * vector tokenVector is holding a valid expression
bool isValidExpression()
{
	//for loop to traverse vector tokenVector
	for (int i = 0; i < tokenVector.size(); i++)
	{
		//if i is divisible by 2 check to see if object at tokenVector.at(i) is of type number-- if not, return false
			if (i % 2 == 0)
			{
				if (typeid(*(tokenVector.at(i))) == typeid(Number)) {}
				else
					return false;
			}	
		//if i is an odd index -- should be an operator Minus or plus -- otherwise return false
			else
			{
				if (typeid(*(tokenVector.at(i))) == typeid(Minus) ||
					typeid(*(tokenVector.at(i))) == typeid(Plus))
				{
				
				}
				else
					return false;

			}
			

			//make sure last value is a number
			if (i == tokenVector.size() - 1)
			{
		
				if (typeid(*(tokenVector.at(i))) == typeid(Number))
				{
				}
				else
					return false;
			}
	}
	return true;
}
//function to calculate final result
void calculateResult()
{
	//for loop till end of tokenVector
	for (int i = 0; i < tokenVector.size(); i++)
	{
		//if tokenVector.at(i) is of type Minus
		if (typeid(*(tokenVector.at(i))) == typeid(Minus))
		{
			//create temporary instance pointer of Minus
			Minus* tempM = new Minus();
			//set rightmost value of Minus to be the result of the Minus.operate function on i - 1 and i + 1
				tokenVector.at(i + 1) = (tempM->operate((Number*)tokenVector.at(i - 1), (Number*)tokenVector.at(i + 1)));
			//delete tempM
			delete tempM;
		}
		//if tokenVector.at(i) is of type Plus
		if (typeid(*(tokenVector.at(i))) == typeid(Plus))
		{
			//create temporary instance pointer of Plus
			Plus* tempP = new Plus();
			//set rightmost value of Plus to be the result of the Plus.operate function on i - 1 and i + 1
				tokenVector.at(i + 1) = (tempP->operate((Number*)tokenVector.at(i - 1), (Number*)tokenVector.at(i + 1)));
			//delete tempM
			delete tempP;
		}
	}
}
//function to print final result of equation
void getResult()
{
	//get last index of tokenVector which holds final value of expression
	cout << "Answer is " << tokenVector.at(tokenVector.size() - 1)->getValue();
}

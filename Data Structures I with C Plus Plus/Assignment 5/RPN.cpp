//******************************************************************
//
//		File:			RPN.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment #5 Part 1
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			March 1, 2018
//
//		This program uses a templated linked stack
//		structure to process and evaluate RPN expressions
//		provided from a file.
//		
//******************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Stack.h"
using namespace std;

//******************************************************************
//********************* Function Prototypes ************************
//******************************************************************
void getData(Stack<string>&);
void processInput(Stack<string>&);
void processExpression(string, ofstream&);
void calculateExpression(Stack<int>&, string, ofstream&);
bool processNumber(Stack<int>&, string, ofstream&);
void displayResult(Stack<int>&, ofstream& outFile);

//******************************************************************
//************************ Main Function ***************************
//******************************************************************
int main()
{
	Stack<string> inputStack;
	getData(inputStack);
	processInput(inputStack);

	return 0;
}

//******************************************************************
//*********************** getData Function *************************
//******************************************************************
void getData(Stack<string>& inputStack)
{
	ifstream inFile("RPNExpressions.txt");
	if (!inFile)
	{
		cout << "Problem opening RPNExpressions.txt file." << endl;
		exit(99);
	}

	while (!inFile.eof()) 
	{
		string input;
		getline(inFile, input);
		inputStack.push(input);
	}
	inFile.close();
}

//******************************************************************
//******************* processInput Function ************************
//******************************************************************
void processInput(Stack<string>& inputStack)
{
	ofstream outFile("RPNResults.txt");

	while (!inputStack.empty()) 
	{
		string expression = inputStack.getTop();
		inputStack.pop();

		outFile << "\nInput Expression: " << expression << endl;
		processExpression(expression, outFile);
	}
	outFile.close();
}

//******************************************************************
//***************** processExpression Function *********************
//******************************************************************
void processExpression(string expression, ofstream& outFile)
{
	Stack<int> stack;
	calculateExpression(stack, expression, outFile);
	displayResult(stack, outFile);
}

//******************************************************************
//******************** displayList Function ************************
//******************************************************************
void displayResult(Stack<int>& stack, ofstream& outFile)
{
	int result;
	bool valid = false;
	if (!stack.empty())
	{
		result = stack.getTop();
		stack.pop();
		valid = true;
	}

	if (stack.empty() && valid)
	{
		outFile << "\nThis is a valid RPN expression.\n";
		outFile << "\nThe result is " << result << ".\n\n";
	}
	else
	{
		if (!stack.empty())
		{
			outFile << "\nNot enough operators.\n\n";
		}
		outFile << "This is an invalid RPN expression.\n\n";
	}
}

//******************************************************************
//******************* processNumber Function ***********************
//******************************************************************
bool processNumber(Stack<int>& stack, string num, ofstream& outFile)
{
	char ch;
	int a, b, result;
	ch = num[0];

	switch (ch)
	{
		case '+':
		{	
			if (stack.empty()) 
			{ 
				outFile << "\nNot enough operands.\n\n"; 
				return false; 
			}
			a = (stack.getTop());
			stack.pop();
			outFile << "\n(Token +): Pop " << a;

			if (stack.empty()) 
			{ 
				outFile << "\n\nNot enough operands.\n\n"; 
				return false; 
			}
			b = (stack.getTop());
			stack.pop();
			outFile << " Pop " << b;

			result = a + b;
			stack.push(result);
			outFile << " Push " << result << endl;
			break;
		}

		case '-':
		{	
			if (stack.empty())
			{ 
				outFile << "\nNot enough operands.\n\n"; 
				return false;
			}
			a = (stack.getTop());
			stack.pop();
			outFile << "\n(Token -): Pop " << a;

			if (stack.empty())
			{ 
				outFile << "\n\nNot enough operands.\n\n";
				return false; 
			}
			b = (stack.getTop());
			stack.pop();
			outFile << " Pop " << b;

			result = b - a;
			stack.push(result);
			outFile << " Push " << result << endl;
			break;
		}

		case '*':
		{	
			if (stack.empty())
			{
				outFile << "\nNot enough operands.\n\n";
				return false;
			}
			a = (stack.getTop());
			stack.pop();
			outFile << "\n(Token *): Pop " << a;

			if (stack.empty())
			{
				outFile << "\n\nNot enough operands.\n\n";
				return false;
			}
			b = (stack.getTop());
			stack.pop();
			outFile << " Pop " << b;

			result = b * a;
			stack.push(result);
			outFile << " Push " << result << endl;
			break;
		}

		case '/':
		{	
			if (stack.empty())
			{ 
				outFile << "\nNot enough operands.\n\n"; 
				return false; 
			}
			a = (stack.getTop());
			stack.pop();
			outFile << "\n(Token /): Pop " << a;

			if (stack.empty()) 
			{ 
				outFile << "\n\nNot enough operands.\n\n"; 
				return false; 
			}
			b = (stack.getTop());
			stack.pop();
			outFile << " Pop " << b;

			result = b / a;
			stack.push(result);
			outFile << " Push " << result << endl;
			break;
		}

		case '%':
		{	
			if (stack.empty())
			{ 
				outFile << "\nNot enough operands.\n\n";
				return false;
			}
			a = (stack.getTop());
			stack.pop();
			outFile << "\n(Token %): Pop " << a;

			if (stack.empty())
			{ 
				outFile << "\n\nNot enough operands.\n\n"; 
				return false;
			}
			b = (stack.getTop());
			stack.pop();
			outFile << " Pop " << b;

			result = b % a;
			stack.push(result);
			outFile << " Push " << result << endl;
			break;
		}

		default:
		{
			a = atoi(num.c_str());
			stack.push(a);
			outFile << "\n(Token " << a << "):" << " Push " << a << endl;
		}
	}
	return true;
}

//******************************************************************
//**************** calculateExpression Function ********************
//******************************************************************
void calculateExpression(Stack<int>& stack, string expression, ofstream& outFile)
{
	int position = 0;
	string delimiter = " ";
	string num;
	bool valid = true;

	while ((position = expression.find(delimiter)) != string::npos)
	{
		num = expression.substr(0, position);

		expression.erase(0, position + delimiter.length());

		if (!processNumber(stack, num, outFile))
		{
			valid = false;
			break;
		}
	}

	if (valid)
	{
		processNumber(stack, expression, outFile);
	}
}
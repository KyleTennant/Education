//************************************************************
//
//		File:			Palindrome.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment #6 Option 1
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			March 8, 2018
//
//		This program checks the input for a Palindrome
//		using a stack and a queue.
//		
//************************************************************
#include <iostream>
#include <string>
#include "Queue.h"
#include "Stack.h"
using namespace std;

string checkPal(string);

//************************************************************
int main()
{
	string input;

	while (true) 
	{
		cout << "Enter your expressions to check if it is Palindrome: ";
		getline(cin, input);
		if (input.empty()) break;
			cout << checkPal(input);
	}
	
	return 0;
}

//************************************************************
string checkPal(string input) 
{
	Stack<char> stack;
	Queue<char> queue;

	for (int i = 0; i < input.size(); i++)
	{
		if (isalnum(input[i]))
		{
			if (isalpha(input[i]))
			{
				input[i] = tolower(input[i]);
				stack.push(input[i]);
				queue.enqueue(input[i]);
			}
			else
			{
				stack.push(input[i]);
				queue.enqueue(input[i]);
			}
		}
	}

	bool isPal = true;

	while (!stack.empty() && !queue.empty()) 
	{
		char front, back;
		front = queue.getFront();
		queue.dequeue();
		back = stack.getTop();
		stack.pop();
		if (front != back)
		{
			isPal = false;
			break;
		}
	}

	return isPal ? (input + " is a Palindrome.\n\n") : (input + " is not a Palindrome.\n\n");
}
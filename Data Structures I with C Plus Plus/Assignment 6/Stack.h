//************************************************************
//
//		File:			Stack.h
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
#include <string>
using namespace std;
#ifndef STACK_H
#define STACK_H

//************************************************************
template<class DT>
struct NodeStack
{
	DT info;
	NodeStack *next;
};

//************************************************************
template<class DT>
class Stack
{
	private:
		NodeStack<DT> *top;
	public:
		Stack();
		~Stack();
		bool empty();
		void push(DT& obj);
		DT getTop();
		bool pop();
};
#endif

//************************************************************
template<class DT>
Stack<DT>::Stack()
{
	top = nullptr;
}

//************************************************************
template<class DT>
Stack<DT>::~Stack()
{
	while (!empty())
		pop();
}

//************************************************************
template<class DT>
bool Stack<DT>::empty()
{
	return top == NULL;
}

//************************************************************
template<class DT>
void Stack<DT>::push(DT& obj)
{
	NodeStack<DT> *ptr = new NodeStack<DT>;
	ptr->info = obj;
	ptr->next = top;
	top = ptr;
}

//************************************************************
template<class DT>
DT Stack<DT>::getTop()
{
	return top->info;
}

//************************************************************
template<class DT>
bool Stack<DT>::pop()
{
	if (!empty())
	{
		NodeStack<DT> *ptr = top;
		DT obj = ptr->info;
		top = top->next;
		delete ptr;
		return true;
	}
	return false;
}
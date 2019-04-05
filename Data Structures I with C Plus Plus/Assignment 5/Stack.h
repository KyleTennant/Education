//************************************************************
//
//		File:			Stack.h
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment #5 Part 1 & 2
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			March 1, 2018
//
//		This header file is a linked stack structure template
//		for part 1 and 2 of assignment 5.
//		
//************************************************************
#include <string>
using namespace std;
#ifndef STACK_H
#define STACK_H

//************************************************************
template<class DT>
struct Node2
{
	DT info;
	Node2 *next;
};

//************************************************************
template<class DT>
class Stack
{
private:
	Node2<DT> *top;
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

template<class DT>
void Stack<DT>::push(DT& obj)
{
	Node2<DT> *ptr = new Node2<DT>;
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
		Node2<DT> *ptr = top;
		DT obj = ptr->info;
		top = top->next;
		delete ptr;
		return true;
	}
	return false;
}
//************************************************************
//
//		File:			List.h
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #2		
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			February 8, 2018
//
//		In this assignment, I develop a program using a 
//		templated class named List. With the templated list
//		I practice writing pointers, dynamic memory allocation,
//		a copy constructor, and a destructor.
//		
//************************************************************
#include <string>
using namespace std;
#ifndef LIST_H
#define LIST_H

template<class DT>
class List
{
private:
	DT *pList;				// Pointer to the dynamically allocated array
	int numberInList;
	int listSize;
	int nextIndex;
public:
	List();					// Default Constructor
	List(int);				// Overloaded Constructor
	List(const List<DT>&);	// Copy Constructor
	~List();				// Deconstructor
	void addMember(DT);
	void expand();
	bool getMember(DT&);
	DT getNext();
	int getNumber();
	void setItem(DT);
};
#endif

// Default Constructor
template<class DT>
List<DT>::List()
{
	numberInList = 0;
	listSize = 100;
	pList = new DT[listSize];
	nextIndex = 0;
}

// Overloaded Constructor
template<class DT>
List<DT>::List(int size)
{
	numberInList = 0;
	listSize = size;
	pList = new DT[listSize];
	nextIndex = 0;
}

// Copy Constructor
template<class DT>
List<DT>::List(const List<DT> &original)
{
	numberInList = original.numberInList;
	listSize = original.listSize;
	nextIndex = original.nextIndex;
	pList = new DT[listSize];
	for (int i = 0; i < listSize; i++)
	{
		pList[i] = original.pList[i];
	}

}

// Deconstructor
template<class DT>
List<DT>::~List()
{
	delete[] pList;
}

// Adds a new member in the list
template<class DT>
void List<DT>::addMember(DT newMember)
{
	if (numberInList >= listSize)
	{
		expand();
	}
	pList[numberInList] = newMember;
	numberInList++;
}

// Doubles size of array
template<class DT>
void List<DT>::expand()
{
	DT * temp = new DT[listSize * 2];
	for (int i = 0; i < listSize; i++)
		temp[i] = pList[i];
	delete[] pList;
	pList = temp;
	listSize *= 2;
}

// Moves to the next element in the array
template<class DT>
DT List<DT>::getNext()
{
	if (nextIndex >= numberInList)
		nextIndex = 0;
	return pList[nextIndex++];
}

// Searches the array for a member
template<class DT>
bool List<DT>::getMember(DT& findMember)
{
	bool found = false;
	for (int i = 0; i < numberInList; i++)
	{
		if (pList[i] == findMember)
		{
			findMember = pList[i];
			found = true;
		}
	}
	return found;
}

// Returns the location number in the array.
template<class DT>
int List<DT>::getNumber()
{
	return numberInList;
}

// Sets the index to the current element in the array.
template<class DT>
void List<DT>::setItem(DT newProduct)
{
	pList[nextIndex-1] = newProduct;
}
//************************************************************
//
//		File:			List.h
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #1		
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			February 1, 2018
//
//		This program using a list class template located in a
//		header file to sort through data. 
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
	DT array[100];
	int numberInList;
	int listSize;
	int nextIndex;
public:
	List();
	void insert(DT);
	bool getMember(DT&);
	DT getNext();
	int getNumber();
};
#endif

template<class DT>
List<DT>::List()
{
	numberInList = 0;
	listSize = 100;
	nextIndex = 0;
}

template<class DT>
void List<DT>::insert(DT newMember)
{
	array[numberInList] = newMember;
	numberInList++;
}

template<class DT>
DT List<DT>::getNext()
{
	if (nextIndex >= numberInList)
		nextIndex = 0;
	return array[nextIndex++];
}

template<class DT>
bool List<DT>::getMember(DT& findMember)
{
	bool found = false;
	for (int i = 0; i < numberInList; i++)
	{
		if (array[i] == findMember)
		{
			findMember = array[i];
			found = true;
		}
	}
	return found;
}

template<class DT>
int List<DT>::getNumber()
{
	return numberInList;
}
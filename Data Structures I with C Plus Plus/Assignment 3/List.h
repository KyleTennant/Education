//************************************************************
//
//		File:			List.h
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #3		
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			February 15, 2018
// 
//		In this program I store data into an unsorted
//		linked list and calculate totals and averages.
//		
//************************************************************
#include <string>
using namespace std;
#ifndef LIST_H
#define LIST_H

// Node structure template
template<class DT>
struct Node
{
	DT info;			// Used as a record of information
	Node<DT> *next;		// Address of a Node
};

template<class DT>
class List
{
	private:
		Node<DT> *start;				// Delcares the beginning Node
		Node<DT> *current;				// Delcares the current Node
		//DT obj;						// Delcares a datatype
		//DT item;						// Delcares a datatype
	public:
		List();							// Constructor
		void insert(const DT& item);
		bool first(DT& obj);
		bool getNext(DT& odj);
		bool find(DT& odj);
};
#endif

// Constructor
template<class DT>
List<DT>::List()
{
	start = 0;
}

// Returns a bool false if the list is empty
// or it sets the current pointer, passes back the object
// in the list located at the start location, and returns
// a bool true if the list is not empty.
template<class DT>
bool List<DT>::first(DT& obj)
{
	if (start == nullptr)
	{
		return false;
	}
	current = start;
	obj = start->info;
	return true;
}

// Inserts data found in the file unsorted.
template<class DT>
void List<DT>::insert(const DT& item)
{
	Node<DT> *ptr = new Node<DT>;
	ptr->info = item;
	ptr->next = start;
	start = ptr;
}


// Sets the current pointer and passes back the object
// in the list located at the current location, and
// returns a bool true. Otherwise it returns a bool false.
template<class DT>
bool List<DT>::getNext(DT& obj)
{
	current = current->next;
	if (current == nullptr)
	{
		return false;
	}
	obj = current->info;
	return true;
}

// Searches the list for the obj entered by the user.
template<class DT>
bool List<DT>::find(DT& obj)
{
	Node<DT> *ptr = start;
	bool found = false;
	while (ptr != nullptr && !found)
	{
		if (ptr->info == obj)
		{
			obj = ptr->info;
			return true;
		}
		if (!found)
		{
			ptr = ptr->next;
		}
	}
	return false;
}
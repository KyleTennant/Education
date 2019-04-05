//************************************************************
//
//		File:			List.h
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #4		
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			February 22, 2018
//
//		This program uses a sorted linked list structure to 
//		organize an inventory file. The program also includes
//		a find, update, and erase functions to either find,
//		update, or erase a certain data member within the file.
//		
//************************************************************
#include <string>
using namespace std;
#ifndef LIST_H
#define LIST_H

//************************************************************
template<class DT>
struct Node
{
	DT info;
	Node<DT> *next;
};

//************************************************************
template<class DT>
class List
{
	private:
		Node<DT> *start;
		Node<DT> *current;
	public:
		List();
		bool first(DT& obj);
		bool insert(DT& obj);
		bool getNext(DT& obj);
		bool getMember(DT& obj);
		bool find(DT& obj, Node<DT>*& pPrev);
		bool update(DT& obj);
		bool erase(DT& obj);
};
#endif

//************************************************************
template<class DT>
List<DT>::List()
{
	start = 0;
}

//************************************************************
template<class DT>
bool List<DT>::first(DT& obj)
{
	if (start == nullptr)
		return false;

	current = start;
	obj = start->info;
	return true;
}

//************************************************************
template<class DT>
bool List<DT>::insert(DT& obj)
{
	Node<DT> *pPrev;
	bool found = false;
	found = find(obj, pPrev);
	if (!found)
	{
		Node<DT> *pNew = new Node<DT>;
		pNew->info = obj;
		if (pPrev != nullptr)
		{
			pNew->next = pPrev->next;
			pPrev->next = pNew;
		}
		else
		{
			pNew->next = start;
			start = pNew;
		}
	}
	else
		found = true;
	return found;
}

//************************************************************
template<class DT>
bool List<DT>::getNext(DT& obj)
{
	current = current->next;
	if (current == nullptr)
		return false;
	
	obj = current->info;
	return true;
}

//************************************************************
template<class DT>
bool List<DT>::getMember(DT& obj)
{
	Node<DT> *pPrev;
	bool found = false;
	found = find(obj, pPrev);
	if (found)
	{
		if (pPrev == nullptr)
			obj = start->info;
		else
			obj = pPrev->next->info;
		return true;
	}
	return false;
}

//************************************************************
template<class DT>
bool List<DT>::find(DT& obj, Node<DT>*& pPrev)
{
	bool found = false;
	pPrev = nullptr;
	Node<DT> *ptr = start;
	while (ptr != nullptr && !found && obj >= ptr->info)
	{
		if (obj == ptr->info)
		{
			found = true;
		}
		else
		{
			pPrev = ptr;
			ptr = ptr->next;
		}
	}
	return found;
}

//************************************************************
template<class DT>
bool List<DT>::update(DT& obj)
{
	Node<DT> *pPrev;
	bool found = false;
	found = find(obj, pPrev);
	if (found)
	{
		if (pPrev == nullptr)
			start->info = obj;
		else
			pPrev->next->info = obj;
	}
	return found;
}

//************************************************************
template<class DT>
bool List<DT>::erase(DT& obj)
{
	Node<DT> *pPrev;
	Node<DT> *ptr;
	bool found = false;
	found = find(obj, pPrev);
	if (found)
	{
		if (pPrev != nullptr)
		{
			ptr = pPrev->next;
			pPrev->next = ptr->next;
		}
		else
		{
			ptr = start;
			start = ptr->next;
		}
		delete ptr;
	}
	return found;
}
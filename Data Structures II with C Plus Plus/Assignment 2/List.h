//************************************************************
//
//		File:			List.h
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #2		
//
//		Course Name:	Data Structures II
//
//		Course Number:	COSC 3100
//
//		Due:			April 12, 2018
//		
//************************************************************
template <class DT>
struct Node
{
	DT info;
	Node<DT> *next;
};

//************************************************************
template <class DT>
class List
{
	public:
		List();
		List(const List<DT> &);
		~List();
		List<DT> & operator =(const List<DT> &);
		void insert(const DT &);
		bool first(DT &);
		inline bool getNext(DT &);	
		bool find(const DT &);
		bool retrieve(DT &);
		bool isEmpty() const;
		void makeEmpty();
		inline void deepCopy(const List<DT> &);
		static int getCollision();
	private:
		Node<DT> *start;
		Node<DT> *current;
		static int collision;
};

//************************************************************
#include <iostream>
using namespace std;

//************************************************************
template <class DT>
int List<DT>::collision = 0;

//************************************************************
template <class DT>
int List<DT>::getCollision()
{
	return collision;
}

//************************************************************
template <class DT>
List<DT>::List()
{
	start = current = NULL;
}

//************************************************************
template <class DT>
List<DT>::List(const List<DT> & aplist)
{
	deepCopy(aplist);
}

//************************************************************
template <class DT>
List<DT>::~List()
{
	makeEmpty();
}

//************************************************************
template <class DT>
List<DT> & List<DT>::operator =(const List<DT> & rlist)
{
	if (this == &rlist)
		return *this;
	makeEmpty();
	deepCopy(rlist);
	return *this;
}

//************************************************************
template <class DT>
void List<DT>::insert(const DT & element)
{
	cout << element << " is being added" << endl;
	current = NULL;
	if (start != NULL)
	{
		cout << "There was a collision loading " << element << endl;
		collision++;
		cout << "It collided with " << endl;
	}
	else
	{
		cout << "There was no collision loading " << element << endl;
	}
	Node<DT> *newNode = new Node<DT>;
	newNode->info = element;
	newNode->next = start;
	start = newNode;
	Node<DT> *ptr = start;
	
	while (ptr != NULL)
	{
		//cout << ptr->info;
		ptr = ptr->next;
	}
	cout << " " << endl;
	cout << "************************************************************************************" << endl;
	cout << " " << endl;
}

//************************************************************
template <class DT>
bool List<DT>::first(DT & listEl)
{
	if (start == NULL)
		return false;

	current = start;
	listEl = start->info;
	return true;
}

//************************************************************
template <class DT>
inline bool List<DT>::getNext(DT & listEl)
{
	if (current == NULL)
		return false;
	if (current->next == NULL) {
		current = NULL;
		return false;
	}

	current = current->next;
	listEl = current->info;
	return true;
}

//************************************************************
template <class DT>
bool List<DT>::find(const DT & element)
{
	int pass = 1;
	DT item;
	if (!first(item))
		return false;
	do {
		if (item == element)
			return true;
	} while (getNext(item));

	return false;
}

//************************************************************
template <class DT>
bool List<DT>::retrieve(DT & element)
{
	Node<DT> *ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->info << endl;
		ptr = ptr->next;
	}
	if (!find(element))
		return false;
	
	element = current->info;
	return true;
}

//************************************************************
template <class DT>
bool List<DT>::isEmpty() const
{
	return start == NULL;
}

//************************************************************
template <class DT>
void List<DT>::makeEmpty()
{
	while (start != NULL) {
		current = start;
		start = start->next;
		delete current;
	}

	current = NULL;
}

//************************************************************
template <class DT>
inline void List<DT>::deepCopy(const List<DT> & original)
{
	start = current = NULL;
	if (original.start == NULL)
		return;
	Node<DT> *copyptr = start = new Node<DT>;
	Node<DT> *originalptr = original.start;
	copyptr->info = originalptr->info;
	if (originalptr == original.current)
		current = copyptr;
	while (originalptr->next != NULL) {
		originalptr = originalptr->next;
		copyptr->next = new Node<DT>;
		copyptr = copyptr->next;
		copyptr->info = originalptr->info;
		if (originalptr == original.current)
			current = copyptr;
	}
	copyptr->next = NULL;
}
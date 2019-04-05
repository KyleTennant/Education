//************************************************************
//
//		File:			Queue.h
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment #6 Option 1 & 2		
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			March 8, 2018
//
//		This program uses a linked queue structure to
//		process a simutation of a telephone customer
//		service center.
//		
//************************************************************
#include <string>
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H

//************************************************************
template<class DT>
struct NodeQueue
{
	DT info;
	NodeQueue *next;
};

//************************************************************
template<class DT>
class Queue
{
	private:
		NodeQueue<DT> *front;
		NodeQueue<DT> *back;
		int qSize;
		int mySize;
	public:
		Queue();
		Queue(int size);
		~Queue();
		bool empty();
		bool enqueue(DT& obj);
		bool dequeue();
		DT getFront();
};
#endif

//************************************************************
template<class DT>
Queue<DT>::Queue()
{
	front = nullptr;
	back = nullptr;
	qSize = 10;
	mySize = 0;
}

//************************************************************
template<class DT>
Queue<DT>::Queue(int size)
{
	front = nullptr;
	back = nullptr;
	qSize = size;
	mySize = 0;
}

//************************************************************
template<class DT>
Queue<DT>::~Queue()
{
	while (!empty())
		dequeue();
}

//************************************************************
template<class DT>
bool Queue<DT>::empty()
{
	return back == NULL;
}

//************************************************************
template<class DT>
bool Queue<DT>::enqueue(DT& obj)
{
	if (qSize == mySize)
		return false;

	NodeQueue<DT> *ptr = new NodeQueue<DT>;
	ptr->info = obj;

	if (empty())
		front = ptr;
	else
		back->next = ptr;

	back = ptr;
	mySize++;
	return true;

}

//************************************************************
template<class DT>
bool Queue<DT>::dequeue()
{
	if (!empty())
	{
		NodeQueue<DT> *ptr = front;

		if (front == back)
			front = back = nullptr;
		else
			front = front->next;

		delete ptr;
		mySize--;
		return true;
	}
	return false;
}

//************************************************************
template<class DT>
DT Queue<DT>::getFront()
{
	return front->info;
}
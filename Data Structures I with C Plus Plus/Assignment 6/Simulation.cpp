//************************************************************
//
//		File:			Simulation.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment #6 Option 2		
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
#include <iostream>
#include <string>
#include <fstream>
#include "Queue.h"
using namespace std;

void readDataAndProcess(Queue<char>&);

//************************************************************
int main()
{
	Queue<char> Queue(10);

	readDataAndProcess(Queue);

	return 0;
}

//************************************************************
void readDataAndProcess(Queue<char>& queue)
{
	ifstream inFile("Queue.csv");
	ofstream outFile("QueueResults.txt");

	int dequeQuestion;
	char customer;
	int enqueQuestion;

	int lostCalls = 0;

	if (!inFile)
	{
		cout << "Problem opening Queue.csv file." << endl;
		exit(99);
	}

	while (!inFile.eof())
	{
		inFile >> dequeQuestion;
		inFile.ignore();
		inFile >> customer;
		inFile.ignore();
		inFile >> enqueQuestion;
		inFile.ignore();

		int i = 0;

		while (i < enqueQuestion)
		{
			bool loaded = queue.enqueue(customer);

			if (loaded)
			{
				outFile << "Question enqueued for customer " << customer << "\n\n";
			}
			else
			{
				outFile << "Phone Queue is full; cannot add to the queue\n\n";
				lostCalls++;
			}
			i++;
		}

		i = 0;

		while (i < dequeQuestion)
		{
			if (queue.empty())
			{
				outFile << "Phone Queue is empty; cannot remove from the queue\n\n";
				break;
			}
			char cust = queue.getFront();
			queue.dequeue();
			outFile << "\tQuestion dequeued for customer " << cust << "\n\n";
			i++;
		}
	}

	outFile << "*****Final Phone Queue was*****\n\n";

	while (!queue.empty())
	{
		char aCust = queue.getFront();
		queue.dequeue();
		outFile << aCust << " ";
	}
	
	outFile << "\n\nThere were " << lostCalls << " lost calls\n\n";
}
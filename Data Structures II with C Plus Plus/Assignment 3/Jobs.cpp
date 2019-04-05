//***********************************************************
//
//		File:			Jobs.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #3		
//
//		Course Name:	Data Structures II
//
//		Course Number:	COSC 3100
//
//		Due:			April 19, 2018
//		
//***********************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

//************************************************************
struct Jobs
{
	double lines;
	string name;
	double index;
	double level;
	double priority;

	Jobs() { lines = 0.0; name = ""; index = 0.0; level = 0.0; priority = 0.0; }

	bool operator <= (const Jobs& j)
	{
		if (priority <= j.priority) return true; return false;
	}
	bool operator > (const Jobs& j)
	{
		if (priority > j.priority) return true; return false;
	}

	friend ostream& operator << (ostream& out, const Jobs& j)
	{
		out << j.index << '\t' << j.level << '\t' << j.name << '\t'
			<< j.lines << '\t' << j.priority << endl;
		return out;
	}
};

//************************************************************
void getData(PriorityQueue<Jobs> &, Jobs []);
void displayData(PriorityQueue<Jobs> &);
void processData(PriorityQueue<Jobs> &, Jobs []);

//************************************************************
int main()
{
	PriorityQueue<Jobs> Data;
	Jobs jobArr[11];

	cout << "**********************************************\n" << endl;
	cout << "Displaying records before Priority Queue.\n" << endl;
	cout << "Index\tLevel\tName\tLines\tKey" << endl;
	cout << " " << endl;
	getData(Data, jobArr);

	cout << "**********************************************\n" << endl;
	cout << "Displaying records in Priority Queue.\n" << endl;
	cout << "Index\tLevel\tName\tLines\tKey" << endl;
	cout << " " << endl;
	displayData(Data);

	PriorityQueue<Jobs> SecondData;
	processData(SecondData, jobArr);

	cout << "**********************************************\n" << endl;
	cout << "Displaying records in PrintActivity.csv.\n" << endl;
	cout << "Index\tLevel\tName\tLines\tKey" << endl;
	cout << " " << endl;

	return 0;
}

//************************************************************
void getData(PriorityQueue<Jobs> &PQ, Jobs JA[])
{
	Jobs j;
	int index = 0;
	
	ifstream inFile("Jobs.csv");

	if (!inFile)
	{
		cout << "Problem opening Jobs.csv file." << endl;
		exit(99);
	}

	while (!inFile.eof())
	{
		inFile >> j.lines;
		if (!inFile.eof())
		{
			inFile.ignore();
			getline(inFile, j.name);
			if (j.lines > 0 && j.lines <= 10000)
			{
				j.level = 15;
			}
			else if(j.lines >= 10001 && j.lines <= 50000)
			{
				j.level = 10;
			}
			else if (j.lines > 50001)
			{
				j.level = 1;
			}
			j.priority = ((100000 * j.level) - j.lines);
			j.index = index;
			PQ.enqueue(j);
			JA[index] = j;
			index++;
		}
	}
	for (int i = 0; i < index; i++)
	{
		cout << JA[i] << "\t" << endl;
	}
	inFile.close();
}

//************************************************************
void displayData(PriorityQueue<Jobs> &PQ)
{
	Jobs j;
	bool found = false;

	// 3. Use while loop in displayData function when PQ is not empty
	while(!PQ.isEmpty())
	{
		// 4. In the while loop, display dequeue.
		found = PQ.dequeue(j);
		cout << j << endl;
	}
}

//************************************************************
void processData(PriorityQueue<Jobs> &PQ, Jobs JA[])
{
	Jobs j;

	ifstream inFile("PrintActivity.csv");

	if (!inFile)
	{
		cout << "Problem opening PrintActivity.csv file." << endl;
		exit(99);
	}
}
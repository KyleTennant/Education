//************************************************************
//
//		File:			Sort1.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #4		
//
//		Course Name:	Data Structures II
//
//		Course Number:	COSC 3100
//
//		Due:			April 26, 2018
//		
//************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//************************************************************
//******************* Global Variables ***********************
//************************************************************
int sCount = 0;
int iCount = 0;
int bCount = 0;

//************************************************************
//******************* Object Structure ***********************
//************************************************************
struct Object
{
	int index;
	int rank;
	string name;
	string city;
	string state;
	string zip;

	Object() { index = 0; rank = 0; name = " "; city = " "; state = " "; zip = " "; }

	bool operator > (const Object& o)
	{
		if (rank > o.rank) return true; return false;
	}

	friend ostream& operator << (ostream& out, const Object& o)
	{
		out << setw(7) << left << o.index
			<< setw(7) << left << o.rank 
			<< setw(35) << left << o.name
			<< setw(20) << left << o.city
			<< setw(20) << left << o.state
			<< setw(7) << left << o.zip << endl;
		return out;
	}
};

//************************************************************
//***************** Function Prototypes **********************
//************************************************************
void copyArray(Object[], Object[]);
void displayArray(Object[], Object[], fstream&);
void selectionSort(Object[]);
void insertionSort(Object[]);
void bubbleSort(Object[]);

//************************************************************
//******************** Main Function *************************
//************************************************************
int main()
{
	Object unSorted[1000];
	Object sortedArray[1000];

	Object object;
	int index = 0;

	fstream inFile("Fortune1000.csv");
	if (!inFile)
	{
		cout << "There was a problem opening Fortune1000.csv." << endl;
		exit(99);
	}
	while (!inFile.eof())
	{
		inFile >> object.rank;
		if (!inFile.eof())
		{
			inFile.ignore();
			getline(inFile, object.name, ',');
			getline(inFile, object.city, ',');
			getline(inFile, object.state, ',');
			getline(inFile, object.zip);
			object.index = index;
			unSorted[index] = object;
			index++;
		}
	}
	inFile.close();

	fstream outFile("RankingReport.txt", ios::out);
	displayArray(unSorted, sortedArray, outFile);
	outFile.close();
	
	return 0;
}

//************************************************************
//***************** Copy Array Function **********************
//************************************************************
void copyArray(Object UA[], Object SA[])
{
	for (int i = 0; i < 1000; i++)
	{
		SA[i].index = i;
		SA[i].rank = UA[i].rank;
		SA[i].name = UA[i].name;
		SA[i].city = UA[i].city;
		SA[i].state = UA[i].state;
		SA[i].zip = UA[i].zip;
	}
}

//************************************************************
//**************** Display Array Function ********************
//************************************************************
void displayArray(Object UA[], Object SA[], fstream& outFile)
{
//**************************************************************************
	outFile << "----------------------------------------------------------" 
			<< "-----------------------------" << endl;
	outFile << " " << endl;
	outFile << "The Selection Sort results follow" << endl;
	outFile << " " << endl;
	outFile << "The unsorted data follows" << endl;
	outFile << setw(7) << left << "Index"
			<< setw(7) << left << "Rank"
			<< setw(35) << left << "Name"
			<< setw(20) << left << "City"
			<< setw(20) << left << "State"
			<< setw(7) << left << "Zip" << endl;
	for (int i = 0; i < 10; i++)
		outFile << UA[i];
	for (int i = 990; i < 1000; i++)
		outFile << UA[i];
	outFile << " " << endl;

	copyArray(UA, SA);
	selectionSort(SA);

	outFile << "The sorted data follows" << endl;
	outFile << setw(7) << left << "Index"
			<< setw(7) << left << "Rank"
			<< setw(35) << left << "Name"
			<< setw(20) << left << "City"
			<< setw(20) << left << "State"
			<< setw(7) << left << "Zip" << endl;
	for (int i = 0; i < 10; i++) 
		outFile << SA[i];
	for (int i = 990; i < 1000; i++)
		outFile << SA[i];
	outFile << " " << endl;

	outFile << "The number of iterations is: " << sCount << endl;
	outFile << " " << endl;
//**************************************************************************
	outFile << "----------------------------------------------------------"
			<< "-----------------------------" << endl;
	outFile << " " << endl;
	outFile << "The Insertion Sort results follow" << endl;
	outFile << " " << endl;
	outFile << "The unsorted data follows" << endl;
	outFile << setw(7) << left << "Index"
		<< setw(7) << left << "Rank"
		<< setw(35) << left << "Name"
		<< setw(20) << left << "City"
		<< setw(20) << left << "State"
		<< setw(7) << left << "Zip" << endl;
	for (int i = 0; i < 10; i++)
		outFile << UA[i];
	for (int i = 990; i < 1000; i++)
		outFile << UA[i];
	outFile << " " << endl;

	copyArray(UA, SA);
	insertionSort(SA);

	outFile << "The sorted data follows" << endl;
	outFile << setw(7) << left << "Index"
		<< setw(7) << left << "Rank"
		<< setw(35) << left << "Name"
		<< setw(20) << left << "City"
		<< setw(20) << left << "State"
		<< setw(7) << left << "Zip" << endl;
	for (int i = 0; i < 10; i++)
		outFile << SA[i];
	for (int i = 990; i < 1000; i++)
		outFile << SA[i];
	outFile << " " << endl;

	outFile << "The number of iterations is: " << iCount << endl;
	outFile << " " << endl;
//**************************************************************************
	outFile << "----------------------------------------------------------"
			<< "-----------------------------" << endl;
	outFile << " " << endl;
	outFile << "The Bubble Sort results follow" << endl;
	outFile << " " << endl;
	outFile << "The unsorted data follows" << endl;
	outFile << setw(7) << left << "Index"
		<< setw(7) << left << "Rank"
		<< setw(35) << left << "Name"
		<< setw(20) << left << "City"
		<< setw(20) << left << "State"
		<< setw(7) << left << "Zip" << endl;
	for (int i = 0; i < 10; i++)
		outFile << UA[i];
	for (int i = 990; i < 1000; i++)
		outFile << UA[i];
	outFile << " " << endl;

	copyArray(UA, SA);
	bubbleSort(SA);

	outFile << "The sorted data follows" << endl;
	outFile << setw(7) << left << "Index"
		<< setw(7) << left << "Rank"
		<< setw(35) << left << "Name"
		<< setw(20) << left << "City"
		<< setw(20) << left << "State"
		<< setw(7) << left << "Zip" << endl;
	for (int i = 0; i < 10; i++)
		outFile << SA[i];
	for (int i = 990; i < 1000; i++)
		outFile << SA[i];
	outFile << " " << endl;

	outFile << "The number of iterations is: " << bCount << endl;
	outFile << " " << endl;
//**************************************************************************
	outFile << "----------------------------------------------------------"
			<< "-----------------------------" << endl;
	outFile << " " << endl;
	outFile << "The summary of iterations follows" << endl;
	outFile << " " << endl;
	outFile << "The number of iterations for the selection soft was " << sCount << endl;
	outFile << "The number of iterations for the insertion soft was " << iCount << endl;
	outFile << "The number of iterations for the bubble soft was " << bCount << endl;
}

//************************************************************
//******************** Selection Sort ************************
//************************************************************
void selectionSort(Object SA[])
{
	for (int i = 0; i <= 1000 - 1; ++i) 
	{
		int smallest = i;
		for (int j = i + 1; j < 1000; ++j)
		{
			sCount++;
			if (SA[smallest] > SA[j])
			{
				smallest = j;
			}
		}
		Object swap = SA[smallest];
		SA[smallest] = SA[i];
		SA[i] = swap;
		SA[i].index = i;
	}
}

//************************************************************
//******************** Insertion Sort ************************
//************************************************************
void insertionSort(Object SA[])
{
	for (int i = 1; i < 1000; ++i)
	{
		int insert = i;
		while (insert > 0 && SA[insert - 1] > SA[insert])
		{
			iCount++;
			Object swap = SA[insert];
			SA[insert] = SA[insert - 1];
			SA[insert - 1] = swap;
			--insert;
		}
	}
}

//************************************************************
//********************* Bubble Sort **************************
//************************************************************
void bubbleSort(Object SA[])
{
	for (int end = 1000 - 1; end >= 0; --end)
	{
		for (int index = 0; index < end; ++index)
		{
			bCount++;
			if (SA[index] > SA[index + 1])
			{
				
				Object temp = SA[index];
				SA[index] = SA[index + 1];
				SA[index + 1] = temp;
			}
			
		}
		SA[end].index = end;
	}
}
//************************************************************
//
//		File:			Sort2.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #5		
//
//		Course Name:	Data Structures II
//
//		Course Number:	COSC 3100
//
//		Due:			May 3, 2018
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
int hCount = 0;
int qCount = 0;
int mCount = 0;

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

	bool operator < (const Object& o)
	{
		if (rank < o.rank) return true; return false;
	}
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
void shiftRight(Object[], int, int);
void heapify(Object[], int, int);
void heapSort(Object[], int);
void quickSort(Object[], int, int);
void merge(Object[], int, int, int);
void mergeSort(Object[], int, int);

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
		SA[i].index = UA[i].index;
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
	outFile << "The Heap Sort results follow" << endl;
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
	heapSort(SA, 1000);

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

	outFile << "The number of iterations is: " << hCount << endl;
	outFile << " " << endl;
//**************************************************************************
	outFile << "----------------------------------------------------------"
			<< "-----------------------------" << endl;
	outFile << " " << endl;
	outFile << "The Quick Sort results follow" << endl;
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
	quickSort(SA, 0, 999);

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

	outFile << "The number of iterations is: " << qCount << endl;
	outFile << " " << endl;
//**************************************************************************
	outFile << "----------------------------------------------------------"
			<< "-----------------------------" << endl;
	outFile << " " << endl;
	outFile << "The Merge Sort results follow" << endl;
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
	mergeSort(SA, 0, 999);

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

	outFile << "The number of iterations is: " << mCount << endl;
	outFile << " " << endl;
//**************************************************************************
	outFile << "----------------------------------------------------------"
			<< "-----------------------------" << endl;
	outFile << " " << endl;
	outFile << "The summary of iterations follows" << endl;
	outFile << " " << endl;
	outFile << "The number of iterations for the heap soft was " << hCount << endl;
	outFile << "The number of iterations for the quick soft was " << qCount << endl;
	outFile << "The number of iterations for the merge soft was " << mCount << endl;
//**************************************************************************
}

//************************************************************
//********************** Heap Sort ***************************
//************************************************************
void shiftRight(Object SA[], int low, int high)
{
	int root = low;
	while ((root * 2) + 1 <= high)
	{
		hCount++;
		int leftChild = (root * 2) + 1;
		int rightChild = leftChild + 1;
		int swapIdx = root;
		if (SA[swapIdx] < SA[leftChild])
		{
			swapIdx = leftChild;
		}
		if ((rightChild <= high) && (SA[swapIdx] < SA[rightChild]))
		{
			swapIdx = rightChild;
		}
		if (swapIdx != root)
		{
			Object tmp = SA[root];
			SA[root] = SA[swapIdx];
			SA[swapIdx] = tmp;
			root = swapIdx;
		}
		else
		{
			break;
		}
	}
	return;
}
void heapify(Object SA[], int low, int high)
{
	int midIdx = (high - low - 1) / 2;
	while (midIdx >= 0)
	{
		shiftRight(SA, midIdx, high);
		--midIdx;
	}
	return;
}
void heapSort(Object SA[], int size)
{
	heapify(SA, 0, size - 1);
	int high = size - 1;
	while (high > 0)
	{
		Object tmp = SA[high];
		SA[high] = SA[0];
		SA[0] = tmp;
		--high;
		shiftRight(SA, 0, high);
	}
	return;
}

//************************************************************
//********************** Quick Sort **************************
//************************************************************
void quickSort(Object SA[], int left, int right)
{
	int i = left, j = right;
	Object tmp;
	Object pivot = SA[(left + right) / 2];

	while (i <= j)
	{
		while (SA[i] < pivot)
		{
			qCount++;
			i++;
		}
		while (SA[j] > pivot)
		{
			qCount++;
			j--;
		}
		if (i <= j)
		{
			tmp = SA[i];
			SA[i] = SA[j];
			SA[j] = tmp;
			i++;
			j--;
		}
	};

	if (left < j)
		quickSort(SA, left, j);
	if (i < right)
		quickSort(SA, i, right);
}

//************************************************************
//********************** Merge Sort **************************
//************************************************************
void merge(Object SA[], int low, int middle, int high)
{
	Object* tmp = new Object[high - low + 1];
	int i = low;
	int j = middle + 1;
	int k = 0;
	while ((i <= middle) && (j <= high))
	{
		mCount++;
		if (SA[i] < SA[j])
			tmp[k++] = SA[i++];
		else
			tmp[k++] = SA[j++];
	}
	if (i <= middle)
	{
		while (i <= middle)
		{
			mCount++;
			tmp[k++] = SA[i++];
		}
	}
	if (j <= high)
	{
		while (j <= high)
		{
			mCount++;
			tmp[k++] = SA[j++];
		}
	}
	for (k = low; k <= high; ++k)
	{
		mCount++;
		SA[k] = tmp[k - low];
	}
	delete[] tmp;
	return;
}
void mergeSort(Object SA[], int low, int high)
{
	if (low < high)
	{
		int middle = (high + low) / 2;
		mergeSort(SA, low, middle);
		mergeSort(SA, middle + 1, high);
		merge(SA, low, middle, high);
	}
	return;
}
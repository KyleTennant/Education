// This program demostrates a class with an array of floating-point numbers
#include <iostream>
using namespace std;

// Class for the array of numbers
class NumberArray
{
private:
	float *numArr;
	int numEle;

public:
	NumberArray(int);					// Constructor
	void storeNum();
	float retrieveNum(int)const;
	double highestVal()const;
	double lowestVal()const;
	double avg()const;
	~NumberArray();						// Destructor
};

// Constructor
NumberArray::NumberArray(int n)
{
	numEle = n;								// Initialize the number of elements
	numArr = nullptr;
	numArr = new float[numEle];				// Dynamically allocate the array

	for (int i = 0; i < numEle; i++)		// Initialize the array values
	{
		numArr[i] = 0;
	}
}

void NumberArray::storeNum()
{
	int x;
	float y;

	// Prompt user to select element of the array
	cout << "Which element in the array would you like to fill? ";
	cin >> x;

	// Prompt user to enter value into that element
	cout << "What value would you like to add to that element? ";
	cin >> y;

	// Store value in element chosen
	numArr[x] = y;
}

// Retrieves the number from the element in the array
float NumberArray::retrieveNum(int ele)const
{
	return numArr[ele];
}

// Find the lowest value of the elements
double NumberArray::highestVal()const
{
	float highVal;
	highVal = numArr[0];
	for (int i = 0; i < numEle; i++)
	{
		if (numArr[i] > highVal)
		{
			highVal = numArr[i];
		}
	}

	//Return highest value
	return highVal;
}

// Find the lowest value of the elements
double NumberArray::lowestVal()const
{
	float lowVal;
	lowVal = numArr[0];
	for (int i = 0; i < numEle; i++)
	{
		if (numArr[i] < lowVal)
		{
			lowVal = numArr[i];
		}
	}

	// Return lowest value
	return lowVal;
}

// Calculate the average value of the elements
double NumberArray::avg()const
{
	float x = 0;
	for (int i = 0; i < numEle; i++)
	{
		x = x + numArr[i];
	}

	// Return average
	return x / numEle;
}

// Destructor
NumberArray::~NumberArray()
{
	delete numArr;
}

int main()
{
	int x, y;

	// Prompt user to enter how big they want the array
	cout << "Enter the number of array elements: ";
	cin >> x;

	// NumberArray object
	NumberArray element(x);

	// Read the values stored in each element
	for (int i = 0; i < x; i++)
	{
		element.storeNum();
	}

	// Prompt user to enter which element they wish to retrieve
	cout << "Which element in the array would you like to retrieve? ";
	cin >> y;

	// Display the results
	cout << "The value in element " << y << " is " << element.retrieveNum(y) << endl;
	cout << "Highest value: " << element.highestVal() << endl;
	cout << "Lowest value: " << element.lowestVal() << endl;
	cout << "Average value: " << element.avg() << endl;

	return 0;
}
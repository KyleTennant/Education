// This program has a function that dynamically allocates an array of integers
#include <iostream>
using namespace std;

// Function prototypes
int *showValues(int);

int main()
{
	// To point to the numbers
	int *iptr = nullptr;
	int size;

	// Get the size of the array
	cout << "Enter the size of the array: ";
	cin >> size;

	// Get the array of numbers
	iptr = showValues(size);

	// Display the numbers
	for (int x = 0; x < size; x++)
		cout << "Element: " << iptr[x] << endl;

	// Free the memory
	delete[] iptr;
	iptr = nullptr;
	return 0;
}

int *showValues(int size)
{
	// Array to hold the numbers
	int *arr = nullptr;

	// Return a null pointer if size is a zero or negative
	if (size <= 0)
	{
		return nullptr;
	}

	// Dynamically allocate the array
	arr = new int[size];

	// Populate the array with integers
	for (int x = 0; x < size; x++)
	{
		arr[x] = x + 1;
	}

	// Return a pointer to the array
	return arr;
}
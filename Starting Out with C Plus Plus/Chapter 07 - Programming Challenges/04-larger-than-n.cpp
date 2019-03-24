// This program has an array with a size of 10 elements. Each element has a 
// number. Each number is compared to 'n' in a function. A for loop with an if
// statement determines the numbers in the array that are larger than 'n'
// and displays the numbers.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
void showValues(int[], int, int);

int main()
{
	// The size of the array
	const int ARRAY_SIZE = 10;
	// The numbers in the array
	int numbers[ARRAY_SIZE] = { 23, 42, 76, 99, 17, 58, 36, 14, 81, 63 };
	// The number 'n'
	const int n = 40;

	// Calling the funstion below
	showValues(numbers, ARRAY_SIZE, n);

	cin.ignore();
	cin.clear();
	cin.get();
	return 0;
}

// Function that determines the numbers that are higher than 'n'
void showValues(int nums[], const int size, const int x)
{
	for (int count = 0; count < size; count++)
	{
		if (nums[count] > x)
		{
			cout << nums[count] << " ";
		}
	}
}
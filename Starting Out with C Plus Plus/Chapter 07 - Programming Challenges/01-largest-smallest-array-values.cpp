// This program prompts the user toenter 10 digits. Those 10 digits are
// then processed by an array so the smallest and largest digits are displayed.
#include <iostream>
using namespace std;

int main()
{
	// Initializaing the array
	const int SIZE = 10;
	int tenDigitArray[SIZE];

	// Declaring variables
	int count;
	double highest;
	double lowest;
	
	// Prompting user to enter data
	cout << "Enter 10 digits (Press 'Enter' after each digit): " << endl;
	cin >> tenDigitArray[0];
	cin >> tenDigitArray[1];
	cin >> tenDigitArray[2];
	cin >> tenDigitArray[3];
	cin >> tenDigitArray[4];
	cin >> tenDigitArray[5];
	cin >> tenDigitArray[6];
	cin >> tenDigitArray[7];
	cin >> tenDigitArray[8];
	cin >> tenDigitArray[9];

	// Finding the highest amount entered
	highest = tenDigitArray[0];
	for (count = 1; count < SIZE; count++)
	{
		if (tenDigitArray[count] > highest)
			highest = tenDigitArray[count];
	}

	// Finding the lowest amount entered
	lowest = tenDigitArray[0];
	for (count = 1; count < SIZE; count++)
	{
		if (tenDigitArray[count] < lowest)
			lowest = tenDigitArray[count];
	}

	// Outputing the calculated results
	cout << "The highest digit you entered is: " << highest << endl;
	cout << "The lowest digit you entered is: " << lowest << endl;

	cin.ignore();
	cin.clear();
	cin.get();
	return 0;
}
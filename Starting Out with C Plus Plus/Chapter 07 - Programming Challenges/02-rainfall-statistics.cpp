// This program calculates the total, average, highest, and lowest amount of
// rainfall for a year y using an array.
#include <iostream>
using namespace std;

int main()
{
	// Initializaing the array
	const int SIZE = 12;
	double months[SIZE];

	// Declaring variables
	int count;
	double highest;
	double lowest;
	double total = 0;
	double average;

	// Prompting user to enter data
	cout << "Enter the total amount of rainfall for January: ";
	cin >> months[0];
	cout << "Enter the total amount of rainfall for Febuary: ";
	cin >> months[1];
	cout << "Enter the total amount of rainfall for March: ";
	cin >> months[2];
	cout << "Enter the total amount of rainfall for April: ";
	cin >> months[3];
	cout << "Enter the total amount of rainfall for May: ";
	cin >> months[4];
	cout << "Enter the total amount of rainfall for June: ";
	cin >> months[5];
	cout << "Enter the total amount of rainfall for July: ";
	cin >> months[6];
	cout << "Enter the total amount of rainfall for August: ";
	cin >> months[7];
	cout << "Enter the total amount of rainfall for September: ";
	cin >> months[8];
	cout << "Enter the total amount of rainfall for October: ";
	cin >> months[9];
	cout << "Enter the total amount of rainfall for November: ";
	cin >> months[10];
	cout << "Enter the total amount of rainfall for December: ";
	cin >> months[11];

	// Finding the highest amount of rainfall
	highest = months[0];
	for (count = 1; count < SIZE; count++)
	{
		if (months[count] > highest)
			highest = months[count];
	}

	// Finding the lowest amount of rainfall
	lowest = months[0];
	for (count = 1; count < SIZE; count++)
	{
		if (months[count] < lowest)
			lowest = months[count];
	}

	// Finding the total and average amount of rainfall
	for (count = 0; count < SIZE; count++)
	{
		total += months[count];
		average = total / SIZE;
	}

	// Outputing the calculated results
	cout << "The total amount of rainfall this year is: " << total << endl;
	cout << "The average monthly amount of rainfall this year is: " << average << endl;
	cout << "The highest amount of rainfall in one month is: " << highest << endl;
	cout << "The lowest amount of rainfall in one month is: " << lowest << endl;


	cin.ignore();
	cin.clear();
	cin.get();
	return 0;
}
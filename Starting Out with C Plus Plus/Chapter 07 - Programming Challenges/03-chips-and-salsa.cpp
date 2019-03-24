// This program uses an for loop to determine how many salsa jars were sold and
// parallel arrays to keep track of which salsa sold the most and least amount of jars.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	const int SIZE = 5;
	string salsa[SIZE] = { "Mild", "Medium", "Sweet", "Hot", "Zesty" };
	string mostSold;
	string leastSold;
	double jars[SIZE];
	double total_jars = 0;
	double highest;
	double lowest;

	// Prompting user to enter the amount of salsa jars sold
	for (int index = 0; index < SIZE; index++)
	{
		cout << "Enter amount of " << salsa[index] << " jars sold: ";
		cin >> jars[index];
		total_jars += jars[index];
	}

	cout << "--------------------------------------------" << endl;

	// Displaying what the users input
	for (int index = 0; index < SIZE; index++)
	{
		cout << "The " << salsa[index] << " salsa sold " << jars[index] << " jars." << endl;
	}

	cout << "--------------------------------------------" << endl;

	// Determining the most sold salsa type
	highest = jars[0];
	for (int count = 0; count < SIZE; count++)
	{
		if (jars[count] > highest)
		{
			highest = jars[count];			// The element number with the most sold jar
			mostSold = salsa[count];		// The type of salsa associated with that element
		}
	}

	// Determining the least sold salsa type
	lowest = jars[0];
	for (int count = 0; count < SIZE; count++)
	{
		if (jars[count] < lowest)
		{
			lowest = jars[count];			// The element number with the least sold jar
			leastSold = salsa[count];		// The type of salsa associated with that element
		}
	}

	// Displaying the results
	cout << "The total amount of jars sold: " << total_jars << endl;
	cout << mostSold << " sold the most jars" << endl;
	cout << leastSold << " sold the least jars" << endl;

	cin.ignore();
	cin.clear();
	cin.get();
	return 0;
}

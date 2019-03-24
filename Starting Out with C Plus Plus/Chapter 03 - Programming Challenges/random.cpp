// This program generates random numbers.
#include <iostream>
#include <cstdlib> //needed for rand function
#include <ctime> //needed for time function
#include <iomanip> //needed for stream manipulators
using namespace std;

int main()
{
	// Declaring variables
	double num1, num2, num3, num4, num5, num6;

	// Get the system time
	unsigned seed = time(0);

	// Seed the random generator
	srand(seed);

	// Limiting the range of each random variable generated
	num1 = (rand() % (32676 - 0 + 1)) + 0;
	num2 = (rand() % (99 - 0 + 1)) + 0;
	num3 = (rand() % (100 - 1 + 1)) + 1;
	num4 = (rand() % (40 - 25 + 1)) + 25;
	num5 = (rand() % (80 - 60 + 1)) + 60;
	num6 = (rand() % (100 - 45 + 1)) + 45;

	// Output of random variables
	cout << "Random number within default range: " << right << setw(8) << num1 << endl;
	cout << "Random number between 0 and 99:     " << right << setw(8) << num2 << endl;
	cout << "Random number between 1 and 100:    " << right << setw(8) << num3 << endl;
	cout << "Random number between 25 and 40:    " << right << setw(8) << num4 << endl;
	cout << "Random number between 60 and 80:    " << right << setw(8) << num5 << endl;
	cout << "Random number between 45 and 100:   " << right << setw(8) << num6 << endl;

	cin.get();
	return 0;
}
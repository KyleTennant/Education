// This program uses a for loop to give the sum of all positive numbers that
// come before the number entered by the user.
#include <iostream>
using namespace std;

int main()
{
	int num, x;

	cout << "Please enter a positive integer value: ";
	cin >> num;
	
	if (num >= 1) // Checks if number entered is positive.
	{
		for (x = 1; x <= num; x++) // Loop used to output positive numbers.
		{
			cout << x << endl;
		}
		cin.get();
	}
	else // Output if number entered is negaitive.
	{
		cout << "Invalid entry.";
		cin.get();
	}

	cin.get();
	return 0;
}
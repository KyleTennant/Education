// This program determines which number the user enters is smaller
// and which number is larger.
#include <iostream>
using namespace std;

int main()
{
	double num1, num2;

	cout << "Please enter two numbers: ";
	cin >> num1 >> num2;

	if (num1 > num2)
	{
		cout << "The first number you entered is larger than \n";
		cout << "the second number you entered.\n";
	}
	else if (num1 < num2)
	{
		cout << "The second number you entered is larger than \n";
		cout << "the first number you entered.\n";
	}
	else
	{
		cout << "You entered the same number twice!\n";
	}

	cin.get();
	return 0;
}
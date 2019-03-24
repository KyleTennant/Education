// This program returns an integer and accepts a pointer to a c-string as an argument
#include <iostream>
#include <string>
using namespace std;

// Function prototype
int count(string);

// Function main
int main()
{
	// Member variables of function main
	string str;
	int num;

	// Prompt user to enter string
	cout << "Enter a String: ";
	cin >> str;

	// Call function count
	num = count(str);

	// Display results
	cout << "The number of characters in the string is: " << num << endl;


	return 0;
}

// Function count
int count(string str)
{
	// Member variables of function count
	int x = 0;
	int i = 0;

	// While loop executes until the end of the string
	while (str[i] != '\0')
	{
		x++;
		i++;
	}

	return x;
}
// This program accepts a pointer to a c-string as an argument and displays its contents backwards
#include <iostream>
#include <string>
using namespace std;

// Function prototype
void reDisplayString(char *);

int main()
{
	// Member variables
	const int SIZE = 50;
	char orgString[SIZE];

	// Prompt user to enter a string
	cout << "Enter a string: ";
	cin.getline(orgString, SIZE);

	// Call function to re-display string backwards
	reDisplayString(orgString);

	return 0;
}

// Function to re-display string backwards
void reDisplayString(char *original)
{
	// Temporary string pointer
	char *reverse = original;

	// Go through the string
	while (*reverse != '\0')
	{
		*reverse++;
	}
	
	// Display the original string backwards
	cout << "The reverse string is: ";

	while (reverse != original)
	{
		*reverse--;
		cout << *reverse;
	}
	cout << " " << endl;
}
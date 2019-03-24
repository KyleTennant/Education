// This program finds the area of a cirle, rectangle, or triangle depending on 
// what the user choices by using a switch statement.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// To hold menu choice and variables.
	int choice;
	double radius, length, width, base, height, area;

	// Constants for menu choices.
	const int CIRCLE = 1, 
			  RECTANGLE = 2, 
			  TRIANGLE = 3, 
			  QUIT = 4;

	// Displaying the menu of choices.
	cout << "Geometry Calculator" << endl;
	cout << "	1. Calculate the Area of a Circle" << endl;
	cout << "	2. Calculate the Area of a Rectangle" << endl;
	cout << "	3. Calculate the Area of a Triangle" << endl;
	cout << "	4. Quit" << endl;
	cout << " " << endl;
	cout << "Enter your choice (1-4): ";
	cin >> choice;

	// Switch statement that responds to the user's input.
	switch (choice)
	{
	case CIRCLE: 
		cout << "Enter the Circle radius: ";
		cin >> radius;
		area = 3.14159 * pow(radius, 2.0);
		cout << "The Area of the Cirle is " << area << endl;
		break;
	case RECTANGLE: 
		cout << "Enter the Length and Width: ";
		cin >> length >> width;
		area = length * width;
		cout << "The Area of the Rectangle is " << area << endl;
		break;
	case TRIANGLE: 
		cout << "Enter the Base-Length of the Triangle: ";
		cin >> base;
		cout << "Enter the Height of the Triangle: ";
		cin >> height;
		area = base * height * .5;
		cout << "The Area of the Triangle is " << area << endl;
		break;
	case QUIT: 
		cout << "Thank you.";
		break;
	default: 
		cout << "That is an invalid choice.\n";
	}

	cin.get();
	return 0;
}
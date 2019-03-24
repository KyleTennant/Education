// This program uses a function to gather input from the user and another 
// function to determine the highest number the user input by passing values by reference.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes with referenced variables
double getSales(double&, double&, double&, double&);
void findHighest(double&, double&, double&, double&);

int main()
{
	double num1, num2, num3, num4;

	cout << "This program determines which division has the highest amount of sales." << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	
	// Calling functions to main
	getSales(num1, num2, num3, num4);
	findHighest(num1, num2, num3, num4);

	cin.ignore();
	cin.clear();
	cin.get();
	return 0;
}

// Function that prompts user to enter sales
double getSales(double &northEast, double &northWest, double &southEast, double &southWest)
{
	cout << "Enter sales for the NorthEast division: ";
	cin >> northEast;
	cout << "Enter sales for the NorthWest division: ";
	cin >> northWest;
	cout << "Enter sales for the SouthEast division: ";
	cin >> southEast;
	cout << "Enter sales for the SouthWest division: ";
	cin >> southWest;

	return northEast, northWest, southEast, southWest;
}

// Function that determines highest sale entered by user
void findHighest(double &val1, double &val2, double &val3, double &val4)
{

	double a = val1;
	double b = val2;
	double c = val3;
	double d = val4;

	cout << setprecision(2) << fixed << endl;

	if (a > b && a > c && a > d)
		cout << "NorthEast division has the most sales with $" << val1 << endl;
	else if (b > a && b > c && b > d)
		cout << "NorthWest division has the most sales with $" << val2 << endl;
	else if (c > a && c > b && c > d)
		cout << "SouthEast division has the most sales with $" << val3 << endl;
	else if (d > a && d > b && d > c)
		cout << "SouthWest division has the most sales with $" << val4 << endl;
	else if (a == b & a == c & a == d)
		cout << "Each division has the same amount of sales." << endl;
	else
		cout << "Invalid Entry";

}
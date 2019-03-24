// This program uses a function to calculate the retail price after a 
// marked-up percentage.
#include <iostream>
#include <iomanip>
using namespace std;

void calculateRetail(double, double); // Function Prototype

int main()
{
	double wholesaleCost;	// The orignal cost before markup
	double markup;			// The markup percentage

	// Prompting user to enter data
	cout << "Enter the wholesale price: ";
	cin >> wholesaleCost;
	cout << "Enter the markup percentage: ";
	cin >> markup;

	// Calling function to calculate users input
	calculateRetail(wholesaleCost, markup);

	cin.ignore();
	cin.clear();
	cin.get();
	return 0;
}

// Function that calculates users input
void calculateRetail(double val1, double val2)
{
	double retailPrice;		// Price after markup
	val2 *= .01;
	retailPrice = (val1 * val2) + val1;
	cout << setprecision(2) << fixed;
	cout << "The retail price is: $"  << retailPrice << endl;
}
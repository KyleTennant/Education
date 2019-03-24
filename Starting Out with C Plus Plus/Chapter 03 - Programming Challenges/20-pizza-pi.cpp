// This program calculates the number of slices a pizza of any size can be divided into
#include <iostream>
#include <iomanip> //needed for setprecision
using namespace std;

int main()
{
	// Declaring variables
	const double PI = 3.14159;
	double area, diameter, radius, pizza_slice;

	// Prompting user to enter size of their pizza
	cout << "How large is the diameter of the pizza in inches? ";
	cin >> diameter;

	// Calculations
	radius = diameter / 2;
	area = PI * pow(radius, 2.0);
	pizza_slice = area / 14.125;

	// Display how many slices the pizza can have
	cout << "The pizza can be divided up by " << setprecision(2) << pizza_slice << " slice(s)." << endl;

	return 0;
}
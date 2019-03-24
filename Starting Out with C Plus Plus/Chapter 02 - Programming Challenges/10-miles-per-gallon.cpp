// This program calculates the number of miles per gallon a car gets
#include <iostream>
using namespace std;

int main()
{
	int gallons, miles, MPG;

	gallons = 15;
	miles = 375;
	MPG = miles / gallons;

	cout << "The car can travel " << MPG << " miles per gallon." << endl;

	return 0;
}
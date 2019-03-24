// This program converts Celsius temperatures to Fahrenheit temperatures.
#include <iostream>
using namespace std;

int main()
{
	double F, C;

	// Formula that converts temperatures
	F = (9 / 5)*C + 32; 

	// Asks user for degrees Celsuis
	cout << "Please enter the temperature in Celsuis: "; 
	cin >> C;

	// Provides conversion to Fahrendeit
	cout << C << " degrees Celsuis is equal to " << F << " degrees Fahrenheit."

	return 0;
}
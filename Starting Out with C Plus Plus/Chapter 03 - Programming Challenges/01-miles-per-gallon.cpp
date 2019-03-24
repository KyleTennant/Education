// This program displays the miles per gallon someone can travel after entering
// the number of gallons their car can hold and the number of miles that car can 
// travel on one tank.
#include <iostream>
using namespace std;

int main()
{
	// Declaring variables
	double Tank, Miles, MPG;

	// Prompting user to enter information
	cout << "How many gallons of gas can your car hold? ";
	cin >> Tank;

	// Prompting user to enter information
	cout << "How many miles can your car travel on a full tank of gas? ";
	cin >> Miles;

	// Calculating information given by user
	MPG = Miles / Tank;

	// Displaying calculation of information
	cout << "Your car can travel " << MPG << " miles per a gallon of gas." << endl;

	return 0;
}
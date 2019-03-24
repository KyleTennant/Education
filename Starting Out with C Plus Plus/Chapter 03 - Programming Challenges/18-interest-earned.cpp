// This program calculates the interest earned in a savings account
// with the information given by the user.
#include <iostream>
#include <iomanip> //included for stream manipulators
#include <string> //included for strings
using namespace std;

int main()
{
	// Declaring variables
	double Principal, Interest_Rate, Compounded, Interest, Savings;

	// Prompting user to input data
	cout << "Enter the principal of your savings account: ";
		cin >> Principal;
	cout << "Enter the interest rate of your savings account: ";
		cin >> Interest_Rate;
	cout << "Enter the number of times the interest rate is compounded: ";
		cin >> Compounded;

	// Calculating variable definitions
	Savings = Principal * pow((1 + ((Interest_Rate*0.01)/Compounded)), Compounded);
	Interest = Savings - Principal;

	// Outputing calculated data
	cout << setprecision(2) << fixed << endl;
	cout << "Interest Rate:        " << right << setw(8) << Interest_Rate << "%" << endl;
	cout << "Times Compounded:     " << right << setw(8) << Compounded << endl;
	cout << "Principal:           $" << right << setw(8) << Principal << endl;
	cout << "Interest:            $" << right << setw(8) << Interest << endl;
	cout << "Amount in Savings:   $" << right << setw(8) << Savings << endl;


	cin.get();
	return 0;
}
// This program calculates and produces the monthly sales tax data entered by
// the user for a retail business.
#include <iostream>
#include <iomanip> //included for stream manipulators
#include <string> //included for strings
using namespace std;

int main()
{
	// Declaring characters and variables
	string Month; 
	double TotalAmount, Sales, CountyTax, StateTax, TotalTax;

	// Prompting user to enter data
	cout << "Enter the month for the Monthly Sales Tax Report: ";
	cin >> Month;
	cout << "Enter the total amount of cash collected from the register in " << Month << ": ";
	cin >> TotalAmount;
	
	// Calculating variable definitions
	Sales = (TotalAmount / 1.06);
	CountyTax = (Sales * 0.02);
	StateTax = (Sales * 0.04);
	TotalTax = (Sales * 0.06);
	
	// Outputing data enter by user after variable definitions are calculated
	cout << "\nMonth: " << Month << endl;
	cout << "--------------------" << endl;
	cout << setprecision(2) << fixed;
	cout << "Total Collected:      $" << right << setw(9) << TotalAmount << endl;
	cout << "Sales:                $" << right << setw(9) << Sales << endl;
	cout << "County Sales Tax:     $" << right << setw(9) << CountyTax << endl;
	cout << "State Sales Tax:      $" << right << setw(9) << StateTax << endl;
	cout << "Total Sales Tax:      $" << right << setw(9) << TotalTax << endl;

	cin.get();
	return 0;
}
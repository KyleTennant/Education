// This program calculates the profit of a movie theater.
#include <iostream>
#include <iomanip> //needed for stream manipulators
#include <string> //needed for strings
using namespace std;

int main()
{
	// Declaring variables
	string Movie_Name;
	double Adult_Tickets_Sold, Child_Tickets_Sold, Gross_Profit, Net_Profit, Amount_Paid;
	double Adult_Price, Child_Price;

	// Ticket prices
	Adult_Price = 10;
	Child_Price = 6;
	
	// Prompting user to enter data
	cout << "Enter the title of the film: ";
		getline(cin, Movie_Name);
	cout << "Enter how many adult tickets were sold: ";
		cin >> Adult_Tickets_Sold;
	cout << "Enter how many child tickets were sold: ";
		cin >> Child_Tickets_Sold;

	// Calculations required to process desire output
	Gross_Profit = (Adult_Tickets_Sold * Adult_Price) + (Child_Tickets_Sold * Child_Price);
	Net_Profit = Gross_Profit * 0.20;
	Amount_Paid = Gross_Profit - Net_Profit;

	// Ouptuting data recently entered and processed
	cout << "" << endl;
	cout << "Movie Name:                        \"" << Movie_Name << "\""<< endl;
	cout << "Adult Tickets Sold:                  " << Adult_Tickets_Sold << endl;
	cout << "Child Tickets Sold:                  " << Child_Tickets_Sold << endl;
	cout << setprecision(2) << fixed;
	cout << "Gross Box Office Profit:            $" << right << setw(8) << Gross_Profit << endl;
	cout << "Net Box Office Profit:              $" << right << setw(8) << Net_Profit << endl;
	cout << "Amount Paid to Distributor:         $" << right << setw(8) << Amount_Paid << endl;
	
	cin.get();
	return 0;
}
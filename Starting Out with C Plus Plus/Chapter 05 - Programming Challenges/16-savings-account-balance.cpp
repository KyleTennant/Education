// This program calculates the remaining balance of the users savings account
// for the last three months by using a for loop.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double yrInterestRate,          // Annual interest rate
		   moInterestRate,          // Monthly interest rate
		   startBal,                // Balance at start of the 3-mo. period
		   moBegBal,                // Balance at the beginning of a month
		   currentBal,              // Balance at intermediate point in a month
		   moEndBal,                // Balance at the end of a month
		   avgMoBal,                // Average monthly balance
		   deposited,               // Amount deposited in a single month
		   withdrawn,               // Amount withdrawn in a single month
		   moIntPaid,               // Interest paid in a single month
		   totalDeposits = 0.0,     // Total of all deposits
		   totalWithdrawals = 0.0,  // Total of all withdrawals
		   totalInterest = 0.0;     // Total interest earned

	double value; // Cheating

	// User is prompted to enter data
	cout << "Enter the starting balance: ";
	cin >> startBal;
	cout << "Enter the annual interest rate: ";
	cin >> yrInterestRate;

	value = startBal; // More Cheating
	moInterestRate = (yrInterestRate / 12) / 100;

	// For  loop iterates 3 times
	for (int x = 1; x <= 3; x++)
	{
		// User is prompt to enter data
		cout << "Month " << x << endl;
		cout << "Total deposits for this month: ";
		cin >> deposited;
		cout << "Total withdrawals for this month: ";
		cin >> withdrawn;

		// Calculations for the loop
		moBegBal = value;
		currentBal = moBegBal + deposited - withdrawn;
		avgMoBal = (moBegBal + currentBal) / 2;
		moIntPaid = avgMoBal * moInterestRate;
		moEndBal = currentBal + moIntPaid;
		value = moEndBal;
		
		totalDeposits += deposited;
		totalWithdrawals += withdrawn;
		totalInterest += moIntPaid;

		cout << "------------------------------------------------------------------" << endl;
	}

	cout << " " << endl;
	cout << "Quarterly Savings Account Statement" << endl;
	cout << setprecision(2) << fixed << endl;											// Sets decimal point
	cout << "Stating Balance:      $" << setw(10) << right << startBal << endl;			// Starting balance from beginning
	cout << "Total Deposits:      +$" << setw(10) << right << totalDeposits << endl;	// Total Deposits
	cout << "Total Withdrawals:   -$" << setw(10) << right << totalWithdrawals << endl;	// Total Withdrawals
	cout << "Total Interest:      +$" << setw(10) << right << totalInterest << endl;	// Total Interest Earned
	cout << "                       " << "__________" << endl;
	cout << "Ending Balance:       $" << setw(10) << right << moEndBal << endl;			// Remaining balance after calculation

	cin.ignore();
	cin.clear();
	cin.get();
	return 0;
}
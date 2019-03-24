// This program calculates the monthly interest rate on a loan.
#include <iostream>
#include <iomanip> //needed for stream manipulators
using namespace std;

int main()
{
	// Declaring variables
	double Loan, Rate, Payments, Monthly_Payment, Amount_Paid, Interest_Paid;

	// Prompting user to enter data
	cout << "Enter the loan amount: ";
		cin >> Loan;
	cout << "Enter the monthly interest rate: ";
		cin >> Rate;
	cout << "Enter the number of payments: ";
		cin >> Payments;

	// Calculations required to process desire output
	Rate = (Rate / 12);
	Monthly_Payment = (((Rate*0.01) * pow((1 + (Rate*0.01)), Payments))/(pow((1 + (Rate*0.01)), Payments) - 1)) * Loan;
	Amount_Paid = Payments * Monthly_Payment;
	Interest_Paid = Amount_Paid - Loan;

	// Ouptuting data recently entered and processed
	cout << "" << endl;
	cout << "Loan Amount:                      $" << right << setw(10) << Loan << endl;
	cout << "Monthly Interest Rate:             " << right << setw(10) << Rate << "%" << endl;
	cout << "Number of Payments:                " << right << setw(10) << Payments << endl;
	cout << setprecision(2) << fixed;
	cout << "Monthly Payment:                  $" << right << setw(10) << Monthly_Payment << endl;
	cout << "Amount Paid Back:                 $" << right << setw(10) << Amount_Paid << endl;
	cout << "Interest Paid:                    $" << right << setw(10) << Interest_Paid << endl;

	cin.get();
	return 0;
}
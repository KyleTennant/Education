// This program uses a class to calculate a monthly mortage payment
#include <iostream>
#include <cmath>
using namespace std;

// Mortgage class
class Mortgage
{
	private:
		// Member variables
		double mortgageAmt;
		double interestRate;
		int numberOfYrs;

	public:
		// Default Constructor
		Mortgage();
		
		// Mutators
		void setMortgageAmt(double);
		void setInterestRate(double);
		void setNumberOfYrs(int);

		// Accessors
		double getMonthlyPayment();
		double getTotalAmt();
};

// Default Constructor
Mortgage::Mortgage()
{
	setMortgageAmt(0);
	setInterestRate(0);
	setNumberOfYrs(0);
}

// Accessor functions
void Mortgage::setMortgageAmt(double myMortgageAmt)
{
	mortgageAmt = myMortgageAmt;
}
void Mortgage::setInterestRate(double myInterestRate)
{
	interestRate = myInterestRate;
}
void Mortgage::setNumberOfYrs(int myNumberOfYrs)
{
	numberOfYrs = myNumberOfYrs;
}

// Mutator functions
double Mortgage::getMonthlyPayment()
{
	double term = pow(1 + (interestRate / 12), 12 * numberOfYrs);
	double payment = (mortgageAmt * (interestRate / 12) * term) / (term - 1);
	
	return payment;
}
double Mortgage::getTotalAmt()
{
	return (getMonthlyPayment() * 12 * numberOfYrs);
}

// Main function
int main()
{
	// Class object
	Mortgage m;

	// Member variables
	char choice;
	double x, y;
	int z;

	// Do/While loop to process information
	do
	{
		// Promt user to enter information
		cout << "Enter mortgage amount: ";
		cin >> x;
		if (x <= 0)
		{
			cout << "Invalid Entry. Input must be positive." << endl;
			break;
		}
		cout << "Enter annual interest rate: ";
		cin >> y;
		if (y <= 0)
		{
			cout << "Invalid Entry. Input must be positive." << endl;
			break;
		}
		cout << "Enter number of years: ";
		cin >> z;
		if (z <= 0)
		{
			cout << "Invalid Entry. Input must be positive." << endl;
			break;
		}

		// Calculate user information
		m.setMortgageAmt(x);
		m.setInterestRate(y);
		m.setNumberOfYrs(z);

		// Diplay user calculated information 
		cout << "The monthly payment amount: $" << m.getMonthlyPayment() << endl;
		cout << "The total amount paid: $" << m.getTotalAmt() << endl;

		// Ask user if they wish to continnue
		cout << " " << endl;
		cout << "Do you wish to continue? (Y/N): ";
		cin >> choice;
		cout << " " << endl;
	}
	// If choice is anything but the letter N or n, loop repeats
	while (tolower(choice) != 'n');
}
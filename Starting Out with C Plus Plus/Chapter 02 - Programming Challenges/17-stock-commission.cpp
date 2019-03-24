// This program calculates and displays the amount paid for a stock
// with and without commission, the commission amount, and total
#include <iostream>
using namespace std;

int main()
{
	double shares, sharePrice, commision, amtPaid, commisionAmt, totalCost;

	shares = 750; //shares bought
	sharePrice = 35; //price per share
	commision = .02;

	amtPaid = shares * sharePrice;
	commisionAmt = amtPaid * commision;
	totalCost = amtPaid + commision;

	cout << "The amount paid for the stock without commision is $" << amtPaid << endl;
	cout << "The amount of commision is $" << commisionAmt << endl;
	cout << "The total amount is $" << totalCost << endl;

	return 0;
}
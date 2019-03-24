// This program computes the tax and tip on a restaurant bill
#include <iostream>
using namespace std;

int main()
{
	double meal, tax, tip, tax_amt, tip_amt, total_bill;

	meal = 88.67;
	tax = .0675;
	tip = .2;

	tax_amt = meal * tax;
	tip_amt = meal * tip;
	total_bill = meal + tax_amt + tip_amt;

	cout << "The cost of the meal is $" << meal << endl;
	cout << "The amount of tax owed is $" << tax_amt << endl;
	cout << "The amount of gratituity is $" << tip_amt << endl;
	cout << "The total cost of the meal is $" << total_bill << endl;

	return 0;
}
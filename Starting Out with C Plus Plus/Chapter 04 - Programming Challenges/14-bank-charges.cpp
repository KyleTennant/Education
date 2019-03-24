// This program uses a if statement to determine how many fees
// someone has based on their input.
#include <iostream>
using namespace std;

int main()
{
	double balance, checks, fees;

	cout << "Please enter your beginning balance: ";
	cin >> balance;
	cout << "Please enter the number of checks written: ";
	cin >> checks;

	if (balance < 400)
	{
		if (checks < 20)
		{
			fees = checks * .10;
		}
		else if (checks >= 20 && checks <= 39)
		{
			fees = checks * .08;
		}
		else if (checks >= 40 && checks <= 59)
		{
			fees = checks * .06;
		}
		else (checks >= 60)
		{
			fees = checks * .04;
		}
		
		fees += 25;
		cout << "Including the $10 a month fee for your commercial checking account,\n";
		cout << "there is an extra $15 fee when your balance is lower than $400.\n";
		cout << "The Total amount of fees for this month: " << fees << endl;
	}
	else (balance > 400)
	{
		if (checks < 20)
		{
			fees = checks * .10;
		}
		else if (checks >= 20 && checks <= 39)
		{
			fees = checks * .08;
		}
		else if (checks >= 40 && checks <= 59)
		{
			fees = checks * .06;
		}
		else (checks >= 60)
		{
			fees = checks * .04;
		}

		fees += 10;
		cout << "There is a $10 commercial checking account fee every month,\n";
		cout << "which brings the otal amount of fees for this month to: " << fees << endl;
	}

	cin.get();
	return 0;
}
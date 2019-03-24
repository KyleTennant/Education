// This program uses a if statement to determine how many points 
// someone has earned based on how many books they have bought.
#include <iostream>
using namespace std;

int main()
{
	double numBooks;

	cout << "Please enter the amount of books you have purchased today: ";
	cin >> numBooks;

	if (numBooks == 0)
	{
		cout << "You have earned 0 points.\n";
	}
	else if (numBooks == 1)
	{
		cout << "You have earned 5 points!\n";
	}
	else if (numBooks == 2)
	{
		cout << "You have earned 15 points!\n";
	}
	else if (numBooks == 3)
	{
		cout << "You have earned 30 points!\n";
	}
	else if (numBooks >= 4)
	{
		cout << "You have earned 60 points!\n";
	}
	else
	{
		cout << "Your entry is invalid.\n";
	}

	cin.get();
	return 0;
}
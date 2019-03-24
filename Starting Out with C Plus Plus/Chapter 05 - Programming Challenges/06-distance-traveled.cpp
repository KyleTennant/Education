// This program calculates the amount of hours and distance traveled by using
// an if statement followed by a for loop.
#include <iostream>
using namespace std;

int main()
{
	double x, mph, hours, distance;

	cout << "What is the speed of the vehicle in mph? ";
	cin >> mph;
	cout << "How many hours has the vehicle traveled? ";
	cin >> hours;

	distance = mph * hours;

	if (mph > 0 && hours > 0)
	{
		cout << "------------------------------------------" << endl;
		cout << "      Hour       Distance Traveled        " << endl;
		cout << "------------------------------------------" << endl;
		for (x = 1; x <= hours; x++)
		{
			cout << "       " << x << "                " << (x * mph) << "            " << endl;
		}
	cin.get();
	}
	else
	{
		cout << "Your entry is invalid.";
		cin.get();
	}
	
	cin.get();
	return 0;
}
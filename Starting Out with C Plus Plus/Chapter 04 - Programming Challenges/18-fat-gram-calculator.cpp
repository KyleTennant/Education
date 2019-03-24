// This program prompts the user to input calories and grams of food
// and calculates the precentage of calories within a gram using an if statement.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double calories, grams, totalCal, preOFcal;

	cout << "Please enter the total amount of calories: ";
	cin >> calories;
	cout << "Please enter the total amount of fat grams: ";
	cin >> grams;

	totalCal = grams * 9;
	preOFcal = totalCal / calories;


	if (preOFcal < .30)
	{
		cout << "The food is low in fat with a precentage of " << fixed << setprecision(2) << preOFcal << endl;
	}
	else
	{
		cout << "The food is high in fat with a precentage of " << fixed << setprecision(2) << preOFcal << endl;
	}

	cin.get();
	return 0;
}
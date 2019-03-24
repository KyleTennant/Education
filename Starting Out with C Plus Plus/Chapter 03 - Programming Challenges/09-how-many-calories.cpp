// This program calculates and display the amount of calories consumed by the
// amount of cookies consumed by the user.
#include <iostream>
using namespace std;

int main()
{
	// Declaring variables
	double Cookies, Calories;

	// Prompting user to provide amount of cookies consumed
	cout << "How many cookies did you eat? ";
	cin >> Cookies;

	// Formula for calculation
	Calories = Cookies * 100;

	// Conclusion to amount of calories consumed by the amount of cookies consumed
	cout << "You have consumed " << Calories << " calorie(s) after eating " << Cookies << " cookie(s).";

	return 0;
}
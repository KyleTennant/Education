// This program determines how much a hospital patient's expenses are.
// First an if/statement determines if the patient is an in-patient or out-patient.
// Second once determined a function is called to gather information from user.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double inPatient(double&, double&, double&, double&, double&);
double outPatient(double&, double&, double&);

int main()
{
	int choice;
	double val1, val2, val3, val4, val5;

	cout << "Enter (1) for in-patient OR (2) for out-patient: ";
	cin >> choice;

	// If/Statement determines type of patient
	if (choice == 1)
	{
		// Function call
		inPatient(val1, val2, val3, val4, val5);
	}
	else if (choice == 2)
	{
		// Function call
		outPatient(val1, val2, val3);
	}
	else
	{
		cout << "Your entry is invalid. Please enter 1 or 2.";
	}
		
	cin.ignore();
	cin.clear();
	cin.get();
	return 0;
}

// Function for in-patient. Calculates expenses. Passes by reference.
double inPatient(double &num1, double &num2, double &num3, double &num4, double &num5)
{
	cout << "Enter the number of days spent in the hospital: ";
	cin >> num1;
	cout << "Enter the daily rate: $";
	cin >> num2;
	cout << "Enter the hospital's medication charges: $";
	cin >> num3;
	cout << "Enter the hospital's service charges (lab tests, etc.): $";
	cin >> num4;

	num5 = 0.0;
	num5 = (num1 * num2) + num3 + num4; //Calculates total

	cout << setprecision(2) << fixed << endl;
	cout << "The total charges: $" << num5 << endl;

	return num1, num2, num3, num4, num5;
}

// Function for out-patient. Calculates expenses. Passes by reference.
double outPatient(double &num1, double &num2, double &num3)
{
	cout << "Enter the hospital's medication charges: $";
	cin >> num1;
	cout << "Enter the hospital's service charges (lab tests, etc.): $";
	cin >> num2;

	num3 = 0.0;
	num3 = (num1 + num2); //Calculates total

	cout << setprecision(2) << fixed << endl;
	cout << "The total charges: $" << num3 << endl;

	return num1, num2, num3;
}
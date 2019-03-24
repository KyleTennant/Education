// This program simulates a soft drink machine
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Vending machine structure
struct Machine
{
	string name;
	double cost;
	int num;
};

// Function prototypes
void inventory(Machine &, string, double, int);
int menu(Machine[]);
void payment(double);

int main()
{
	Machine drink[5];
	int choice;
	double made = 0;

	cout << "Please Order Your Delicious Cold Beverage" << endl;
	cout << " " << endl;

	// Drink menu display
	inventory(drink[0], "Cola", 0.75, 20);
	inventory(drink[1], "Root Beer", 0.75, 20);
	inventory(drink[2], "Lemon-Lime", 0.75, 20);
	inventory(drink[3], "Grape Soda", 0.80, 20);
	inventory(drink[4], "Cream Soda", 0.80, 20);
	
	choice = menu(drink);

	while (choice != 5)
	{
		payment(drink[choice].cost);

		made += drink[choice].cost;

		drink[choice].num--;
		
		choice = menu(drink);
	}

	cout << "Today the machine has made $" << setprecision(2) << fixed << made << endl;
	cout << " " << endl;

	return 0;
}

// Payment function
void payment(double p)
{
	double pay;

	// Prompt user to pay
	cout << "Your drink costs: $" << setprecision(2) << fixed << p << endl;
	cout << "Enter payment: $";
	cin >> pay;

	// Validate input
	while (pay < 0 || pay > 1. || pay < p)
	{
		cout << "Enter at least $0.75 and no more than $1.00." << endl;
		cout << " " << endl;
		cout << "Enter payment: ";
		cin >> pay;
	}

	// Display results
	cout << " " << endl;
	cout << "Thump, thump, thump, splat!" << endl;

	cout << "Enjoy your beverage!" << endl;
	cout << " " << endl;
	cout << "Change Calculated: $" << setprecision(2) << fixed << (pay - p) << endl;

	cout << "Your change has dropped into the change dispenser." << endl;
	cout << " " << endl;

	return;
}

// Inventory function
void inventory(Machine &d, string n, double c, int num)
{
	d.name = n;
	d.cost = c;
	d.num = num;
}

// Menu function
int menu(Machine d[])
{
	int choice = 8;
	bool soldout = true;

	// Validate drink choice
	while ((choice < 1 || choice > 6) || soldout)
	{
		soldout = false;

		// Display menu format
		for (int i = 0; i < 5; i++)
		{
			cout << i + 1 << ". " << setw(15) << left << d[i].name << setw(5);
			cout << setprecision(2) << fixed << d[i].cost << "\t" << d[i].num << endl;
		}

		cout << "6. Leave the drink machine." << endl;
		cout << " " << endl;
		cout << "Choice one: ";
		cin >> choice;

		if (choice < 1 || choice > 6)
		{
			cout << " " << endl;
			cout << "Bad Choice. Choose again." << endl;
			cout << " " << endl;
		}
		else
		{
			if (d[choice - 1].num == 0)
			{
				cout << "Sorry, that selection is sold out." << endl;
				soldout = true;
			}
		}
	}
	return choice - 1;
}
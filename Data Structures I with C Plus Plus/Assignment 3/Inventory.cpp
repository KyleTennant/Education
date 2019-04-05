//************************************************************
//
//		File:			Inventory.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #3		
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			February 15, 2018
//
//		In this program I store data into an unsorted
//		linked list and calculate totals and averages.
//		
//************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "List.h"
using namespace std;

// Structure for each entry
struct Product
{
	string UPC;
	string desription;
	double price;
	double inventory;
	double totalValue;
	Product()
	{
		UPC = ""; desription = ""; price = 0.0; inventory = 0.0; totalValue = 0.0;
	}
	bool operator == (const Product& n)
	{
		if (UPC == n.UPC) return true; return false;
	}
};

// Function Prototypes
void getData(List<Product>&);
void displayList(List<Product>&);
void findProduct(List<Product>&);

// Main Function
int main()
{
	List<Product> a;
	getData(a);
	displayList(a);
	findProduct(a);

	return 0;
}

// Function retrieves the data from file
void getData(List<Product>& n)
{
	Product b;

	ifstream inFile("Inventory.csv");

	if (!inFile)
	{
		cout << "Problem opening Inventory.csv file." << endl;
		exit(99);
	}

	getline(inFile, b.UPC, ',');
	getline(inFile, b.desription, ',');
	inFile >> b.price;
	inFile.ignore();
	inFile >> b.inventory;
	inFile.ignore();

	while (!inFile.eof())
	{
		if (b.price > 0) 
		{
			b.totalValue = (b.price * b.inventory);
		}
		else 
		{
			b.totalValue = 0;
		}

		n.insert(b);

		getline(inFile, b.UPC, ',');
		if (b.UPC != "")
		{
			getline(inFile, b.desription, ',');
			inFile >> b.price;
			inFile.ignore();
			inFile >> b.inventory;
			inFile.ignore();
		}
	}
}

// Function displpays the data to console
void displayList(List<Product>& n)
{
	Product c;
	int count = 0;
	double cost;
	double amount;
	double totalInv = 0.0;
	double totalVal = 0.0;
	double totalAmt = 0.0;
	double AvgAmtVal;
	double totalProCost = 0.0;
	double AvgProCost;

	bool more = n.first(c);

	if (!more)
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		while (more)
		{
			cout << setw(4) << left << c.UPC << '\t'
				 << setw(30) << left << c.desription << '\t'
				 << fixed << setprecision(2) << setw(4) << left << c.price << '\t'
				 << fixed << setprecision(0) << setw(4) << left << c.inventory << '\t'
				 << fixed << setprecision(2) << setw(8) << c.totalValue << endl;

			cost = c.price;
			amount = c.inventory;
			totalInv += c.inventory;
			totalVal = (cost * amount);
			totalAmt += totalVal;
			totalProCost += cost;

			more = n.getNext(c);

			count++;
		}

		AvgAmtVal = (totalAmt / count);
		AvgProCost = (totalAmt / totalInv);

		cout << "The total product value is: " << fixed << setprecision(2) << setw(8) << totalAmt << endl;
		cout << "The average product value is: " << fixed << setprecision(2) << setw(8) << AvgAmtVal << endl;
		cout << "The average product cost is: " << fixed << setprecision(2) << setw(8) << AvgProCost << endl;
	}
}

// Function searches list for certain element
void findProduct(List<Product>& n)
{
	Product d;
	string UPC;
	bool found = false;

	cout << "Enter the UPC of a product to locate: ";
	getline(cin, UPC);

	while (UPC != "0")
	{
		d.UPC = UPC;
		found = n.find(d);

		if (found)
			cout << setw(4) << left << d.UPC << '\t'
				 << setw(30) << left << d.desription << '\t'
				 << fixed << setprecision(2) << setw(4) << left << d.price << '\t'
				 << fixed << setprecision(0) << setw(4) << left << d.inventory << '\t'
				 << fixed << setprecision(2) << setw(8) << d.totalValue << endl;
		else
			cout << "That product is not in the inventory.\n";

		cout << "Enter the UPC of a product to locate: ";
		getline(cin, UPC);
	}
}
//************************************************************
//
//		File:			Inventory.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #2		
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			February 8, 2018
//
//		In this assignment, I develop a program using a 
//		templated class named List. With the templated list
//		I practice writing pointers, dynamic memory allocation,
//		a copy constructor, and a destructor.
//		
//************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "List.h"
using namespace std;

struct Product
{
	string UPC;
	string desription;
	double price;
	double invAmt;
	double totalValue;
	Product()
	{
		UPC = ""; desription = ""; price = 0.0; invAmt = 0.0; totalValue = 0.0;
	}
	bool operator == (const Product& n)
	{
		if (UPC == n.UPC) return true; return false;
	}
};

void getData(List<Product>&);
void displayList(List<Product>&);
void findProduct(List<Product>&);
void setupCenter(List<Product>&, double factor);

int main()
{
	List<Product> a;
	getData(a);
	displayList(a);
	findProduct(a);

	List<Product> WestCenter = a;
	List<Product> SouthCenter = a;
	
	setupCenter(WestCenter, 30);
	cout << "----------------------------------------------------------\n";
	cout << "The following data is for the new West Center.\n";
	displayList(WestCenter);

	setupCenter(SouthCenter, 20);
	cout << "----------------------------------------------------------\n";
	cout << "The following data is for the new South Center.\n";
	displayList(SouthCenter);

	setupCenter(a, 50);
	cout << "----------------------------------------------------------\n";
	cout << "The following data is for the new Webster Frozen Foods.\n";
	displayList(a);

	return 0;
}

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
	inFile >> b.invAmt;
	inFile.ignore();

	while (!inFile.eof())
	{
		if (b.price > 0)
		{
			b.totalValue = (b.price * b.invAmt);
		}
		else
		{
			b.totalValue = 0;
		}

		n.addMember(b);

		getline(inFile, b.UPC, ',');
		if (b.UPC != "")
		{
			getline(inFile, b.desription, ',');
			inFile >> b.price;
			inFile.ignore();
			inFile >> b.invAmt;
			inFile.ignore();
		}
	}
}

void displayList(List<Product>& n)
{
	Product c;
	double cost;
	double amount;
	double totalInv = 0.0;
	double totalVal = 0.0;
	double totalAmt = 0.0;
	double AvgAmtVal;
	double totalProCost = 0.0;
	double AvgProCost;

	for (int i = 0; i < n.getNumber(); i++)
	{
		c = n.getNext();

		cout << setw(4) << left << c.UPC << '\t'
			<< setw(30) << left << c.desription << '\t'
			<< fixed << setprecision(2) << setw(4) << left << c.price << '\t'
			<< fixed << setprecision(0) << setw(4) << left << c.invAmt << '\t'
			<< fixed << setprecision(2) << setw(8) << c.totalValue << endl;

		cost = c.price;
		amount = c.invAmt;
		totalInv += c.invAmt;
		totalVal = (cost * amount);
		totalAmt += totalVal;
		totalProCost += cost;

	}

	AvgAmtVal = (totalAmt / n.getNumber());
	AvgProCost = (totalAmt / totalInv);

	cout << "The total product value is: " << fixed << setprecision(2) << setw(8) << totalAmt << endl;
	cout << "The average product value is: " << fixed << setprecision(2) << setw(8) << AvgAmtVal << endl;
	cout << "The average product cost is: " << fixed << setprecision(2) << setw(8) << AvgProCost << endl;

}

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
		found = n.getMember(d);

		if (found)
			cout << setw(4) << left << d.UPC << '\t'
			<< setw(30) << left << d.desription << '\t'
			<< fixed << setprecision(2) << setw(4) << left << d.price << '\t'
			<< fixed << setprecision(0) << setw(4) << left << d.invAmt << '\t'
			<< fixed << setprecision(2) << setw(8) << d.totalValue << endl;
		else
			cout << "That product is not in the inventory.\n";

		cout << "Enter the UPC of a product to locate: ";
		getline(cin, UPC);
	}
}

void setupCenter(List<Product>& n, double factor)
{
	Product e;
	double amount;
	double cost;
	double total = 0.0;

	for (int i = 0; i < n.getNumber(); i++)
	{
		e = n.getNext();

		amount = e.invAmt;
		amount *= (factor / 100);
		e.invAmt = amount;

		cost = e.price;
		total = (cost * amount);
		e.totalValue = total;

		n.setItem(e);
	}
}
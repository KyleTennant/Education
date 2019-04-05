//************************************************************
//
//		File:			Inventory.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #1		
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			February 1, 2018
//
//		This program using a list class template located in a
//		header file to sort through data. 
//		
//************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "List.h"
using namespace std;

struct WebsterFrozenFoods
{
	string UPC;
	string desription;
	double price;
	double invAmt;
	double totalValue;
	WebsterFrozenFoods()
	{
		UPC = ""; desription = ""; price = 0.0; invAmt = 0.0; totalValue = 0.0;
	}
	bool operator == (const WebsterFrozenFoods& n)
	{
		if (UPC == n.UPC) return true; return false;
	}
};

void getData(List<WebsterFrozenFoods>&);
void displayList(List<WebsterFrozenFoods>&);
void findProduct(List<WebsterFrozenFoods>&);

int main()
{
	List<WebsterFrozenFoods> inv;
	getData(inv);
	displayList(inv);
	findProduct(inv);
	return 0;
}

void getData(List<WebsterFrozenFoods>& n)
{
	WebsterFrozenFoods b;

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

		n.insert(b);

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

void displayList(List<WebsterFrozenFoods>& n)
{
	WebsterFrozenFoods c;
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

void findProduct(List<WebsterFrozenFoods>& n)
{
	WebsterFrozenFoods d;
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
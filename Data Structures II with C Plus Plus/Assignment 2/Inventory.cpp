//************************************************************
//
//		File:			Inventory.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #2		
//
//		Course Name:	Data Structures II
//
//		Course Number:	COSC 3100
//
//		Due:			April 12, 2018
//		
//************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "HashTable.h"
using namespace std;

//************************************************************
struct Product
{
	string UPC;
	string description;
	double cost;
	double amount;

	Product() { UPC = " "; description = " "; cost = 0.0; amount = 0; }

	bool operator==(const Product& s)
	{
		if (UPC == s.UPC) return true; return false;
	}

	friend ostream& operator << (ostream& outFile, const Product& s)
	{
		outFile << setw(8) << left << fixed << s.UPC
			<< setw(25) << left << fixed << s.description
			<< setw(8) << right << fixed << setprecision(2) << s.cost
			<< setw(8) << right << fixed << setprecision(0) << s.amount;
		return outFile;
	}

};

//************************************************************
void getData(HashTable<Product>&);
void displayProduct(HashTable<Product>&);
int hf1(const Product &);
const int SIZE = 6;

//************************************************************
int main()
{
	HashTable<Product> Inventory(hf1, SIZE);
	getData(Inventory);
	cout << "The collisions were " << List<Product>::getCollision() << endl;
	cout << " " << endl;
	displayProduct(Inventory);
	return 0;
}

//************************************************************
void getData(HashTable<Product>& cls)
{
	Product p;
	ifstream inFile("Inventory.csv");

	if (!inFile)
	{
		cout << "Problem opening Inventory.csv file." << endl;
		exit(99);
	}

	getline(inFile, p.UPC, ',');
	getline(inFile, p.description, ',');
	inFile >> p.cost;
	inFile.ignore();
	inFile >> p.amount;
	inFile.ignore();

	while (!inFile.eof())
	{
		cls.insert(p);
		getline(inFile, p.UPC, ',');
		if (p.UPC != "")
		{
			getline(inFile, p.description, ',');
			inFile >> p.cost;
			inFile.ignore();
			inFile >> p.amount;
			inFile.ignore();
		}
	}
}

//************************************************************
void displayProduct(HashTable<Product> &s)
{
	Product product;
	string UPC;
	bool found = false;

	cout << "Enter the UPC of the product (0 to end): ";
	cin >> UPC;

	string sUPC = UPC;
	int iUPC = stoi(sUPC);

	while (iUPC != 0)
	{
		product.UPC = UPC;
		found = s.retrieve(product);
		if (found)
			cout << "Product " << UPC << " found.\n";
		else
			cout << "Product " << UPC << " not found.\n";

		cout << " " << endl;
		cout << "************************************************************************************" << endl;
		cout << " " << endl;
		cout << "Enter the UPC of the product (0 to end): ";
		cin >> UPC;

		sUPC = UPC;
		iUPC = stoi(sUPC);

	}
}

//************************************************************
int hf1(const Product & s)
{
	string sUPC = s.UPC;
	int iUPC = stoi(sUPC);
	return iUPC%SIZE;
}
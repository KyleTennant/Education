//************************************************************
//
//		File:			BigO.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #1		
//
//		Course Name:	Data Structures II
//
//		Course Number:	COSC 3100
//
//		Due:			April 5, 2018
// 
//		This program compares the time complexities of
//		several BigO algorithms.
//		
//************************************************************
#include <iostream>

using namespace std;

// Function Prototypes
void firstFunction();
void secondFunction();
void thirdFunction();
void fourthFunction();
void fifthFunction();
void sixthFunction();
void seventhFunction();

// Main Function
int main() 
{
	cout << "\t\tn=30\t\tn=1000" << endl;

	firstFunction();
	secondFunction();
	thirdFunction();
	fourthFunction();
	fifthFunction();
	sixthFunction();
	seventhFunction();

	return 0;
}

// Function O(1)
void firstFunction()
{
	int const SIZE = 2;
	int array[SIZE] = { 30, 1000 };
	int n = 0;
	int i = 0;

	cout << "O(1)\t\t";

	while (i != SIZE) {
		cout << ++n << "\t\t";
		n = 0;
		i++;
	}

	cout << "\n";
	return;
}

// Function O(n)
void secondFunction()
{
	int const SIZE = 2;
	int array[SIZE] = { 30, 1000 };
	int n = 0;
	int i = 0;

	cout << "O(n)\t\t";

	while (i != SIZE) {
		for (int j = 0; j < array[i]; j++) {
			n++;
		}
		cout << n << "\t\t";
		n = 0;
		i++;
	}

	cout << "\n";
	return;
}

// Function O(n2)
void thirdFunction()
{
	int const SIZE = 2;
	int array[SIZE] = { 30, 1000 };
	int n = 0;
	int i = 0;
	
	cout << "O(n2)\t\t";

	while (i != SIZE) {
		for (int j = 0; j < array[i]; j++) {
			for (int k = 0; k < array[i]; k++) {
				n++;
			}
		}
		cout << n << "\t\t";
		n = 0;
		i++;
	}

	cout << "\n";
	return;
}

// Function O(n3)
void fourthFunction()
{
	int const SIZE = 2;
	int array[SIZE] = { 30, 1000 };
	int n = 0;
	int i = 0;

	cout << "O(n3)\t\t";

	while (i != SIZE) {
		for (int j = 0; j < array[i]; j++) {
			for (int k = 0; k < array[i]; k++) {
				for (int l = 0; l < array[i]; l++) {
					n++;
				}
			}
		}
		cout << n << "\t\t";
		n = 0;
		i++;
	}

	cout << "\n";
	return;
}

// Function O(lg n)
void fifthFunction()
{
	int const SIZE = 2;
	int array[SIZE] = { 30, 1000 };
	int n = 0;
	int i = 0;

	cout << "O(lg n)\t\t";

	while (i != SIZE) {
		for (int j = 1; j <= array[i]; j = j * 2) {
			n++;
		}

		cout << n << "\t\t";
		n = 0;
		i++;
	}

	cout << "\n";
	return;
}

// Function O(n lg n)
void sixthFunction()
{
	int const SIZE = 2;
	int array[SIZE] = { 30, 1000 };
	int n = 0;
	int i = 0;

	cout << "O(n lg n)\t";

	while (i != SIZE) {
		for (int j = 0; j < array[i]; j++) {
			for (int k = 1; k <= array[i]; k = k * 2) {
				n++;
			}
		}

		cout << n << "\t\t";
		n = 0;
		i++;
	}

	cout << "\n";
	return;
}

// Function O(n2 lg n)
void seventhFunction()
{
	int const SIZE = 2;
	int array[SIZE] = { 30, 1000 };
	int n = 0;
	int i = 0;

	cout << "O(n2 lg n)\t";

	while (i != SIZE) {
		for (int j = 0; j < array[i]; j++) {
			for (int k = 0; k < array[i]; k++) {
				for (int l = 1; l <= array[i]; l = l * 2) {
					n++;
				}
			}
		}

		cout << n << "\t\t";
		n = 0;
		i++;
	}

	cout << "\n";
	return;
}
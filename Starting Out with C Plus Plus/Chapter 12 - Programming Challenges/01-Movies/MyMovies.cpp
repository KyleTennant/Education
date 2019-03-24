#include <iostream>
#include <string>
#include <fstream>
#include "Movies.h"
using namespace std;

// Function prototypes
int menu();
void purchase(Collection&);
void displayMovies(Collection&);
void find(Collection&);

// Setting default constructors max capacity to 20
const int SIZE = 20;

int main()
{
	Collection MyMovies(SIZE);

	int option = menu();

	while (option != 4)
	{
		switch (option)
		{
		case 1: purchase(MyMovies);
			break;
		case 2: displayMovies(MyMovies);
			break;
		case 3: find(MyMovies);
			break;
		}
		option = menu();
	}
	return 0;
}

// Displays the menu
int menu()
{
	int option;

	do
	{
		cout << "----------------------------------------" << endl;
		cout << "        My Movie Collection Menu        " << endl;
		cout << "----------------------------------------" << endl;
		cout << "1. Purchase a Movie for the Colelction" << endl;
		cout << "2. Display all Movies in the Collection" << endl;
		cout << "3. Find a Movie in the Collection" << endl;
		cout << "4. Exit" << endl;
		cout << " " << endl;
		cout << "Select One: ";
		cin >> option;

		if (option < 1 || option > 4)
		{
			cout << "Invalid option - Please re-enter: ";
		}
	} while (option < 1 || option > 4);
	
	return option;
}

// Purchase a movie
void purchase(Collection& x)
{
	bool found = false;
	Movie m;

	cout << "Enter MPAC: ";
	cin >> m.MPAC;

	while (m.MPAC != 0)
	{
		cin.ignore();
		cout << "Enter movie title: ";
		getline(cin, m.title);
		cout << "Enter year released: ";
		cin >> m.yearReleased;
		cout << "Enter run time in minutes: ";
		cin >> m.runTime;
		cout << " " << endl;

		found = x.buy(m);
		if (found)
		{
			cout << "The movie is already in the collection." << endl;
			cout << " " << endl;
		}
		else
		{
			cout << "That movie has been added to the collection." << endl;
			cout << " " << endl;
		}

		cout << "Enter MPAC (0 to Exit): ";
		cin >> m.MPAC;
	}
}

// Display movies owned
void displayMovies(Collection& x)
{
	Movie m;

	cout << "----------------------------------------" << endl;
	cout << "             My Movie List              " << endl;
	cout << "----------------------------------------" << endl;

	for (int i = 0; i < x.getNumOfMovies(); i++)
	{
		m = x.getNext();
		cout << "MPAC: " << m.MPAC
			<< "  Title: " << m.title
			<< "  Year Released: " << m.yearReleased
			<< "  Run Time: " << m.runTime
			<< endl;
	}

	cout << "I have " << x.numOfMovies << " movie(s)." << endl;
}

// Find a certain movie owned
void find(Collection& x)
{
	bool found = false;
	Movie m;
	int MPAC;

	cout << "Enter the MPAC code of the movie to display (0 to exit): ";
	cin >> MPAC;

	while (MPAC != 0)
	{
		m.MPAC = MPAC;
		found = x.find(m);

		if (found)
		{
			cout << "Found the movie - " 
				 << "MPAC: " << m.MPAC
				 << "  Title: " << m.title
				 << "  Year Released " << m.yearReleased
				 << "  Run Time " << m.runTime
				 << endl;
		}
		else
		{
			cout << "That movie was not found. " << endl;
		}

		cout << "Enter the MPAC code of the movie to display (0 to exit): ";
		cin >> MPAC;
	}
}
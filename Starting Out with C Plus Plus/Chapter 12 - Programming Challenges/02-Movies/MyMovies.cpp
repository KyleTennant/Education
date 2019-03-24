#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "Movies.h"
using namespace std;

// Function prototypes
int menu();
void loadData(Collection&);
void purchase(Collection&);
void sell(Collection&);
void displayMovies(Collection&);
void find(Collection&);

// Setting default constructors max capacity to 25
const int SIZE = 25;

int main()
{
	Collection MyMovies(SIZE);
	loadData(MyMovies);

	int option = menu();

	while (option != 5)
	{
		switch (option)
		{
		case 1: displayMovies(MyMovies);
			break;
		case 2: purchase(MyMovies);
			break;
		case 3: sell(MyMovies);
			break;
		case 4: find(MyMovies);
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
		cout << "1. Display all Movies in the Collection" << endl;
		cout << "2. Purchase a Movie for the Collection" << endl;
		cout << "3. Sell a Movie from the Collection" << endl;
		cout << "4. Find a Movie in the Collection" << endl;
		cout << "5. Exit" << endl;
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


void loadData(Collection& x)
{
	Movie m;
	fstream file("Movies.csv");

	if (file.fail())
	{
		cout << "File did not open." << endl;
		exit(99);
	}
	file >> m.MPAC;
	file.ignore();
	getline(file, m.title, ',');
	file >> m.yearReleased;
	file >> m.runTime;
	while(!file.eof())
	{
		file >> m.MPAC;
		file.ignore();
		getline(file, m.title, ',');
		file >> m.yearReleased;
		file >> m.runTime;
	}
	cout << "Movie Collection was loaded." << endl;
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

// Sell a movie
void sell(Collection& x)
{
	bool found = false;
	Movie m;

	cout << "Enter MPAC: ";
	cin >> m.MPAC;

	while (m.MPAC != 0)
	{
		found = x.sell(m);
		if (found)
		{
			cout << "That movie has been sold." << endl;
			cout << " " << endl;
		}
		else
		{
			cout << "That movie is not in the Collection." << endl;
			cout << " " << endl;
		}

		cout << "Enter MPAC (0 to Exit): ";
		cin >> m.MPAC;
	}
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
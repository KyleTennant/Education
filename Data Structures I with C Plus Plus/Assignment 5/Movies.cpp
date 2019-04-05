//************************************************************
//
//		File:			Movies.cpp
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment #5 Part 2
//
//		Course Name:	Data Structures I
//
//		Course Number:	COSC 3050
//
//		Due:			March 1, 2018
//
//		This program uses a sorted linked list and a 
//		stack to process data from a file and outputs
//		it to another file.
//		
//************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "List.h"
#include "Stack.h"
using namespace std;

//************************************************************
//******************* Product Structure **********************
//************************************************************
struct Movie
{
	int MPAC;
	string title;
	int year;
	int time;
	int amtIn;
	int amtOut;
	Movie()
	{
		MPAC = 0; title = ""; year = 0; time = 0; amtIn = 0; amtOut = 0;
	}
	bool operator == (const Movie& n)
	{
		if (MPAC == n.MPAC) return true; else return false;
	}
	bool operator >= (const Movie& n)
	{
		if (MPAC >= n.MPAC) return true; else return false;
	}
};

//************************************************************
//****************** Function Prototypes *********************
//************************************************************
void getData(List<Movie>&);
void movieOutput(List<Movie>&, ofstream&);
void returns(List<Movie>&);
void checkouts(int, List<Movie>&);
void checkins(int, Stack<int>&, List<Movie>&, ofstream&);

//************************************************************
//********************* Main Function ************************
//************************************************************
int main()
{
	List<Movie> movieList;
	getData(movieList);
	returns(movieList);

	return 0;
}

//************************************************************
//******************** getData Function **********************
//************************************************************
void getData(List<Movie>& m)
{
	Movie a;

	ifstream inFile("Movies.csv");

	if (!inFile)
	{
		cout << "Problem opening Movies.csv file." << endl;
		exit(99);
	}

	while (!inFile.eof())
	{
		inFile >> a.MPAC;
		inFile.ignore();
		getline(inFile, a.title, ',');
		inFile >> a.year;
		inFile.ignore();
		inFile >> a.time;
		inFile.ignore();
		inFile >> a.amtIn;
		inFile.ignore();
		inFile >> a.amtOut;
		inFile.ignore();
		m.insert(a);
	}
	inFile.close();
}

//************************************************************
//***************** movieOutput Function *********************
//************************************************************
void movieOutput(List<Movie>& m, ofstream& outFile)
{
	Movie b;

	bool more = m.first(b);

	if (!more)
	{
		outFile << "The list is empty." << endl;
	}
	else
	{
		outFile << "The following is the Webster Movies list:\n\n";
		while (more)
		{
			outFile << setw(4) << left << b.MPAC << '\t'
					<< setw(30) << left << b.title << '\t'
					<< fixed << setprecision(2) << setw(4) << left << b.year << '\t'
					<< fixed << setprecision(0) << setw(4) << left << b.time << '\t'
					<< fixed << setprecision(2) << setw(8) << b.amtIn << '\t'
					<< fixed << setprecision(2) << setw(8) << b.amtOut << endl << endl;
					more = m.getNext(b);
		}
	}
}

//************************************************************
//******************* returns Function ***********************
//************************************************************
void returns(List<Movie>& m) 
{
	Stack<int> stack;

	ifstream inFile("Returns.txt");
	if (!inFile)
	{
		cout << "Problem opening Returns.txt file." << endl;
		exit(99);
	}

	ofstream outFile("MoviesReport.txt");
	movieOutput(m, outFile);
	outFile << "The transactions are:\n\n";

	char command;
	int MPAC;

	while (!inFile.eof())
	{
		inFile >> command;
		inFile >> MPAC;

		switch (command)
		{
			case 'C':
			{
				outFile << "Movie " << MPAC << " was checked out.\n\n";
				checkouts(MPAC, m);
				break;
			}
			case 'R':
			{
				outFile << "Movie " << MPAC << " was placed on the stack.\n\n";
				stack.push(MPAC);
				break;
			}
			case 'P':
			{
				outFile << "The clerk can process " << MPAC << " return(s).\n\n";
				checkins(MPAC, stack, m, outFile);
				movieOutput(m, outFile);
				break;
			}
			default: { break; }
		}
	}

	outFile << "The final WebsterMovies report for the day.\n\n";
	movieOutput(m, outFile);
	outFile.close();
}

//************************************************************
//****************** checkouts Function **********************
//************************************************************
void checkouts(int MPAC, List<Movie>& m)
{
	Movie c;
	c.MPAC = MPAC;
	bool found = m.getMember(c);

	if (found)
	{
		c.amtIn--;
		c.amtOut++;
		m.update(c);
	}

}

//************************************************************
//****************** checkins Function ***********************
//************************************************************
void checkins(int MPAC, Stack<int>& stack, List<Movie>& m, ofstream& outFile)
{
	Movie d;
	for (int i = 0; i < MPAC; i++)
	{
		if (stack.empty())
		{
			return;
		}
		else
		{
			int code = stack.getTop();
			stack.pop();
			d.MPAC = code;

			bool found = m.getMember(d);
			if (found)
			{
				d.amtIn++;
				d.amtOut--;
				m.update(d);
				outFile << "Movie " << code << " was checked in.\n\n";
			}

			if (stack.empty()) outFile << "You have caught up with the stack.\n\n";
		}
	}
}
// This program is a modified version of the previous programs.
// This program compares two .csv files and outputs the results into a .dat file.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 30;

struct Movie
{
	int MPAC;
	char title[SIZE];
	int YR;
	double RT;
};

int main()
{
	Movie m;
	string name;
	int MPAC;
	long int locator;

	ifstream ifile("newMovies.csv");
	if (!ifile)
	{
		cout << "Error opening newMovies.csv" << endl;
		return 0;
	}
	ifstream ofile("Movies.dat", ios::out | ios::binary);
	if (!ofile)
	{
		cout << "Error reopening Movies.dat" << endl;
		return 0;
	}

	while (!ifile.eof())
	{
			ifile >> m.MPAC;
			ifile.ignore();
			getline(ifile, name, ',');
			strcpy_s(m.title, name.c_str());
			ifile >> m.YR;
			ifile.ignore();
			ifile >> m.RT;
	}

	ifile.close();
	ofile.close();

	fstream mfile("Movies.dat", ios::in | ios::binary);
	cout << "---------------------------------------------------------" << endl;
	cout << " MPAC\tTitle\t\t\t\tYear\tRunTime\n";
	cout << "---------------------------------------------------------" << endl;
	mfile.read(reinterpret_cast<char *>(&m), sizeof(m));
	while (!mfile.eof())
	{
		cout << " " << m.MPAC << '\t' << setw(30) << left << m.title << "\t" << m.YR << '\t' << m.RT << endl;
		mfile.read(reinterpret_cast<char *>(&m), sizeof(m));
	}

	mfile.clear();
	
	cout << "\n Enter a MPAC to find (0 to end): ";
	cin >> MPAC;

	while (MPAC != 0)
	{
		locator = (MPAC - 1100) * sizeof(m);
		mfile.seekg(locator, ios::beg);
		mfile.read(reinterpret_cast<char *>(&m), sizeof(m));
		if (mfile.fail())
		{
			cout << "\n That movie is not in the file.\n" << endl;
			mfile.clear();
		}
		else
		{
			cout << "---------------------------------------------------" << endl;
			cout << " " << m.MPAC << '\t' << setw(30) << left << m.title << "\t" << m.YR << '\t' << m.RT << endl;
			cout << "---------------------------------------------------" << endl;
		}
		cout << " Enter a MPAC to find (0 to end): ";
		cin >> MPAC;
	}

	return 0;
}
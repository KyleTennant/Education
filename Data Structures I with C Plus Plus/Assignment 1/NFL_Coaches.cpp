//************************************************************
//
//		File:			NFL_Coaches.cpp
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

struct NFL_Coaches
{
	string teamName;
	string coachName;
	int numOfWins;
	int numOfLosses;
	int numOfTies;
	int coachBirthYr;
	int YrsOfExp;
	double percentOfWins;
	int coachAge;
	NFL_Coaches()
	{
		teamName = " "; coachName = " "; numOfWins = 0;
		numOfLosses = 0; numOfTies = 0; coachBirthYr = 0; YrsOfExp = 0;
		percentOfWins = 0.0; coachAge = 0;
	}
	bool operator == (const NFL_Coaches& n)
	{
		if (coachName == n.coachName)return true; return false;
	}
};

void getData(List<NFL_Coaches>&);
void displayCoach(List<NFL_Coaches>&);
void displayList(List<NFL_Coaches>&);

int main()
{
	List<NFL_Coaches> list;
	getData(list);
	displayList(list);
	displayCoach(list);
	return 0;
}

void getData(List<NFL_Coaches>& cls)
{
	NFL_Coaches nfl_coaches;

	ifstream inFile("NFL_Coaches.csv");

	if (!inFile)
	{
		cout << "Problem opening NFL_Coaches.csv file." << endl;
		exit(99);
	}

	getline(inFile, nfl_coaches.teamName, ',');
	getline(inFile, nfl_coaches.coachName, ',');
	inFile >> nfl_coaches.numOfWins;
	inFile.ignore();
	inFile >> nfl_coaches.numOfLosses;
	inFile.ignore();
	inFile >> nfl_coaches.numOfTies;
	inFile.ignore();
	inFile >> nfl_coaches.coachBirthYr;
	inFile.ignore();
	inFile >> nfl_coaches.YrsOfExp;
	inFile.ignore();

	while (!inFile.eof())
	{
		if ((nfl_coaches.numOfWins + nfl_coaches.numOfLosses + nfl_coaches.numOfTies) > 0)
		{
			nfl_coaches.percentOfWins = (nfl_coaches.numOfWins) *1.0 / 
			(nfl_coaches.numOfWins + nfl_coaches.numOfLosses + nfl_coaches.numOfTies);
		}
		else
		{
			nfl_coaches.percentOfWins = 0;
		}
		
		nfl_coaches.coachAge = (2017 - nfl_coaches.coachBirthYr);

		cls.insert(nfl_coaches);

		getline(inFile, nfl_coaches.teamName, ',');
		if (nfl_coaches.teamName != "")
		{
			getline(inFile, nfl_coaches.coachName, ',');
			inFile >> nfl_coaches.numOfWins;
			inFile.ignore();
			inFile >> nfl_coaches.numOfLosses;
			inFile.ignore();
			inFile >> nfl_coaches.numOfTies;
			inFile.ignore();
			inFile >> nfl_coaches.coachBirthYr;
			inFile.ignore();
			inFile >> nfl_coaches.YrsOfExp;
			inFile.ignore();
		}
	}

}

void displayCoach(List<NFL_Coaches>& n)
{
	NFL_Coaches nfl_coaches;

	string coachName;
	bool found = false;

	cout << "Enter the name of the coach to display: ";
	getline(cin, coachName);

	while (coachName != "")
	{
		nfl_coaches.coachName = coachName;
		found = n.getMember(nfl_coaches);

		if (found)
			cout << setw(20) << left << nfl_coaches.teamName << '\t'
				<< setw(20) << left << nfl_coaches.coachName << '\t'
				<< setw(4) << left << nfl_coaches.numOfWins << '\t'
				<< setw(4) << left << nfl_coaches.numOfLosses << '\t'
				<< setw(4) << left << nfl_coaches.numOfTies << '\t'
				<< setw(4) << left << nfl_coaches.coachBirthYr << '\t'
				<< setw(4) << left << nfl_coaches.YrsOfExp << '\t'
				<< setw(4) << left << nfl_coaches.coachAge << '\t'
				<< fixed << setprecision(2) << setw(4) << left
				<< nfl_coaches.percentOfWins << endl;
		else
			cout << "The coach " << coachName << " is not listed.\n";

		cout << "Enter the name of the coach to display: ";
		getline(cin, coachName);
	}
}

void displayList(List<NFL_Coaches>& n)
{
	NFL_Coaches nfl_coaches;

	double AvgAge;
	double TotalAge = 0;
	double AvgYrs;
	double TotalYrs = 0;
	double NumOfYrs = 0;
	string coachEXP;
	double NumOfPer = 0;
	string coachPER;


	for (int i = 0; i < n.getNumber(); i++)
	{
		nfl_coaches = n.getNext();

		cout << setw(20) << left << nfl_coaches.teamName << '\t'
			<< setw(20) << left << nfl_coaches.coachName << '\t'
			<< setw(4) << left << nfl_coaches.numOfWins << '\t'
			<< setw(4) << left << nfl_coaches.numOfLosses << '\t'
			<< setw(4) << left << nfl_coaches.numOfTies << '\t'
			<< setw(4) << left << nfl_coaches.coachBirthYr << '\t'
			<< setw(4) << left << nfl_coaches.YrsOfExp << '\t'
			<< setw(4) << left << nfl_coaches.coachAge << '\t'
			<< fixed << setprecision(2) << setw(4) << left 
			<< nfl_coaches.percentOfWins << endl;

		if (nfl_coaches.YrsOfExp > NumOfYrs)
		{
			NumOfYrs = nfl_coaches.YrsOfExp;
			coachEXP = nfl_coaches.coachName;
		}

		if (nfl_coaches.percentOfWins > NumOfPer)
		{
			NumOfPer = nfl_coaches.percentOfWins;
			coachPER = nfl_coaches.coachName;
		}

		TotalAge += nfl_coaches.coachAge;
		TotalYrs += nfl_coaches.YrsOfExp;
	}

	AvgAge = (TotalAge / n.getNumber());
	AvgYrs = (TotalYrs / n.getNumber());

	cout << "Average coach age: " << AvgAge << endl;
	cout << "Average years of experience: " << AvgYrs << endl;
	cout << "Coach with the most experience: " << coachEXP << endl;
	cout << "Coach with the most wins: " << coachPER << endl;

}
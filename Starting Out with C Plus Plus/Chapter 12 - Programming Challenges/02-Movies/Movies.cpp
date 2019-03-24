// This program is a modified version of the previous program with addition functions.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "Movies.h"
using namespace std;

// Default Constructor
Collection::Collection()
{
	movCapacity = 25;
	ptrMovie = new Movie[movCapacity];
	numOfMovies = 0;
	nextIndex = 0;
}

// Constructor
Collection::Collection(int cap)
{
	movCapacity = cap;
	ptrMovie = new Movie[movCapacity];
	numOfMovies = 0;
	nextIndex = 0;
}

// Destructor
Collection::~Collection()
{
	delete[]ptrMovie;
}

// Loads data from file
bool Collection::load(fstream &file, Movie &m)
{
	bool found = true;
	file.open("Movies.csv", ios::in | ios::out | ios::app);

	if (file.fail())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < numOfMovies; i++)
		{
			file >> m.MPAC;
			getline(file, m.title, ',');
			file >> m.yearReleased;
			file >> m.runTime;
		}
		return true;
	}
}

// Searches for movie's MPAC
bool Collection::find(Movie &m)
{
	bool found = false;

	for (int i = 0; i < numOfMovies; i++)
	{
		if (m.MPAC == ptrMovie[i].MPAC)
		{
			m = ptrMovie[i];
			found = true;
		}
	}
	return found;
}

// Movie index
Movie Collection::getNext()
{
	if (nextIndex >= numOfMovies)
		nextIndex = 0;
	return ptrMovie[nextIndex++];
}

// Purchase a movie not already owned
bool Collection::buy(Movie m)
{
	bool found;
	found = find(m);

	if (!found)
	{
		ptrMovie[nextIndex++] = m;
		numOfMovies++;
	}
	return found;
}

// Sell a movie from the collection
bool Collection::sell(Movie m)
{
	bool found = false;
	int index;

	for (int i = 0; i < numOfMovies; i++)
	{
		if (m.MPAC == ptrMovie[i].MPAC)
		{
			found = true;
			index = i;
		}
	}

	if (!found)
		return found;

	Movie *newPtr = new Movie[movCapacity];
	for (int k = 0, j = 0; k < numOfMovies; k++)
	{
		if (k == index)
			continue;
		else
		{
			newPtr[j] = ptrMovie[k];
			j++;
		}
	}
	delete[] ptrMovie;
	ptrMovie = newPtr;
	numOfMovies--;
	nextIndex--;

	return found;
}

// Total number of movies
int Collection::getNumOfMovies()
{
	return numOfMovies;
}
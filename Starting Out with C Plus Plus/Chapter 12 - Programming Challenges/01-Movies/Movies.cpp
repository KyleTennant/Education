// This program demostrates the use of a header file with a structure, class,
// and constructor to purchase movies and find out if they are already owned.
#include <iostream>
#include <string>
#include "Movies.h"
using namespace std;

// Default Constructor
Collection::Collection()
{
	movCapacity = 20;
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

// Total number of movies
int Collection::getNumOfMovies()
{
	return numOfMovies;
}
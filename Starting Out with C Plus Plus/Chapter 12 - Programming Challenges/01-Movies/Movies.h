#include <iostream>
#include <string>
#ifndef MOVIES_H
#define MOVIES_H
using namespace std;

struct Movie						// Structure declaration
{
	int MPAC;						// Motion Picture Association Code
	string title;					// Movie title
	int yearReleased;				// Movie release date
	int runTime;					// Movie run time
};

class Collection					// Class declaration
{
	private:
		Movie *ptrMovie;			// Pointer to array of movies
		int movCapacity;			// Number of elements in movie array
		int numOfMovies;			// Contains the actual number of movies
		int nextIndex;				// Points to next movie in collection
	public:
		Collection();				// Default constructor
		Collection(int);			// Constructor
		~Collection();				// Destructor
		bool find(Movie&);			// Function that finds a movie requested
		Movie getNext();			// Function that returns the pointed movie
		bool buy(Movie);			// Function that includes a new movie
		int getNumOfMovies();		// Function that returns number of movies
};
#endif
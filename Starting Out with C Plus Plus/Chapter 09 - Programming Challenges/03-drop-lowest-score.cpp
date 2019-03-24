// This program is a modified version of the previous program that
// drops the lowest test score
#include <iostream>
#include <iomanip>
using namespace std;

void selectionSort(int *, int);
double calculateAvg(int *, int);

int main()
{
	// Variable holding number of test scores
	int NumOfTests;

	// Determine size of the array
	cout << "Enter the number of tests: ";
	cin >> NumOfTests;
	cout << " " << endl;

	// Variable holding test scores
	int *score;
	score = new int[NumOfTests];

	// Prompt user to enter test scores
	for (int i = 0; i < NumOfTests; i++)
	{
		cout << "Enter score for test " << i + 1 << ": ";
		cin >> score[i];
	}

	// Sorting the tests and their scores
	selectionSort(score, NumOfTests);

	// Displaying results in ascending order
	cout << " " << endl;
	cout << "Scores in ascending order:" << endl;
	for (int i = 0; i < NumOfTests; i++)
	{
		cout << score[i] << endl;
	}

	// Calculating average
	double average = calculateAvg(score, NumOfTests);

	// Displaying average
	cout << " " << endl;
	cout << "Test score average with lowest score dropped: " << average << endl;
	cout << " " << endl;

	return 0;
}

// Selection Sort function
void selectionSort(int *score, int size)
{
	int startScan, minIndex;
	int minValue;

	for (startScan = 0; startScan<(size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = score[startScan];

		for (int index = startScan + 1; index<size; index++)
		{
			if (score[index]<minValue)
			{
				minValue = score[index];
				minIndex = index;
			}
		}
		score[minIndex] = score[startScan];
		score[startScan] = minValue;
	}

}

// Calculating the average test score function
double calculateAvg(int * score, int size)
{
	double sum = 0.0, avg;
	for (int i = 1; i<size; i++)
	{
		sum += score[i];
	}
	return avg = sum / (size - 1);
}
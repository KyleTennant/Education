// This program calculates the distance a car can travel on one tank of gas
#include <iostream>
using namespace std;

int main()
{
	double gallons, mpgTown, mpgHighway, distanceTown, distanceHighway;

	gallons = 20;
	mpgTown = 23.5;
	mpgHighway = 28.9;
	distanceTown = gallons * mpgTown;
	distanceHighway = gallons * mpgHighway;

	cout << "The distance the car can travel on a tank of gas when driven in town is " << distanceTown << endl;
	cout << "The distance the car can travel on a tank of gas when driven on the highway is " << distanceHighway << endl;

	return 0;
}
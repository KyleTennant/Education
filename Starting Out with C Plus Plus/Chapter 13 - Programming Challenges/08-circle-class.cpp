// This program demostrates the purpose of a class
#include <iostream>
using namespace std;

// Class for the circle
class Circle
{
	private:
		double radius;
		double pi;

	public:
		// Default Constructor
		Circle()
		{
			// Member variables
			radius = 0.0;
			pi = 3.14159;
		}

		// Constructor accepting the radius as an argument
		Circle(double r)
		{
			radius = r;
		}

		// A mutator function for the radius
		void setRadius(double r)
		{
			radius = r;
		}

		// An accessor function for the radius
		double getRadius()
		{
			return radius;
		}

		// Returns the area of the circle
		double getArea()
		{
			return pi * radius * radius;
		}

		// Returns the diamter of the circle
		double getDiameter()
		{
			return radius * 2;
		}

		// Returns the circumference of the circle
		double getCircumference()
		{
			return 2 * pi * radius;
		}
};

int main()
{
	Circle c;			// Class object
	double r;			// Variable for radius

	// Prompt user to enter the radius
	cout << "Enter the radius of the circle ";
	cin >> r;

	// Function to calculate results
	c.setRadius(r);

	// Display the results
	cout << "Area of the circle: " << c.getArea() << endl;
	cout << "Diameter of the circle: " << c.getDiameter() << endl;
	cout << "Circumferences of the circle: " << c.getCircumference() << endl;
	
	return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Company
{
	string div;
	int qtr;
	double sales;
};

int main()
{
	Company data;

	double totalQtr[4] = { 0 };
	double totalDiv[4] = { 0 };
	double totalSales = 0;
	int highest = 0;
	int lowest = 0;

	string divName[4] = { "North", "South", "East", "West" };

	ifstream file;
	file.open("sales.csv");

	if (file.fail())
	{
		cout << "File did not open." << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < 16; i++)
		{
			getline(file, data.div, ',');
			file >> data.qtr;
			file.ignore();
			file >> data.sales;
			file.ignore();

			totalSales += data.sales;
			totalQtr[data.qtr - 1] += data.sales;

			for (int x = 0; x < 4; x++)
			{
				if (data.div.compare(divName[x]) == 0)
				{
					totalDiv[x] += data.sales;
					
				}
			}
		}
	}

	file.close();

	for (int i = 0; i < 4; i++)
	{
		if (totalQtr[i] > totalQtr[highest])
			highest = i;
	}

	for (int i = 0; i < 4; i++)
	{
		if (totalQtr[i] < totalQtr[lowest])
			lowest = i;
	}

	cout << setprecision(2) << fixed << showpoint;
	cout << "-------------------" << endl;
	cout << "  Quarterly Sales  " << endl;
	cout << "-------------------" << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << "   " << i + 1 << " $" << totalQtr[i] << endl;
	}

	cout << "-------------------" << endl;
	cout << "   Yearly Sales    " << endl;
	cout << "-------------------" << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << "  Division: " << divName[i] << endl;
		cout << "  Total $" << totalDiv[i] << endl;
		cout << "  Average $" << (totalDiv[i] / 4) << endl;
		cout << " " << endl;
	}

	cout << "-----------------------------------" << endl;
	cout << " Total Corporate Sales: $" << totalSales << endl;
	cout << " " << endl;
	cout << " Highest Quarter: " << highest + 1 << endl;
	cout << " " << endl;
	cout << " Lowest Quarter: " << lowest + 1 << endl;
	cout << "-----------------------------------" << endl;
	cout << " " << endl;

	return 0;
}
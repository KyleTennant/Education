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

			cout << data.div << " " << data.qtr << " " << data.sales << " " << endl;
		}
	}

	file.close();

	return 0;
}
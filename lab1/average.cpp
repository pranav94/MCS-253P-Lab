#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printAverage(double sum, int count)
{
        if (count == 0) {
                cout << "The average is 0" << endl;
                return;
        }
        cout << "The average is: " << sum/count << endl;
}

void readFile(string fileName)
{
	double sum = 0;
	double count = 0;
	double currentNumber = 0;
	ifstream inputFile(fileName.c_str());
	if (inputFile.good())
	{
		while (inputFile >> currentNumber)
		{
			sum += currentNumber;
			count += 1;
		}
	} else
	{
		cout << "File does not exist" << endl;
	}
	inputFile.close();
	printAverage(sum, count);
}

int main()
{
	string fileName;
	cout << "Enter the name of the input file:" << endl;
	getline (cin, fileName);
	readFile(fileName);
	return 0;
}

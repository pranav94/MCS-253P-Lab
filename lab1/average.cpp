#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void readFile(string fileName, vector<double> &numbers)
{
	ifstream inputFile(fileName.c_str());
	if (inputFile.good())
	{
		double currentNumber = 0.0;
		while (inputFile >> currentNumber)
		{
			numbers.push_back(currentNumber);
		}
	} else
	{
		cout << "File does not exist" << endl;
	}
	inputFile.close();
}

void printAverage(vector<double> &numbers)
{
	double sum = 0.0;
	if (numbers.size() == 0) {
		cout << "The average is 0" << endl;
		return;
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		sum += numbers[i];	
	}
	cout << "The average is: " << sum/numbers.size() << endl;
}

int main()
{
	string fileName;
	vector<double> numbers;
	cout << "Enter the name of the input file:" << endl;
	getline (cin, fileName);
	readFile(fileName, numbers);
	printAverage(numbers);
	return 0;
}

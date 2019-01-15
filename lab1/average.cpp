#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void printAverage(ifstream &inputFile)
{
	double sum = 0.0;
	int count = 0;
	double currentNumber = 0.0;
	while (inputFile >> currentNumber)
	{
		sum += currentNumber;
		count++;
	}
	cout << "The average is: " << sum / (count == 0 ? 1 : count) << endl;
}

void readFile(char *fileName)
{
	ifstream inputFile(fileName);
	if (inputFile.good())
		printAverage(inputFile);
	else
		cout << "File does not exist" << endl;

	inputFile.close();
}

int main(int argc, char **argv)
{
	char fileName[] = "standardTestInput.txt";
	if (argc == 2)
		strcpy(fileName, argv[1]);

	readFile(fileName);
	return 0;
}

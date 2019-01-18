#include <iostream>
#include <stdlib.h>
using namespace std;
#define STRMAX 100

int printNewLine(int parsing)
{
	if(parsing == 1)
		cout << endl;
	return 0;
}
void printTokens(char *command)
{
	int is_parsing_command = 0;
	for (unsigned int i = 0; i < strlen(command); i++)
	{
		switch (command[i])
		{
			case '&':
			case '>':
			case '<':
			case '|':
				is_parsing_command = printNewLine(is_parsing_command);
				cout << command[i] << endl;
				break;
			case '\n':
			case '\t':
			case ' ':
				is_parsing_command = printNewLine(is_parsing_command);
				break;
			default:
				cout << command[i];
				is_parsing_command = 1;
				break;
		}
	}
	printNewLine(is_parsing_command);
}

void readLine()
{
	char command[STRMAX];
	cin.getline(command, STRMAX);
	printTokens(command);
}

int main()
{
	for (;;)
		readLine();
	return 0;
}

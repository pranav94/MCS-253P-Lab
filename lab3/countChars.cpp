#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define STRMAX 1000
#define NEWLINE 10
#define TAB 9

int counts[128] = {0};

void printChar(int i)
{
    cout << '\'';
    switch (i)
    {
        case NEWLINE:
            cout << "\\n";
            break;
        case TAB:
            cout << "\\t";
            break;
        default:
            cout << (char) i;
            break;
    }
    cout << "' " << counts[i] << endl;
}

void printCounts()
{
    int other = 0, whitespace = 0;
    for (int i = 32; i <= 126; i++)
    {
        whitespace += isspace((char)i) ? counts[i] : 0;
        if (counts[i] > 0)
            printChar(i);
    }
    for (int i = 31; i >= 0; i--)
    {
        if(isspace((char)i))
            whitespace += counts[i];
        else
            other += counts[i];
    }
    cout << "Whitespace characters: " << whitespace << endl;
    cout << "Other characters: " << other << endl;
}

void countChars(char *str)
{
    counts[NEWLINE]++;
    for (; *str; str++)
        counts[(int)*str]++;
}

void readLine()
{
    char str[STRMAX];
    cin.getline(str, STRMAX);
    if (strlen(str) > 1)
        countChars(str);
}

int main()
{
    for (; !cin.eof();)
        readLine();
    printCounts();
    return 0;
}
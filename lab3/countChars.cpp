#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define STRMAX 100
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
    int total = 0, whitespace = 0;
    for (int i = 127; i >= 0; i--)
    {
        total += counts[i];
        whitespace += isspace((char)i) ? counts[i] : 0;
        if (counts[i] > 0)
            printChar(i);
    }
    cout << "Whitespace characters: " << whitespace << endl;
    cout << "Other characters: " << total - whitespace << endl;
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
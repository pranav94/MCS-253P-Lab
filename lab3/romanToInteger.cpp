#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define STRMAX 500

int getValue(char roman)
{
    switch (roman)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int getInteger(char *s)
{
    int op = 0;
    while (*s)
        if (*s + 1 && getValue(*s) < getValue(*s + 1))
        {
            op += getValue(*s + 1) - getValue(*s);
            s += 2;
        }
        else
            op += getValue(*s++);
    return op;
}

void readLine()
{
    char roman[STRMAX];
    cin.getline(roman, STRMAX);
    if (strlen(roman) > 1)
        cout << roman << " => " << getInteger(roman) << endl;
}

int main()
{
    for (;;)
        readLine();
    return 0;
}
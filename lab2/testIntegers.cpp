#include <iostream>
#include <stdlib.h>
using namespace std;
#define STRMAX 100

int parseDigits(char *s, unsigned int i)
{
    int result = 0;
    for (; i < strlen(s); i++)
        result = result * 10 + (s[i] - '0');
    return result;
}

int atoi(char *s)
{
    int sign = 1;
    unsigned int i = 0;
    if (s[0] == '-' || s[0] == '+')
        i++;
    if (s[0] == '-')
        sign = -1;

    return parseDigits(s, i) * sign;
}

int parseNumber(int number, char *s, int i)
{
    while (number != 0)
    {
        char digit = (number % 10) + '0';
        number = number / 10;
        s[i++] = digit;
    }
    return i-1;
}

int parseSign(int number, char *s)
{
    s[0] = number < 0 ? '-' : '0';
    if (number <= 0)
        return 1;
    return 0;
}

void reverseString(char *s, int i, int j)
{
    while (i < j)
    {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

char *itoa(int number, char *s)
{
    int i = parseSign(number, s);
    int j = parseNumber(abs(number), s, i);
    reverseString(s, i, j);
    s[j+1] = '\0';
    return s;
}

void validate(char *s1, char *s2)
{
    if (strcmp(s1, s2) != 0)
        cout << "Error! The converted number (" << s1 << ") is not equal to the initial number! (" << s2 << ")" << endl;
    else
        cout << "Number (" << s1 << ") was converted to int and back to str successfully!" << endl;
}

void parseLine(char *s)
{
    int number = atoi(s);
    char result_s[STRMAX];
    itoa(number, result_s);
    validate(result_s, s);
}

void readLine()
{
    char s[STRMAX];
    cin.getline(s, STRMAX);
    parseLine(s);
}

int main()
{
    while (!cin.eof())
        readLine();
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void tokenize(vector<int> &input, int number)
{
    while (number != 0)
    {
        input.push_back(number % 10);
        number = number / 10;
    }
    reverse(input.begin(), input.end());
}

void printNumber(vector<int> &input)
{
    for (int &i : input)
        cout << i;
    cout << endl;
}

int findBegin(vector<int> &input)
{
    int i = input.size() - 2;
    while (i >= 0 && input[i] >= input[i + 1])
        i--;
    return i;
}

int findEnd(vector<int> &input, int i)
{
    int j = input.size() - 1;
    while (input[j] <= input[i])
        j--;
    return j;
}

void nextPermutation(vector<int> &input)
{
    int i = findBegin(input);
    if (i < 0)
        reverse(input.begin(), input.end());
    else
    {
        int j = findEnd(input, i);
        swap(input[i], input[j]);
        reverse(input.begin() + i + 1, input.end());
    }
    printNumber(input);
    return;
}

int main()
{
    int number;
    while (!cin.eof())
    {
        cin >> number;
        vector<int> input;
        cout << number << " ==> ";
        tokenize(input, number);
        nextPermutation(input);
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void segregateColors(vector<char> &colors)
{
    int left = 0;
    for (int i = 0; i < (int)colors.size(); i++)
        if (colors[i] == 'R')
            swap(colors[i], colors[left++]);

    for (int i = left + 1; i < (int)colors.size(); i++)
        if (colors[i] == 'G')
            swap(colors[i], colors[left++]);
}

void printColors(vector<char> &colors)
{
    for (char &color : colors)
        cout << color << " ";
    cout << endl;
}

int main()
{
    vector<char> colors{'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    segregateColors(colors);
    printColors(colors);
    return 0;
}
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define STRMAX 1000

int getScore(char a, char b)
{
    return a == b ? 2 : -1;
}

void findLocalAlignment(char *s1, char *s2, int **dp)
{
    int n = strlen(s1), m = strlen(s2);
    for (int i = 0; i <= n; i++)
        dp[i][0] = dp[0][i] = -i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int match_score = getScore(s1[i - 1], s2[j - 1]);
            int gap_score = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1);
            dp[i][j] = max(dp[i - 1][j - 1] + match_score, gap_score);
        }
}

void printAlignment(char *s1, char *s2, int **dp)
{
    string o1, o2;
    int n = strlen(s1), m = strlen(s2);
    int i = n, j = m;
    while (i != 0 || j != 0)
    {
        if (i == 0)
        {
            o1 += '-';
            o2 += s2[j - 1];
            j--;
        }
        else if (j == 0)
        {
            o1 += s1[i - 1];
            o2 += '-';
            i--;
        }
        else
        {
            int score = getScore(s1[i - 1], s2[j - 1]);
            if (dp[i][j] == dp[i - 1][j - 1] + score)
            {
                o1 += s1[i - 1];
                o2 += s2[j - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                o1 += s1[i - 1];
                o2 += '-';
                i--;
            }
            else
            {
                o1 += '-';
                o2 += s2[j - 1];
                j--;
            }
        }
    }
    reverse(o1.begin(), o1.end());
    reverse(o2.begin(), o2.end());
    cout << "The optimal local alighnments are:\nS1: " << o1 << endl;
    cout << "S2: " << o2 << endl;
}

void initializeVariables(char *s1, char *s2)
{
    cout << "Enter S1: " << endl;
    cin.getline(s1, STRMAX);
    cout << "Enter S2: " << endl;
    cin.getline(s2, STRMAX);
}

int main()
{
    char str1[STRMAX], str2[STRMAX];
    int **dp;
    dp = new int *[STRMAX + 1];
    for (int i = 0; i < STRMAX + 1; i++)
        dp[i] = new int[STRMAX + 1];
    initializeVariables(str1, str2);
    findLocalAlignment(str1, str2, dp);
    printAlignment(str1, str2, dp);
    return 0;
}
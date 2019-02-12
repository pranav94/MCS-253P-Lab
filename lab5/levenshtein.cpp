#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
#define STRMAX 1000

void initializeVariables(string &s1, string &s2, vector<vector<int>> &dp)
{
    cout << "Enter S1: " << endl;
    getline(cin, s1);
    cout << "Enter S2: " << endl;
    getline(cin, s2);
    dp.resize(s1.length() + 1);
    for (auto &row_vec : dp)
        row_vec.resize(s2.length() + 1);
}

int getDistance(string s1, string s2, vector<vector<int>> &dp)
{
    dp[0][0] = 0;
    int n = s1.length(), m = s2.length();
    for (int i = 0, j = 1; j <= m; j++)
        dp[i][j] = j;

    for (int i = 1, j = 0; i <= n; i++)
        dp[i][j] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});

    return dp[n][m];
}

int main()
{
    string s1, s2;
    vector<vector<int>> dp;
    initializeVariables(s1, s2, dp);
    int distance = getDistance(s1, s2, dp);
    cout << "The Levenshtein distance for the strings is: " << distance << endl;
    return 0;
}
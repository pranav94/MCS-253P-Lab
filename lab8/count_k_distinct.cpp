#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<int, int> p;
typedef unordered_map<char, int> map;

void printString(string s, p longestString)
{
    for (int m = longestString.first; m <= longestString.second; m++)
        cout << s[m];
    cout << endl;
}

void addToSeen(map &seen, char c)
{
    if (seen.find(c) != seen.end())
        seen[c]++;
    else
        seen[c] = 1;
}

void updateLongestString(p &longestString, int j, int i)
{
    if ((longestString.second - longestString.first) < (i - j))
        longestString = make_pair(j, i);
}

void removeFromSeen(map &seen, char c)
{
    if (seen[c] == 1)
        seen.erase(c);
    else
        seen[c]--;
}

void longestKString(string s, int k)
{
    map seen;
    p longestString = make_pair(0, 0);
    int left = 0, right = 0;

    for (right = 0; right < (int)s.length(); right++)
    {
        addToSeen(seen, s[right]);
        if ((int)seen.size() <= k)
            updateLongestString(longestString, left, right);
        for (; (int)seen.size() > k; left++)
            removeFromSeen(seen, s[left]);
    }
    printString(s, longestString);
}

void readTest()
{
    string s;
    int k;
    cin >> s;
    cin >> k;
    longestKString(s, k);
}

int main()
{
    int T;
    cin >> T; // Number of test cases

    for (int i = 0; i < T; i++)
        readTest();

    return 0;
}
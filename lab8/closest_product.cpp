#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> p;

int getNegativeCount(vector<int> arr)
{
    int neg = 0;
    for (auto &v : arr)
    {
        if (v >= 0)
            return neg;
        neg++;
    }
    return neg;
}

p findClosestPair(vector<int> arr, int left, int right, int product, bool pos)
{
    p result = make_pair(left, right - 1);
    while (left < right)
    {
        int temp = arr[left] * arr[right];
        if (abs(arr[result.first] * arr[result.second] - product) < abs(temp - product))
            result = make_pair(left, right);
        if (temp > product)
            pos ? right-- : left++;
        else if (temp < product)
            pos ? left++ : right--;
        else
            return make_pair(left, right);
    }
    return result;
}

p findPosPair(vector<int> arr, int index, int product)
{
    int left = index;
    int right = arr.size() - 1;
    return findClosestPair(arr, left, right, product, true);
}

p findNegPair(vector<int> arr, int index, int product)
{
    int left = 0;
    int right = index;
    return findClosestPair(arr, left, right, product, false);
}

p getSmallestPair(vector<int> arr, p p1, p p2, int prod)
{
    if (p1.first == p1.second)
        return p2;
    if (p2.first == p2.second)
        return p1;
    int v1 = arr[p1.first] * arr[p1.second];
    int v2 = arr[p2.first] * arr[p2.second];
    if (abs(v1 - prod) <= abs(v2 - prod))
        return p1;
    return p2;
}

p getClosestPair(vector<int> &arr, int prod)
{
    sort(arr.begin(), arr.end());
    int neg = getNegativeCount(arr);

    if (arr.size() - neg == 1 && neg == 1)
        return make_pair(0, 1);
    if (arr.size() - neg == 0)
        return findNegPair(arr, neg, prod);
    if (neg == 0)
        return findPosPair(arr, neg, prod);

    return getSmallestPair(arr, findNegPair(arr, neg, prod), findPosPair(arr, neg, prod), prod);
}

int main()
{
    p result;
    vector<int> arr;
    arr = {2, 4, 5, 1, 5, 8};
    result = getClosestPair(arr, 10);
    cout << endl
         << "A: {2, 4, 5, 1, -2, 5, 8}, P: 10" << endl
         << "X1: " << arr[result.first] << "\tX2: " << arr[result.second] << endl;

    arr = {2, 4, 0, 1, 5, 8};
    result = getClosestPair(arr, 0);
    cout << endl
         << "A: {2, 4, 0, 1, 5, 8}, P: 0" << endl
         << "X1: " << arr[result.first] << "\tX2: " << arr[result.second] << endl;

    arr = {-2, -4, 5, 3, 5, 8};
    result = getClosestPair(arr, 8);
    cout << endl
         << "A: {-2, -4, 5, 3, 5, 8}, P: 8" << endl
         << "X1: " << arr[result.first] << "\tX2: " << arr[result.second] << endl;

    arr = {-2, 2};
    result = getClosestPair(arr, 4);
    cout << endl
         << "A: {-2, 2}, P: 4" << endl
         << "X1: " << arr[result.first] << "\tX2: " << arr[result.second] << endl;

    return 0;
}
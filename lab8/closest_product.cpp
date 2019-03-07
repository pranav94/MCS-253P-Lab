#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> p;

int getClosest(vector<int> arr, int val1, int val2, int target)
{
    if (target - arr[val1] >= arr[val2] - target)
        return val2;
    else
        return val1;
}

int binarySearch(vector<int> arr, int i, int n, int target)
{
    if (target <= arr[i])
        return i;
    if (target >= arr[n - 1])
        return n - 1;
    int j = n, mid = i;
    while (i < j)
    {
        mid = (i + j) / 2;

        if (arr[mid] == target)
            return mid;

        if (target < arr[mid])
        {
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr, mid - 1, mid, target);
            j = mid;
        }
        else
        {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr, mid, mid + 1, target);
            i = mid + 1;
        }
    }

    return mid;
}

int findClosestProductIndex(vector<int> arr, int index, int value)
{
    if (value == 0)
        return index == 0 ? index + 1 : index - 1;
    int key = value / arr[index];
    if (index == 0)
        return binarySearch(arr, 1, (int)arr.size(), key);
    if (index == (int)arr.size() - 1)
        return binarySearch(arr, 0, index, key);

    int lindex = binarySearch(arr, 0, index, key);
    int rindex = binarySearch(arr, index + 1, (int)arr.size(), key);

    int prod1 = arr[lindex] * arr[index];
    int prod2 = arr[rindex] * arr[index];

    if (abs(prod1 - value) < abs(prod2 - value))
        return lindex;
    return rindex;
}

p getClosestPair(vector<int> &arr, int prod)
{
    sort(arr.begin(), arr.end());
    p closestPair;
    bool initialized = false;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        int j = findClosestProductIndex(arr, i, prod);
        if (!initialized)
        {
            closestPair = make_pair(i, j);
            initialized = true;
        }
        else
        {
            int prod1 = arr[i] * arr[j];
            int closestProd = arr[closestPair.first] * arr[closestPair.second];
            if (abs(prod1 - prod) < abs(closestProd - prod))
                closestPair = make_pair(i, j);
        }
    }
    return closestPair;
}

int main()
{
    p result;
    vector<int> arr;
    arr = {2, 4, 5, 1, 5, 8};
    result = getClosestPair(arr, 10);
    cout << endl
         << "A: {2, 4, 5, 1, 5, 8}, P: 10" << endl
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

    arr = {2, -4, 5};
    result = getClosestPair(arr, 9);
    cout << endl
         << "A: {2, -4, 5}, P: 9" << endl
         << "X1: " << arr[result.first] << "\tX2: " << arr[result.second] << endl;

    arr = {-2, -4, 5};
    result = getClosestPair(arr, 9);
    cout << endl
         << "A: {-2, -4, 5}, P: 9" << endl
         << "X1: " << arr[result.first] << "\tX2: " << arr[result.second] << endl;

    arr = {-1, -8, 1};
    result = getClosestPair(arr, 1);
    cout << endl
         << "A: {-1, -8, 1}, P: 1" << endl
         << "X1: " << arr[result.first] << "\tX2: " << arr[result.second] << endl;

    arr = {-2, 2};
    result = getClosestPair(arr, 4);
    cout << endl
         << "A: {-2, 2}, P: 4" << endl
         << "X1: " << arr[result.first] << "\tX2: " << arr[result.second] << endl;

    return 0;
}
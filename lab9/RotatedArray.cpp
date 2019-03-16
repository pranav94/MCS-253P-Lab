#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr, int key)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[low] < arr[mid])
        {
            if (arr[low] <= key && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (key > arr[mid] && arr[high] >= key)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    cout << endl << "arr: {13, 18, 25, 2, 8, 10}\tkey: 8\nIndex found: " << search(vector<int>{13, 18, 25, 2, 8, 10}, 8) << endl;
    cout << endl << "arr: {18, 25, 2, 8, 10, 13}\tkey: 8\nIndex found: " << search(vector<int>{18, 25, 2, 8, 10, 13}, 8) << endl;
    cout << endl << "arr: {18, 25, 2, 8, 10, 13}\tkey: 13\nIndex found: " << search(vector<int>{18, 25, 2, 8, 10, 13}, 13) << endl;
    cout << endl << "arr: {2, 8, 10, 13, 18, 25}\tkey: 13\nIndex found: " << search(vector<int>{2, 8, 10, 13, 18, 25}, 13) << endl;
    cout << endl << "arr: {13, 18, 25, 2, 8, 10}\tkey: 7\nIndex found: " << search(vector<int>{13, 18, 25, 2, 8, 10}, 7) << endl;
    cout << endl;
    return 0;
}
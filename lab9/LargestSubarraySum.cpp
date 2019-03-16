#include <iostream>
#include <vector>
using namespace std;

int largestSubarraySum(vector<int> arr)
{
    int maxSum = 0, currSum = 0;
    int i = 0, j = 0;
    while (j < (int)arr.size())
    {
        while (currSum < 0 && i < j)
            currSum -= arr[i++];
        currSum += arr[j++];
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main()
{
    cout << "{34, -50, 42, 14, -5, 86}: " << largestSubarraySum(vector<int>{34, -50, 42, 14, -5, 86}) << endl;
    cout << "{-5, -1, -8, -9}: " << largestSubarraySum(vector<int>{-5, -1, -8, -9}) << endl;
    return 0;
}
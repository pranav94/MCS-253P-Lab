#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
    cout << endl;
    for (auto it = v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void productExceptSelf(vector<int> input)
{
    vector<int> output;
    int product = 1;
    for (auto it = input.begin(); it!=input.end(); ++it) {
        output.push_back(product);
        product *= *it;
    }
    int i = input.size()-1;

    product = 1;

    for (auto it = input.end()-1; it!=input.begin()-1; --it) {
        output[i--] *= product;
        product *= *it;
    }
    printVector(output);
}

int main()
{
    vector<int> input{10, 3, 5, 6, 2};
    vector<int> zeros{10, 3, 5, 6, 0, 2};
    vector<int> empty{};
    vector<int> negatives{-12, 25, -20, 45};
    productExceptSelf(input);
    productExceptSelf(zeros);
    productExceptSelf(empty);
    productExceptSelf(negatives);
    return 0;
}


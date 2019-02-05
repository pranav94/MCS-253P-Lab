#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

bool isEven(int i)
{
    return i % 2 == 0;
}

void writeToFile(vector<int> numbers)
{
    ofstream evens_output("even.txt");
    ofstream odds_output("odd.txt");

    copy_if(numbers.begin(), numbers.end(), ostream_iterator<int>(evens_output, " "), [](int i) {
        return isEven(i);
    });
    copy_if(numbers.begin(), numbers.end(), ostream_iterator<int>(odds_output, " "), [](int i) {
        return !isEven(i);
    });
}

void readFile(vector<int> &numbers)
{
    ifstream input("rand_numbers.txt");
    istream_iterator<int> input_it(input);
    istream_iterator<int> eos;
    copy(input_it, eos, back_inserter(numbers));
}

int main()
{
    string line;
    vector<int> numbers;
    readFile(numbers);
    sort(numbers.begin(), numbers.end());
    writeToFile(numbers);

    return 0;
}
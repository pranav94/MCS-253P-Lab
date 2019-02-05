#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
using namespace std;

void readStopWords(set<string> &stopwords)
{
    ifstream input("stopwords.txt");
    copy(istream_iterator<string>(input), istream_iterator<string>(), inserter(stopwords, stopwords.end()));
}

void toLower(string &w)
{
    transform (w.begin(), w.end(), w.begin(), ::tolower);
}

void calculateFrequency(map<string, int> &counts, set<string> stopwords)
{
    ifstream input("sample_doc.txt");
    for_each(istream_iterator<string>(input), istream_iterator<string>(), [&](string w) {
        toLower(w);
        if (stopwords.find(w) == stopwords.end())
            counts[w] = counts.find(w) == counts.end() ? 1 : counts[w] += 1;
    });
}

void writeToFile(map<string, int> &counts)
{
    ofstream output("frequency.txt");
    transform(counts.begin(), counts.end(), ostream_iterator<string>(output, "\n"), [&](pair<string, int> p) {
        return p.first + " " + to_string(p.second);
    });
}

int main()
{
    set<string> stopwords;
    map<string, int> counts;
    readStopWords(stopwords);
    calculateFrequency(counts, stopwords);
    writeToFile(counts);
    return 0;
}
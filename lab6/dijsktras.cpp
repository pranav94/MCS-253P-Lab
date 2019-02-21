#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> p;

vector<int> *G;
vector<int> distances;

int Dijkstra(int N)
{
    priority_queue<p, vector<p>, greater<p>> Q;
    distances.assign(N + 1, INT_MAX);
    distances[1] = 0;
    Q.push({0, 1});
    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        for (auto &v : G[u])
            if (distances[v] > distances[u] + 1)
            {
                distances[v] = distances[u] + 1;
                Q.push({distances[v], v});
            }
    }
    return distances[N];
}

void buildGraph(int N)
{
    G = new vector<int>[N + 1];
    for (int i = 1; i <= N; i++)
    {
        if (i + 1 <= N)
            G[i].push_back(i + 1);
        if (3 * i <= N)
            G[i].push_back(3 * i);
    }
}

void printShortestdistancesance(int N)
{
    buildGraph(N);
    cout << Dijkstra(N) << endl;
}

void readTests(vector<int> &tests)
{
    int N;
    cout << "N: ";
    cin >> N;
    tests.push_back(N);
}

int main()
{
    int T;
    vector<int> tests;
    cout << "Enter number of test cases: ";
    cin >> T;

    for (int i = 0; i < T; i++)
        readTests(tests);

    for (auto &n : tests)
        printShortestdistancesance(n);

    return 0;
}
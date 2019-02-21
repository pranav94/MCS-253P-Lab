#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> p;

int Dijkstra(vector<vector<int>> &G, int N)
{
    priority_queue<p, vector<p>, greater<p>> Q;
    vector<int> distances;
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

void buildGraph(vector<vector<int>> &G, int N)
{
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
    vector<vector<int>> G(N+1);
    buildGraph(G, N);
    cout << Dijkstra(G, N) << endl;
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
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> p;

vector<p> *G;
vector<int> distances;

int findMSTWeight(int N)
{
    priority_queue<p, vector<p>, greater<p>> Q;
    distances.assign(N + 1, INT_MAX);
    distances[1] = 0;
    vector<int> weights(N, 0);
    vector<bool> visited(N, false);

    Q.push(make_pair(0, 1));

    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        visited[u] = true;

        for (auto &c : G[u])
        {
            int v = c.first;
            int weight = c.second;
            if (visited[v] == false && distances[v] > weight)
            {
                distances[v] = weight;
                Q.push(make_pair(distances[v], v));
                weights[v] = weight;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= N; ++i)
        sum += weights[i];

    return sum;
}

void readTest()
{
    int n, e;
    cin >> n;
    G = new vector<p>[n + 1];
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    cout << findMSTWeight(n) << endl;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
        readTest();

    return 0;
}
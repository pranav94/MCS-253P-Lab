#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

typedef pair<int, int> p;
float max_average;
int max_average_index;

void updateAverage(int sum, int n, int node)
{
    float average = (float)sum / n;
    if (average > max_average)
    {
        max_average = average;
        max_average_index = node;
    }
}

void reset()
{
    max_average = INT_MIN;
    max_average_index = 0;
}

p getMaxAverage(vector<int> tree, int node)
{
    if(node == 0) reset();
    int sum = tree[node], n = 1;
    int lchild = 2 * node + 1, rchild = 2 * node + 2;

    if (lchild < (int)tree.size())
    {
        p ltree = getMaxAverage(tree, lchild);
        sum += ltree.first;
        n += ltree.second;
    }

    if (rchild < (int)tree.size())
    {
        p rtree = getMaxAverage(tree, rchild);
        sum += rtree.first;
        n += rtree.second;
    }

    updateAverage(sum, n, node);

    return make_pair(sum, n);
}

int main()
{
    vector<int> tree;

    tree = {18, 15, 30, 40, 50, 100, 40, 8, 7, 9};
    getMaxAverage(tree, 0);
    cout << "Max average node index: " << max_average_index << " Max average: " << max_average << endl;

    tree = {18, 15, 30, 40, 50, 0, 0, 8, 7, 9};
    getMaxAverage(tree, 0);
    cout << "Max average node index: " << max_average_index << " Max average: " << max_average << endl;

    tree = {18, 15, 60, 40, 50, 50, 50};
    getMaxAverage(tree, 0);
    cout << "Max average node index: " << max_average_index << " Max average: " << max_average << endl;

    tree = {18, 15, 60, 40, 50, 50, 50};
    getMaxAverage(tree, 0);
    cout << "Max average node index: " << max_average_index << " Max average: " << max_average << endl;

    return 0;
}
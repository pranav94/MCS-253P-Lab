#include <iostream>
#include <vector>
using namespace std;

class SpiralMatrix
{
  private:
    int m = 0, n = 0;
    vector<vector<int>> matrix = vector<vector<int>>();
    void right(int &i, int &j, int &c, int offset, int limit);
    void down(int &i, int &j, int &c, int offset, int limit);
    void left(int &i, int &j, int &c, int offset, int limit);
    void up(int &i, int &j, int &c, int offset, int limit);
    void printMatrix();

  public:
    SpiralMatrix(int m, int n);
    void printSpiral();
};

SpiralMatrix::SpiralMatrix(int m, int n)
{
    this->m = m;
    this->n = n;
    for (int i = 0; i < m; i++)
    {
        matrix.push_back(vector<int>());
        for (int j = 0; j < n; j++)
            matrix[i].push_back(0);
    }
}

void SpiralMatrix::right(int &i, int &j, int &c, int offset, int limit)
{
    while (j < n - offset && c <= limit)
    {
        matrix[i][j] = c++;
        j++;
    }
    j--;
    i++;
}

void SpiralMatrix::down(int &i, int &j, int &c, int offset, int limit)
{
    while (i < m - offset && c <= limit)
    {
        matrix[i][j] = c++;
        i++;
    }
    i--;
    j--;
}

void SpiralMatrix::left(int &i, int &j, int &c, int offset, int limit)
{
    while (j >= offset && c <= limit)
    {
        matrix[i][j] = c++;
        j--;
    }
    i--;
    j++;
}

void SpiralMatrix::up(int &i, int &j, int &c, int offset, int limit)
{
    while (i >= offset + 1 && c <= limit)
    {
        matrix[i][j] = c++;
        i--;
    }
}

void SpiralMatrix::printMatrix()
{
    for (vector<int> &row : matrix)
    {
        for (int &v : row)
            cout << v << "\t";
        cout << endl;
    }
}

void SpiralMatrix::printSpiral()
{
    int offset = 0, limit = m * n;
    int c = 1;
    while (c <= limit)
    {
        int i = offset, j = offset;
        right(i, j, c, offset, limit);
        down(i, j, c, offset, limit);
        left(i, j, c, offset, limit);
        up(i, j, c, offset, limit);
        offset++;
    }
    printMatrix();
}

int main()
{
    while (!cin.eof())
    {
        int m, n;
        cin >> m;
        cin >> n;
        cout << m << "x" << n << endl;
        SpiralMatrix s = SpiralMatrix(m, n);
        s.printSpiral();
        cout << endl << "-----" << endl;
    }
    return 0;
}

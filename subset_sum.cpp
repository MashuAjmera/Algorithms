#include <iostream>
using namespace std;

bool isSafe(int add, int level, int w[], int m, int n)
{
    int rem = 0;
    for (int i = level; i < n; i++)
        rem += w[i];
    return (add + w[level] <= m || add + rem > m) ? true : false;
}

bool subsetSum(int level, int n, int w[], int m, bool x[], int add)
{
    if (add == m)
    {
        cout << " ";
        for (int i = 0; i < n; i++)
            cout << x[i];
        return true;
    }

    bool res = false;
    for (int i = level; i < n; i++)
    {
        if (isSafe(add, i, w, m, n))
        {
            x[i] = true;
            add += w[i];
            res = subsetSum(i + 1, n, w, m, x, add) || res;
            x[i] = false;
            add -= w[i];
        }
    }
    return res;
}

int main()
{
    // int w[] = {5, 10, 12, 13, 15, 18};
    // int m = 30;
    int w[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int m = 53;
    int n = sizeof(w) / sizeof(w[0]);
    bool x[n] = {false};

    cout << "The selected subsets are:";
    if (!subsetSum(0, n, w, m, x, 0))
        cout << "none";
}
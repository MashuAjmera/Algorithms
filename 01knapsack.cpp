#include <iostream>
using namespace std;

int main()
{
    int n = 4, w = 7, i, j;
    int wt[n] = {1, 3, 4, 5};
    int val[n] = {1, 4, 5, 7};
    int DP[n + 1][w + 1];

    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (j < wt[i - 1])
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = max(val[i - 1] + DP[i - 1][j - wt[i - 1]], DP[i - 1][j]);
            cout << DP[i][j] << " ";
        }
        cout << " \n";
    }
    cout << "The selected weights are:";

    for (i = i - 1, j = j - 1; i > 0 && j > 0; i--)
    {
        if (DP[i][j] != DP[i - 1][j])
        {
            cout << " " << wt[i - 1];
            j = j - wt[i - 1];
        }
    }
}
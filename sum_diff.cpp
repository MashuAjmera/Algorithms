#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    // int a[] = {2, 4, 2, 3};
    int a[] = {1, 6, 11, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 0;
    sum = accumulate(a, a + n, sum);
    int ns = sum / 2;
    bool DP[n + 1][ns + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < ns + 1; j++)
        {
            if (j == 0)
                DP[i][j] = true;
            else if (i == 0)
                DP[i][j] = false;
            else if (j < a[i - 1])
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = DP[i - 1][j] || DP[i - 1][j - a[i - 1]];
            cout << DP[i][j] << " ";
        }
        cout << " \n";
    }

    int i = ns;
    while (!DP[n][i])
        i--;
    cout << "The minimum difference possible is: " << sum - 2 * i;
}

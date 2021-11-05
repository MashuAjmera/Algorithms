/* 
Problem: Coin Change Problem
YouTube: https://youtu.be/L27_JpN6Z1Q
Solution Approach: Dynamic Programming
Time Complexity:
Space Complexity: 
Author: Mashu Ajmera
*/

#include <iostream>
using namespace std;

int main()
{
    int n = 4, w = 15, i, j;
    int wt[n] = {2, 3, 5, 10};
    int DP[n + 1][w + 1];

    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < w + 1; j++)
        {
            if (i == 0)
                DP[i][j] = 0;
            else if (j == 0)
                DP[i][j] = 1;
            else if (j < wt[i - 1])
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = DP[i][j - wt[i - 1]] + DP[i - 1][j];
            cout << DP[i][j] << " ";
        }
        cout << " \n";
    }
    cout << "Total number of ways: " << DP[n][w];
}
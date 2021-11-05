/* 
Problem: Weighted Job Scheduling
YouTube: https://youtu.be/UflHuQj6MVA
Solution Approach: Dynamic Programming
Time Complexity:
Space Complexity: 
Author: Mashu Ajmera
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "aaaabbaa";
    int n = s.length();
    bool DP[n][n];
    int max;

    for (int length = 0; length < n; length++)
    {
        for (int i = 0, j = i + length; j < n; i++, j++)
        {
            if ((length == 0) || (length == 1 && s[i] == s[j]) || (length > 1 && s[i] == s[j] && DP[i + 1][j - 1]))
            {
                DP[i][j] = true;
                max = length + 1;
            }
            else
                DP[i][j] = false;
        }
    }

    cout << "The longest palindrome length is: " << max;
}
// Problem: Maximum Subarray Sum
// Approach: Kadane's Algorithm
// YouTube: https://www.youtube.com/watch?v=HCL4_bOd3-4
// Author: Mashu Ajmera

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // int arr[] = {5, -4, -2, 6, -1};
    int arr[] = {-5, 4, 6, -3, 4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = INT_MIN, current = 0;
    for (int i = 0; i < n; i++)
    {
        current += arr[i];
        if (max < current)
            max = current;
        if (current < 0)
            current = 0;
    }
    cout << "The maximum subarray sum is: " << max;
}
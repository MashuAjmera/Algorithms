#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int start[] = {1, 2, 4, 6, 5, 7};
    int end[] = {3, 5, 6, 7, 8, 9};
    int profit[] = {5, 6, 5, 4, 11, 2};
    int size = sizeof(start) / sizeof(start[0]);
    int DP[size];
    copy(profit, profit + size, DP);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < i; j++)
            if (start[i] >= end[j])
                DP[i] = max(DP[i], profit[i] + DP[j]);

    cout << "max profit: " << *max_element(DP, DP + size);
}
/* 
Problem: Travelling Salesman Problem
YouTube: https://youtu.be/hh-uFQ-MGfw
Solution Approach: Dynamic Programming
Time Complexity:
Space Complexity: 
Author: Mashu Ajmera
*/

#include <iostream>
#include <vector>
#include <limits.h>
#define V 4

using namespace std;

int TSP(int s, int i, vector<int> S, int graph[][V])
{
    int n = S.size();
    int min = INT_MAX;
    if (n == 0)
        return graph[i][s];
    for (int j = 0; j < n; j++)
    {
        vector<int> T = S;
        T.erase(T.begin() + j);
        int temp = graph[i][S[j]] + TSP(s, S[j], T, graph);
        if (min > temp)
            min = temp;
    }
    return min;
}

int main()
{
    int s = 0;
    int graph[][V] = {{0, 16, 11, 6}, {8, 0, 13, 16}, {4, 7, 0, 9}, {5, 12, 2, 0}};
    vector<int> S;
    for (int i = 0; i < V; i++)
        if (i != s)
            S.push_back(i);
    cout << "Minimum possible cost of travelling: " << TSP(s, s, S, graph);
}
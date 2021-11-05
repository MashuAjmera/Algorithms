/* 
Problem: Graph Coloring
YouTube: https://youtu.be/052VkKhIaQ4
Solution Approach: Backtracking
Time Complexity:
Space Complexity: 
Author: Mashu Ajmera
*/

#include <iostream>
using namespace std;
#define N 4

bool isSafe(int graph[][N], int colors[], int level)
{
    for (int i = 0; i < level; i++)
    {
        if (graph[level][i] == 1 && colors[level] == colors[i])
            return false;
    }
    return true;
}

bool colorGraph(int graph[][N], int m, int colors[N], int level)
{
    if (level >= N)
    {
        cout << "\nThe colors are:";
        for (int i = 0; i < N; i++)
        {
            cout << " " << colors[i];
        }
        return true;
    }

    bool res = false;
    for (int i = 0; i < m; i++)
    {
        colors[level] = i;
        if (isSafe(graph, colors, level))
        {
            res = colorGraph(graph, m, colors, level + 1) || res;
        }
    }

    return res;
}

int main()
{
    int graph[][N] = {{0, 1, 0, 1},
                      {1, 0, 1, 0},
                      {0, 1, 0, 1},
                      {1, 0, 1, 0}};
    int colors[N];
    int m = 3;
    if (!colorGraph(graph, m, colors, 0))
    {
        cout << "graph cannot be colored using " << m << " colors";
    };
}
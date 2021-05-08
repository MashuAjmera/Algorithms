#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;
#define v 6
// #define v 5

void prim(int s, int g[v][v], int dist[], bool mst[], int edgeto[])
{
    for (int j = s; j < v; j++)
    {
        if (!mst[j] && g[s][j] != 0 && g[s][j] < dist[j])
        {
            dist[j] = g[s][j];
            edgeto[j] = s;
        }
    }
    mst[s] = true;

    int min = INT_MAX, idx = -1;
    for (int i = 0; i < v; i++)
    {
        if (!mst[i] && dist[i] < min)
        {
            idx = i;
            min = dist[i];
        }
    }

    if (idx != -1)
        prim(idx, g, dist, mst, edgeto);

    return;
}

int main()
{
    int g[v][v] = {
        {0, 4, 6, 0, 0, 0},
        {4, 0, 6, 3, 4, 0},
        {6, 6, 0, 1, 8, 0},
        {0, 3, 1, 0, 2, 3},
        {0, 4, 8, 2, 0, 7},
        {0, 0, 0, 3, 7, 0}};

    // int g[v][v] = {{0, 2, 0, 6, 0},
    //                {2, 0, 3, 8, 5},
    //                {0, 3, 0, 0, 7},
    //                {6, 8, 0, 0, 9},
    //                {0, 5, 7, 9, 0}};

    int dist[v], edgeto[v];
    bool mst[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        edgeto[i] = -1;
        mst[i] = false;
        // cout << dist[i] << " " << mst[i] << " " << edgeto[i] << "\n";
    }
    dist[0] = 0, edgeto[0] = -1;

    prim(0, g, dist, mst, edgeto);

    cout << "The MST set is:";
    for (int i = 1; i < v; i++)
    {
        cout << "\n"
             << i << "-" << edgeto[i] << " " << dist[i];
    }
}
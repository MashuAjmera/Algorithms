/* 
Problem: Topological Sort
YouTube: hhttps://youtu.be/qe_pQCh09yU
Solution Approach: 
Time Complexity:
Space Complexity: 
Author: Mashu Ajmera
*/

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void dfs(int i, stack<int> &s, bool visited[])
    {
        visited[i] = true;

        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
            if (!visited[*it])
                dfs(*it, s, visited);

        s.push(i);
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int s, int d) { adj[s].push_back(d); }

    void topologicalSort()
    {
        bool visited[V] = {false};
        stack<int> s;

        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs(i, s, visited);

        cout << "The topological order is:";
        while (!s.empty())
        {
            cout << " " << s.top();
            s.pop();
        }
    }
};

int main()
{
    int V = 6;
    Graph g(V);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topologicalSort();
}
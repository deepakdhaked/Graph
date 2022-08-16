#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v, bool isDir)
{
    if (isDir)
    {
        adj[u].push_back(v);
    }
    else
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void displayGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (auto j : adj[i])
        {
            cout << j << ", ";
        }
        cout << '\n';
    }
}

int main()
{
    int V = 5;

    vector<int> adj[V];
    addEdge(adj, 0, 1, 0);
    addEdge(adj, 0, 4, 0);
    addEdge(adj, 1, 2, 0);
    addEdge(adj, 1, 3, 0);
    addEdge(adj, 1, 4, 0);
    addEdge(adj, 2, 3, 0);
    addEdge(adj, 3, 4, 0);

    displayGraph(adj, V);
}
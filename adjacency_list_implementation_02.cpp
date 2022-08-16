#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void addEdge(unordered_map<int, vector<int>> &adj, int u, int v, bool isDir)
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

void displayGraph(unordered_map<int, vector<int>> &adj)
{
    for (auto i : adj)
    {
        cout << i.first << " -> ";
        for (auto j : i.second)
        {
            cout << j << ", ";
        }
        cout << '\n';
    }
}

int main()
{
    unordered_map<int, vector<int>> adj;

    addEdge(adj, 0, 1, 0);
    addEdge(adj, 0, 4, 0);
    addEdge(adj, 1, 2, 0);
    addEdge(adj, 1, 3, 0);
    addEdge(adj, 1, 4, 0);
    addEdge(adj, 2, 3, 0);
    addEdge(adj, 3, 4, 0);
    displayGraph(adj);
}
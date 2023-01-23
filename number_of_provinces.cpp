#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
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

void numberofProvinces(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &component, int node)
{
    component.push_back(node);
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            numberofProvinces(adj, visited, component, i);
        }
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

    int vertex = adj.size();
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            numberofProvinces(adj, visited, component, i);
            ans.push_back(component);
        }
    }

    cout << "Number of Graph components : " << ans.size() << '\n';
}
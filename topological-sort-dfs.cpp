#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
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

void topological_sort(vector<int> adj[], unordered_map<int, bool> &visited, stack<int> &ans, int src)
{
    visited[src] = true;

    for (auto i : adj[src])
    {
        if (!visited[i])
        {
            topological_sort(adj, visited, ans, i);
        }
    }

    ans.push(src);
}

int main()
{
    int V = 6;

    vector<int> adj[V];
    addEdge(adj, 0, 1, true);
    addEdge(adj, 0, 2, true);
    addEdge(adj, 1, 3, true);
    addEdge(adj, 2, 3, true);
    addEdge(adj, 3, 4, true);
    addEdge(adj, 3, 5, true);
    addEdge(adj, 4, 5, true);

    displayGraph(adj, V);

    unordered_map<int, bool> visited;
    stack<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {

            topological_sort(adj, visited, ans, i);
        }
    }

    while (!ans.empty())
    {
        cout << ans.top() << ", ";
        ans.pop();
    }
}
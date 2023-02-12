#include <iostream>
#include <vector>
#include <unordered_map>
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

bool isCyclicDFS(vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, int src)
{
    visited[src] = true;
    dfsVisited[src] = true;

    for (auto i : adj[src])
    {
        if (!visited[i])
        {
            if (isCyclicDFS(adj, visited, dfsVisited, i))
            {
                return true;
            }
        }
        else if (dfsVisited[i])
        {
            return true;
        }
    }

    dfsVisited[src] = false;
    return false;
}

int main()
{
    int V = 5;

    vector<int> adj[V];
    addEdge(adj, 0, 1, true);
    addEdge(adj, 0, 4, true);
    addEdge(adj, 1, 2, true);
    addEdge(adj, 1, 3, true);
    addEdge(adj, 4, 1, true);
    addEdge(adj, 2, 3, true);
    addEdge(adj, 3, 4, true);

    displayGraph(adj, V);

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    bool ans = false;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            ans = isCyclicDFS(adj, visited, dfsVisited, i);
            if (ans == true)
            {
                break;
            }
        }
    }

    ans ? cout << "Graph is Cyclic" : cout << "Graph is Acyclic";
}
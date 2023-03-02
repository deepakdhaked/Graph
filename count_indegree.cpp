#include <iostream>
#include <vector>
#include <queue>
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

vector<int> getIndegree(vector<int> adj[], int V)
{
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }
    return indegree;
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

    vector<int> indegree;
    indegree = getIndegree(adj, V);

    cout << "Indegree is : ";
    for (auto i : indegree)
    {
        cout << i << ", ";
    }
}
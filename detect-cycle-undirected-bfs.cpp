#include <iostream>
#include <vector>
#include <unordered_map>
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

bool isCyclicBFS(vector<int> adj[], unordered_map<int, bool> &visited, int src)
{
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    parent[src] = -1;
    visited[src] = true;

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            if (visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
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

    unordered_map<int, bool> visited;
    bool ans = false;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            ans = isCyclicBFS(adj, visited, i);
            if (ans == true)
            {
                break;
            }
        }
    }

    ans ? cout << "Graph is Cyclic" : cout << "Graph is Acyclic";
}
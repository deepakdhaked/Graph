#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
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

void bfs(vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int src)
{
    queue<int> q;
    q.push(src);
    parent[src] = -1;
    visited[src] = true;

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
}

void findShortestPath(unordered_map<int, int> &parent, int src, int dst)
{
    vector<int> ans;
    int currentNode = dst;
    ans.push_back(dst);

    while (currentNode != src)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());

    for (auto i : ans)
    {
        cout << i << " -> ";
    }
}

int main()
{
    int V = 9;
    vector<int> adj[V];

    addEdge(adj, 0, 1, 0);
    addEdge(adj, 0, 2, 0);
    addEdge(adj, 0, 3, 0);
    addEdge(adj, 1, 4, 0);
    addEdge(adj, 2, 7, 0);
    addEdge(adj, 3, 5, 0);
    addEdge(adj, 4, 7, 0);
    addEdge(adj, 5, 6, 0);
    addEdge(adj, 6, 7, 0);
    displayGraph(adj, V);

        int src = 0, dst = 7;

    // Do BFS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    bfs(adj, visited, parent, src);

    // find shortest path
    findShortestPath(parent, src, dst);
}
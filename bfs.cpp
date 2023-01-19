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

void bfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();

        ans.push_back(curr);

        for (auto i : adj[curr])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
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
    vector<int> ans;

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adj, visited, ans, i);
        }
    }
    cout << "BFS Traversal : ";
    for (int i : ans)
    {
        cout << i << ' ';
    }
}
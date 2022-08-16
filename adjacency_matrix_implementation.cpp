#include<iostream>
using namespace std;

int main(){
    int V;
    cout << "Enter number of vertices\n";
    cin >> V;

    int adjMat[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    cout << "Enter number of edges\n";

    int edges;
    cin >> edges;

    cout << "Enter the connected edges u following by v\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << adjMat[i][j] << ' ';
        }
        cout << '\n';
    }
}




#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 5

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int min = INT_MAX, u = -1;

        for (int v = 0; v < V; v++)
        {
            if (!mstSet[v] && key[v] < min)
            {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;

    cout << "Minimum Cost Network Connections:\n";
    cout << "Connection\tInstallation Cost\n";

    for (int i = 1; i < V; i++)
    {
        cout << "Server " << parent[i] + 1
             << " - Server " << i + 1
             << "\t" << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "\nTotal Minimum Installation Cost: "
         << totalCost << endl;
}

int main()
{
    int graph[V][V] = 
  {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}

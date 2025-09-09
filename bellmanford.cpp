#include<bits/stdc++.h>
using namespace std;

vector<int> BellmanFord(int n, vector<vector<pair<int, int>>>& adj, int src)
{
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int u=0; u<n; u++)
        {
            if(distance[u] == INT_MAX)
            {
                continue;
            }
            for(auto& edge : adj[u])
            {
                int v = edge.first, w = edge.second;
                if(distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }
    for(int u=0; u<n; u++)
    {
        if(distance[u] == INT_MAX)
        {
            continue;
        }
        for(auto& edge : adj[u])
        {
            int v = edge.first, w = edge.second;
            if(distance[u] + w < distance[v])
            {
                cout << "Negative weight cycle found" << endl;
                return {};
            }
        }
    }
    return distance;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adj(n);
    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int src;
    cin >> src;

    vector<int> result = BellmanFord(n, adj, src);
    if(!result.empty())
    {
        for(int i=0; i<n; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}
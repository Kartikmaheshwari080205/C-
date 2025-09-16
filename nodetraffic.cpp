#include<bits/stdc++.h>
using namespace std;

vector<int> Traffic(int n, vector<vector<int>>& adj)
{
    vector<int> subtreesum(n+1, 0), result(n+1, 0);
    int total = n * (n + 1) / 2;

    function<void(int, int)> DFS1 = [&](int u, int parent)
    {
        subtreesum[u] = u;
        for(int v : adj[u])
        {
            if(v != parent)
            {
                DFS1(v, u);
                subtreesum[u] += subtreesum[v];
            }
        }
    };

    function<void(int, int)> DFS2 = [&](int u, int parent)
    {
        for(int v : adj[u])
        {
            if(v != parent)
            {
                result[u] = max(result[u], subtreesum[v]);
                result[v] = max(result[v], total - subtreesum[v]);
                DFS2(v, u);
            }
        }
    };

    DFS1(1, -1);
    DFS2(1, -1);
    return result;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result = Traffic(n, adj);
    for(int i=1; i<=n; i++)
    {
        cout << i << ": " << result[i] << endl;
    }
}
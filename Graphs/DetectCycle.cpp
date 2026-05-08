#include<bits/stdc++.h>
using namespace std;

bool DFS(int u, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path)
{
    visited[u] = 1;
    path[u] = 1;
    for(auto& v : adj[u])
    {
        if(!visited[v])
        {
            if(DFS(v, adj, visited, path))
            {
                return true;
            }
        }
        else if(path[v])
        {
            return true;
        }
    }
    path[u] = 0;
    return false;
}

void DetectCycle(int n, vector<vector<int>>& adj)
{
    vector<int> visited(n, 0), path(n, 0);
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(DFS(i, adj, visited, path))
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main()
{
    ifstream in("input.txt");
    int n, e;
    in >> n >> e;
    vector<vector<int>> adj(n);
    for(int i=0; i<e; i++)
    {
        int u, v;
        in >> u >> v;

        adj[u].push_back(v);
    }
    DetectCycle(n, adj);
}
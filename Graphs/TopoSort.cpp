//Kahn's Algorithm

#include<bits/stdc++.h>
using namespace std;

void TopoSort(int n, vector<vector<int>>& adj, vector<int>& indegree)
{
    vector<bool> visited(n, false);
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(indegree[i] == 0)
        {
            visited[i] = true;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(auto& v : adj[u])
        {
            if(!visited[v])
            {
                if(--indegree[v] == 0)
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    ifstream in("input.txt");
    int n, e;
    in >> n >> e;
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for(int i=0; i<e; i++)
    {
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    TopoSort(n, adj, indegree);
}

// 6 7
// 0 1
// 0 4
// 1 2
// 1 4
// 2 3
// 3 4
// 3 5
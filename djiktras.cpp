#include<bits/stdc++.h>
using namespace std;

void DjiktrasAlgorithm(int n, vector<vector<int>>& adj, vector<vector<int>>& distance)
{
    for(int i=0; i<n; i++)
    {
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        visited[i] = true;
        distance[i][i] = 0;
        q.push({i, 0});
        while(!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(auto& v : adj[node])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    distance[i][v] = dist + 1;
                    q.push({v, dist + 1});
                }
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    for(int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
    DjiktrasAlgorithm(n, adj, distance);
    cout << "Distance matrix: " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << (distance[i][j] == INT_MAX ? -1 : distance[i][j]) << " ";
        }
        cout << endl;
    }
}
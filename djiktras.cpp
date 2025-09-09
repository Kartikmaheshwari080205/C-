#include<bits/stdc++.h>
using namespace std;

pair<vector<int>, vector<int>> Djiktras(int n, vector<vector<pair<int, int>>>& adj, int src)
{
    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);
    distance[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(dist > distance[node])
        {
            continue;
        }
        for(auto& edge : adj[node])
        {
            if(distance[edge.first] > dist + edge.second)
            {
                distance[edge.first] = dist + edge.second;
                parent[edge.first] = node;
                pq.push({distance[edge.first], edge.first});
            }
        }
    }
    return {distance, parent};
}

vector<int> GetPath(int src, int dest, vector<int>& parent)
{
    vector<int> path;
    for(int v = dest; v != -1; v = parent[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    if(path[0] != src)
    {
        return {};
    }
    return path;
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
        adj[v].push_back({u, w});
    }
    int src, dest;
    cin >> src >> dest;

    auto result = Djiktras(n, adj, src);
    vector<int> distance = result.first;
    vector<int> parent = result.second;
    if(distance[dest] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << distance[dest] << endl;
        vector<int> path = GetPath(src, dest, parent);
        for(auto& node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
}
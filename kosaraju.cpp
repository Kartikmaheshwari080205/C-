#include<bits/stdc++.h>
using namespace std;

void DFS1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            DFS1(v, adj, visited, st);
        }
    }
    st.push(u);
}

void DFS2(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component)
{
    visited[u] = true;
    component.push_back(u);
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            DFS2(v, adj, visited, component);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), transpose(n);
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        transpose[v].push_back(u);
    }
    vector<bool> visited(n, false);
    stack<int> st;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            DFS1(i, adj, visited, st);
        }
    }
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> scc;
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if(!visited[u])
        {
            vector<int> component;
            DFS2(u, transpose, visited, component);
            scc.push_back(component);
        }
    }

    sort(scc.begin(), scc.end());
    cout << "Strongly Connected Components: " << endl;
    for(auto& component : scc)
    {
        sort(component.begin(), component.end());
        for(int node : component)
        {
            cout << node+1 << " ";
        }
        cout << endl;
    }
}
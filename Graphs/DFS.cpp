#include<bits/stdc++.h>
using namespace std;

void DFS(int n, vector<vector<int>>& adj)
{
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(0);
    visited[0] = true;
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        cout << u << " ";
        for(auto& v : adj[u])
        {
            if(!visited[v])
            {
                st.push(v);
                visited[v] = true;
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
    for(int i=0; i<e; i++)
    {
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(n, adj);
}

// 6 7
// 0 1
// 0 4
// 1 2
// 1 4
// 2 3
// 3 4
// 3 5
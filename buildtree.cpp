#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    vector<TreeNode*> children;

    TreeNode(int x) : val(x) {}
};

TreeNode* BuildTree(unordered_map<int, unordered_set<int>>& adj)
{
    unordered_set<int> children;
    unordered_map<int, TreeNode*> nodes;
    for(auto& a : adj)
    {
        int u = a.first;
        if(!nodes.count(u))
        {
            nodes[u] = new TreeNode(u);
        }
        for(int neighbour : a.second)
        {
            if(!nodes.count(neighbour))
            {
                nodes[neighbour] = new TreeNode(neighbour);
            }
            children.insert(neighbour);
        }
    }
    int root = -1;
    for(auto& a : adj)
    {
        if(!children.count(a.first))
        {
            root = a.first;
            break;
        }
    }
    for(auto& a : adj)
    {
        for(int v : a.second)
        {
            nodes[a.first]->children.push_back(nodes[v]);
        }
    }
    return nodes[root];
}

void PrintTree(TreeNode* root)
{
    if(!root)
    {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            for(TreeNode* child : node->children)
            {
                q.push(child);
            }
        }
        cout << endl;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int>> adj;
    for(int i=0; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
    }

    TreeNode* root = BuildTree(adj);

    PrintTree(root);
}
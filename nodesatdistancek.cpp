#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
} TreeNode;

vector<int> result;

void KthChild(TreeNode* node, int k, int currentdepth)
{
    if(!node)
    {
        return;
    }
    if(currentdepth == k)
    {
        result.push_back(node->val);
        return;
    }
    KthChild(node->left, k, currentdepth+1);
    KthChild(node->right, k, currentdepth+1);
}

int KthNeighbour(TreeNode* root, int k, int target)
{
    if(!root)
    {
        return -1;
    }
    if(root->val == target)
    {
        KthChild(root, k, 0);
        return 0;
    }
    int left = KthNeighbour(root->left, k, target);
    if(left != -1)
    {
        if(left + 1 == k)
        {
            result.push_back(root->val);
        }
        else
        {
            KthChild(root->right, k-left-2, 0);
        }
        return left + 1;
    }
    int right = KthNeighbour(root->right, k, target);
    if(right != -1)
    {
        if(right + 1 == k)
        {
            result.push_back(root->val);
        }
        else
        {
            KthChild(root->left, k-right-2, 0);
        }
        return right + 1;
    }
    return -1;
}

TreeNode* BuildTree(int n, vector<int>& nums)
{
    if(n == 0)
    {
        return nullptr;
    }
    unordered_map<int, TreeNode*> map;
    TreeNode* root = nullptr;
    for(int i=0; i<n; i++)
    {
        if(nums[i] != -1)
        {
            TreeNode* node = new TreeNode(nums[i]);
            map[i] = node;
            if(i == 0)
            {
                root = node;
            }
            else
            {
                int parentIndex = (i - 1) / 2;
                TreeNode* parent = map[parentIndex];
                if(i % 2 == 1)
                {
                    parent->left = node;
                }
                else
                {
                    parent->right = node;
                }
            }
        }
    }
    return root;
}

int main()
{
    int n, k, target;
    cin >> n >> k >> target;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    TreeNode* root = BuildTree(n, nums);
    KthNeighbour(root, k, target);
    for(int r : result)
    {
        cout << r << " ";
    }
    cout << endl;
}
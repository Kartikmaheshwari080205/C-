#include<bits/stdc++.h>
using namespace std;

enum Color {RED, BLACK};

struct Node
{
    int val;
    bool color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value) : val(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBT
{
    private:
    Node* root;

    void RotateLeft(Node* &pt)
    {
        Node* pt_right = pt->right;
        pt->right = pt_right->left;
        if(pt->right == nullptr)
        {
            pt->right->parent = pt;
        }
        pt_right->parent = pt->parent;
        if(pt->parent == nullptr)
        {
            root = pt_right;
        }
        else if(pt == pt->parent->left)
        {
            pt->parent->left = pt_right;
        }
        else
        {
            pt->parent->right = pt_right;
        }
        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void RotateRight(Node* &pt)
    {
        Node *pt_left = pt->left;
        pt->left = pt_left->right;
        if(pt->left != nullptr)
        {
            pt->left->parent = pt;
        }
        pt_left->parent = pt->parent;
        if(pt->parent == nullptr)
        {
            root = pt_left;
        }
        else if(pt == pt->parent->left)
        {
            pt->parent->left = pt_left;
        }
        else
        {
            pt->parent->right = pt_left;
        }
        pt_left->right = pt;
        pt->parent = pt_left;
    }

    void FixViolation(Node* &pt)
    {
        Node *parent_pt = nullptr;
        Node *grand_parent_pt = nullptr;
        while((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
        {
            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;
            if(parent_pt == grand_parent_pt->left)
            {
                Node *uncle_pt = grand_parent_pt->right;
                if(uncle_pt != nullptr && uncle_pt->color == RED)
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else
                {
                    if(pt == parent_pt->right)
                    {
                        RotateLeft(parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    RotateRight(grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
            else
            {
                Node *uncle_pt = grand_parent_pt->left;
                if((uncle_pt != nullptr) && (uncle_pt->color == RED))
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else
                {
                    if(pt == parent_pt->left)
                    {
                        RotateRight(parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    RotateLeft(grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }
        root->color = BLACK;
    }

    public:
    RBT() : root(nullptr) {}

    void insert(const int& data)
    {
        Node* pt = new Node(data);
        Node* parent = nullptr;
        Node* current = root;
        while(current != nullptr)
        {
            parent = current;
            if(pt->val < current->val)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        pt->parent = parent;
        if(parent == nullptr)
        {
            root = pt;
        }
        else if(pt->val < parent->val)
        {
            parent->left = pt;
        }
        else
        {
            parent->right = pt;
        }
        FixViolation(pt);
    }

    void InorderHelper(Node* root, vector<int>& inorder)
    {
        if(root == nullptr)
        {
            return;
        }
        InorderHelper(root->left, inorder);
        inorder.push_back(root->val);
        InorderHelper(root->right, inorder);
        return;
    }

    vector<int> inorder()
    {
        vector<int> result;
        InorderHelper(root, result);
        return result;
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter node values: ";
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    RBT tree;
    for(int i=0; i<n; i++)
    {
        tree.insert(A[i]);
    }
    vector<int> inorder = tree.inorder();
    cout << "Inorder traversal of tree: ";
    for(int i=0; i<n; i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;
}
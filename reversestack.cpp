#include<bits/stdc++.h>
using namespace std;

void InsertBottom(stack<int>& st, int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    InsertBottom(st, x);
    st.push(y);
    return;
}

void ReverseStack(stack<int>& st)
{
    if(st.empty())
    {
        return;
    }
    int x = st.top();
    st.pop();
    ReverseStack(st);
    InsertBottom(st, x);
    return;
}

int main()
{
    int n;
    cin >> n;
    stack<int> st;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    ReverseStack(st);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
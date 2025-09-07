#include<bits/stdc++.h>
using namespace std;

void ReverseStack(stack<int>& st)
{
    if(st.empty())
    {
        return;
    }
    int x = st.top();
    st.pop();
    ReverseStack(st);
    stack<int> temp;
    while(!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while(!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
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
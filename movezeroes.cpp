#include<bits/stdc++.h>
using namespace std;

void MoveZeroes(int n, vector<int>& A)
{
    deque<int> dq;
    for(int i=0; i<n; i++)
    {
        if(A[i])
        {
            dq.push_front(A[i]);
        }
        else
        {
            dq.push_back(A[i]);
        }
    }
    A = vector<int>(dq.begin(), dq.end());
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    MoveZeroes(n, A);
    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
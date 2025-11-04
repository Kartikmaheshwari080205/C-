#include<bits/stdc++.h>
using namespace std;

int MinTimeToReachTarget(int n, vector<vector<int>>& A)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-1 >= 0 && j-1 >= 0)
            {
                A[i][j] = min(max(A[i][j], A[i-1][j]), max(A[i][j], A[i][j-1]));
            }
            else if(i-1 >= 0)
            {
                A[i][j] = max(A[i][j], A[i-1][j]);
            }
            else if(j-1 >= 0)
            {
                A[i][j] = max(A[i][j], A[i][j-1]);
            }
        }
    }
    return A[n-1][n-1];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << MinTimeToReachTarget(n, A) << endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
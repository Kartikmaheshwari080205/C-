#include<bits/stdc++.h>
using namespace std;

void FloydWarshall(int n, vector<vector<int>>& A)
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(A[i][k] != INT_MAX && A[k][j] != INT_MAX)
                {
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
    }
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
            if(A[i][j] == -1)
            {
                A[i][j] = INT_MAX;
            }
        }
    }
    FloydWarshall(n, A);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(A[i][j] == INT_MAX)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << A[i][j] << " ";
            }
        }
        cout << endl;
    }
}
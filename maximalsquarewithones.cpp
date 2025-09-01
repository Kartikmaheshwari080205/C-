#include<bits/stdc++.h>
using namespace std;

int MaximalSquare(int n, vector<vector<int>>& A)
{
    int result = 0;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(A[i-1][j-1] == 1)
            {
                dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
                result = max(result, dp[i][j]);
            }
        }
    }
    return result;
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
    cout << MaximalSquare(n, A) << endl;
}
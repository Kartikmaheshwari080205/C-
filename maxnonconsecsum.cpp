#include<bits/stdc++.h>
using namespace std;

int MaxSumOfElements(int n, vector<int>& A, int k)
{
    vector<vector<int>> dp(n, vector<int>(k+1, INT_MIN));
    dp[0][0] = 0;
    if(k >= 1)
    {
        dp[0][1] = A[0];
    }
    for(int i=1; i<n; i++)
    {
        dp[i][0] = 0;
        for(int j=1; j<=k; j++)
        {
            int notpick = dp[i-1][j];
            int pick = INT_MIN;
            if(i >= 2)
            {
                pick = dp[i-2][j-1] + A[i];
            }
            else if(j == 1)
            {
                pick = A[i];
            }
            dp[i][j] = max(notpick, pick);
        }
    }
    int result = 0;
    for(int j=0; j<=k; j++)
    {
        result = max(result, dp[n-1][j]);
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    cout << MaxSumOfElements(n, A, k) << endl;
}
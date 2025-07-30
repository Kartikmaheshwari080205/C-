#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int factorial(int n)
{
    long long result = 1;
    for(int i=2; i<=n; i++)
    {
        result = (result * i) % MOD;
    }
    return result;
}

int ways(int n, int i)
{
    if(i > n)
    {
        return 0;
    } 
    if(i == 1)
    {
        return 1;
    } 
    if(i == n)
    {
        return factorial(n);
    }
    vector<vector<int>> dp(n+1, vector<int>(i+1, 0));
    dp[0][0] = 1;
    for(int j=1; j<=n; j++)
    {
        for(int k=1; k<=min(j, i); k++)
        {
            dp[j][k] = (dp[j-1][k-1] + k * dp[j-1][k]) % MOD;
        }
    }
    return (dp[n][i] * factorial(i)) % MOD;
}

int Distribute(int n)
{
    long long total = 0;
    for(int i=1; i<=n; i++)
    {
        total = (total + ways(n, i)) % MOD;
    }
    return total;
}

int main()
{
    int n;
    cin >> n;
    cout << Distribute(n);
}
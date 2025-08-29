#include<bits/stdc++.h>
using namespace std;

int CountFactorSubsets(int n)
{
    vector<int> factors;
    for(int i=1; i<=n; i++)
    {
        if(n % i == 0)
        {
            factors.push_back(i);
        }
    }
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for(int factor : factors)
    {
        if(factor != 1)
        {
            for(int i : factors)
            {
                if(i < factor && factor % i == 0)
                {
                    dp[factor] += dp[i];
                }
            }
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << CountFactorSubsets(n) << endl;
}
#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> SuperPrimes(long long n)
{
    vector<vector<long long>> result;
    vector<bool> dp(n+1, true);
    dp[0] = false;
    dp[1] = false;
    for(int i=2; i<=n; i++)
    {
        if(dp[i])
        {
            if(dp[i-2])
            {
                result.push_back({2, i-2, i});
            }
            for(int j=i*2; j<n; j+=i)
            {
                dp[j] = false;
            }
        }
    }
    return result;
}

int main()
{
    long long n;
    cin >> n;
    vector<vector<long long>> result = SuperPrimes(n);
    for(auto& v : result)
    {
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
    }
}
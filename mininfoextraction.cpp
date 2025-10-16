#include<bits/stdc++.h>
using namespace std;

int MinLeak(int n, vector<int>& A, int trust, int maxtrust)
{
    if(trust <= 0)
    {
        return -1;
    }
    if(trust > maxtrust)
    {
        trust = maxtrust;
    }
    vector<long long> dp(maxtrust + 1, LLONG_MAX);
    dp[trust] = 0;
    for(int a : A)
    {
        vector<long long> newdp(maxtrust + 1, LLONG_MAX);
        for(int t=1; t<=maxtrust; t++)
        {
            if(dp[t] == LLONG_MAX)
            {
                continue;
            }
            int nt = t - a;
            if(nt > 0)
            {
                newdp[nt] = min(newdp[nt], dp[t]);
            }
            nt = t * 2;
            if(nt > maxtrust)
            {
                nt = maxtrust;
            }
            newdp[nt] = min(newdp[nt], dp[t] + a);
        }
        dp = newdp;
    }
    long long result = LLONG_MAX;
    for(int t=1; t<=maxtrust; t++)
    {
        result = min(result, dp[t]);
    }
    return result == LLONG_MAX ? -1 : result;
}

int main()
{
    int n, trust, maxtrust;
    cin >> n >> trust >> maxtrust;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    cout << MinLeak(n, A, trust, maxtrust) << endl;
}
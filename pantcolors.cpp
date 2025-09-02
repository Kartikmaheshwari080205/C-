#include<bits/stdc++.h>
using namespace std;

pair<int, string> MinCost(int n, vector<int>& r, vector<int>& b, vector<int>& g)
{
    pair<int, string> result;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = r[0];
    dp[0][1] = b[0];
    dp[0][2] = g[0];
    for(int i=1; i<n; i++)
    {
        dp[i][0] = r[i] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = g[i] + min(dp[i-1][0], dp[i-1][1]);
    }

    result.first = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    char last = (result.first == dp[n-1][0]) ? 'R' : (result.first == dp[n-1][1]) ? 'B' : 'G';
    result.second.resize(n);
    result.second[n-1] = last;
    for(int i=n-2; i>=0; i--)
    {
        if(last == 'R')
        {
            last = (dp[i][1] < dp[i][2]) ? 'B' : 'G';
        }
        else if(last == 'B')
        {
            last = (dp[i][0] < dp[i][2]) ? 'R' : 'G';
        }
        else
        {
            last = (dp[i][0] < dp[i][1]) ? 'R' : 'B';
        }
        result.second[i] = last;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> red(n), blue(n), green(n);
    for(int i=0; i<n; i++)
    {
        cin >> red[i] >> blue[i] >> green[i];
    }

    pair<int, string> result = MinCost(n, red, blue, green);
    cout << result.first << " " << result.second << endl;
}
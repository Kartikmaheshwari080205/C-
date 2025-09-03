#include<bits/stdc++.h>
using namespace std;

bool isInterleaved(string& a, string& b, string& c)
{
    int n = a.size(), m = b.size(), p = c.size();
    if(n + m != p)
    {
        return false;
    }
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i > 0 && a[i-1] == c[i+j-1] && dp[i-1][j])
            {
                dp[i][j] = true;
            }
            if(j > 0 && b[j-1] == c[i+j-1] && dp[i][j-1])
            {
                dp[i][j] = true;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >>s3;
    cout << (isInterleaved(s1, s2, s3) ? "YES" : "NO") << endl;
}
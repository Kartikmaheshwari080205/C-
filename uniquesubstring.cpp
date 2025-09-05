#include<bits/stdc++.h>
using namespace std;

int MaxSubstringLength(string& s)
{
    int n = s.size();
    if(n == 0)
    {
        return 0;
    }
    vector<int> dp(n, 0);
    unordered_map<char, int> last;
    dp[0] = 1;
    last[s[0]] = 0;
    int result = 1;
    for(int i=1; i<n; i++)
    {
        if(!last.count(s[i]))
        {
            dp[i] = dp[i-1] + 1;
        }
        else
        {
            int lastpos = last[s[i]];
            if(i - lastpos > dp[i-1])
            {
                dp[i] = dp[i-1] + 1;
            }
            else
            {
                dp[i] = i - lastpos;
            }
        }
        last[s[i]] = i;
        result = max(result, dp[i]);
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << MaxSubstringLength(s) << endl;
}
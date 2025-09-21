#include<bits/stdc++.h>
using namespace std;

int MaxAchieveableScore(int n, vector<int>& A)
{
    int maxsum = accumulate(A.begin(), A.end(), 0);
    sort(A.begin(), A.end());
    vector<bool> dp(maxsum + 1, false);
    dp[0] = true;
    int result = 0;
    for(int a : A)
    {
        for(int i = result + a; i >= 0; i--)
        {
            if(dp[i] && a > i)
            {
                dp[i + a] = true;
                result = max(result, i + a);
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    cout << MaxAchieveableScore(n, A) << endl;
}
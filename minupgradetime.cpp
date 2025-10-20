#include<bits/stdc++.h>
using namespace std;

bool IsPossible(vector<vector<long long>>& prefix, long long lcm, long long mid, int t1, int t2)
{
    long long complete = mid / lcm;
    long long remainder = mid % lcm;
    long long count0 = complete * prefix[lcm][0] + prefix[remainder][0];
    long long count1 = complete * prefix[lcm][1] + prefix[remainder][1];
    long long count2 = complete * prefix[lcm][2] + prefix[remainder][2];
    long long rem1 = max(0LL, t1 - count1);
    long long rem2 = max(0LL, t2 - count2);
    return (count0 >= (rem1 + rem2)) && (count1 + count0 >= t1) && (count2 + count0 >= t2);
}

long long MinUpgradeTime(int req1, int t1, int req2, int t2)
{
    long long lcm = (long long)req1 * req2 / __gcd(req1, req2);
    vector<vector<long long>> prefix(lcm + 1, vector<long long>(3, 0));
    for(int i = 1; i <= lcm; ++i)
    {
        prefix[i] = prefix[i - 1];
        bool f1 = (i % req1 != 0);
        bool f2 = (i % req2 != 0);
        if(f1 && f2)
        {
            prefix[i][0]++;
        }
        else if(f1) 
        {
            prefix[i][1]++;
        }
        else if(f2) 
        {
            prefix[i][2]++;
        }
    }
    long long left = 1, right = ((long long)(t1 + t2) * max(req1, req2) * 2LL), result = right;
    while(left <= right)
    {
        long long mid = left + (right - left) / 2;
        if(IsPossible(prefix, lcm, mid, t1, t2))
        {
            result = min(result, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

int main()
{
    int req1, t1, req2, t2;
    cin >> req1 >> t1 >> req2 >> t2;
    cout << MinUpgradeTime(req1, t1, req2, t2) << endl;
}
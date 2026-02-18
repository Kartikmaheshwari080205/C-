#include<bits/stdc++.h>
using namespace std;

long MinOperations(int k, vector<int>& locks)
{
    int n = locks.size();
    sort(locks.begin(), locks.end());
    vector<long long> B(2 * n);
    for(int i=0; i<n; i++)
    {
        B[i] = locks[i];
        B[i+n] = locks[i] + k;
    }
    vector<long long> prefix(2 * n + 1, 0);
    for(int i=1; i<=2*n; i++)
    {
        prefix[i] = prefix[i-1] + B[i-1];
    }
    long long count = LLONG_MAX;
    for(int i=0; i<n; i++)
    {
        int j = i + n - 1;
        if(B[j] - B[i] > k)
        {
            continue;
        }
        int mid = (i + j) / 2;
        long long median = B[mid];
        long long leftcost = median * (mid - i) - (prefix[mid] - prefix[i]);
        long long rightcost = (prefix[j+1] - prefix[mid+1]) - median * (j - mid);
        count = min(count, leftcost + rightcost);
    }
    return (long)count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> locks(n);
    for(int i=0; i<n; i++)
    {
        cin >> locks[i];
    }
    cout << MinOperations(k, locks) << endl;
}
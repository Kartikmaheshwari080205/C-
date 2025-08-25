#include<bits/stdc++.h>
using namespace std;

int MinDiff(int n, vector<int>& A, int k)
{
    vector<pair<int, int>> index;
    for(int i=0; i<n; i++)
    {
        index.push_back({A[i], i});
    }
    sort(index.begin(), index.end());
    int result = INT_MAX;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int diff = abs(index[i].first - index[j].first);
            if(diff < result && abs(index[i].second - index[j].second) >= k)
            {
                result = diff;
                break;
            }
        }
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    cout << MinDiff(n, A, k) << endl;
}
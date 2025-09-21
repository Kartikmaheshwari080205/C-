#include<bits/stdc++.h>
using namespace std;

bool CanServe(int n, int m, vector<int>& A, int time)
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        count += (time / A[i]);
    }
    return count >= m;
}

int MintimeToProcess(int n, int m, vector<int>& A)
{
    int minnum = *min_element(A.begin(), A.end());
    if(m == 0)
    {
        return 0;
    }
    int low = minnum, high = minnum * m;
    int result = high;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(CanServe(n, m, A, mid))
        {
            high = mid - 1;
            result = min(result, mid);
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    cout << MintimeToProcess(n, m, A) << endl;
}
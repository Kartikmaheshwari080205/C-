#include<bits/stdc++.h>
using namespace std;

int DistanceCarried(int n, vector<int>& A, int target)
{
    sort(A.begin(), A.end());
    int result = 0, pos = 0;
    int i=0;
    while(i < n)
    {
        if(A[i] > pos)
        {
            result += (A[i] - pos);
        }
        pos = A[i] + 10;
        if(pos >= target)
        {
            return result;
        }
        while(i < n && A[i] < pos)
        {
            i++;
        }
    }
    if(pos < target)
    {
        result += (target - pos);
    }
    return result;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    cout << DistanceCarried(n, A, target) << endl;
}
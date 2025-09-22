#include<bits/stdc++.h>
using namespace std;

int NumWaysToDivide(vector<int>& A)
{
    int sum = accumulate(A.begin(), A.end(), 0);
    if(sum % 3 != 0)
    {
        return 0;
    }
    int target = sum / 3;
    int result = 0;
    int prefix = 0, count = 0;
    for(int a : A)
    {
        prefix += a;
        if(prefix == 2 * target)
        {
            result += count;
        }
        if(prefix == target)
        {
            count++;
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

    cout << NumWaysToDivide(A) << endl;
}
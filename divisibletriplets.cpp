#include<bits/stdc++.h>
using namespace std;

int Factorial(int n)
{
    int result = 1;
    for(int i=1; i<=n; i++)
    {
        result *= i;
    }
    return result;
}

int nCk(int n, int k)
{
    return Factorial(n) / (Factorial(k) * Factorial(n-k));
}

int DivisibleTriplets(int n, int k, vector<int>& A)
{
    int mod0 = 0;
    for(int a : A)
    {
        if(a % k == 0)
        {
            mod0++;
        }
    }
    int result = nCk(mod0, 3);
    if(k % 2 == 1)
    {
        return result;
    }
    int modkby2 = 0;
    for(int a : A)
    {
        if(a % k == k/2)
        {
            modkby2++;
        }
    }
    return result + nCk(modkby2, 3);
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
    cout << DivisibleTriplets(n, k, A) << endl;
}
#include<bits/stdc++.h>
using namespace std;

int DivisibleTriplets(int n, int k)
{
    int mod0 = n / k;
    int result = pow(mod0, 3);
    if(k % 2 == 0)
    {
        int modkby2 = mod0 + ((n % k) >= (k / 2));
        result += pow(modkby2, 3);
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << DivisibleTriplets(n, k) << endl;
}
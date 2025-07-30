#include<bits/stdc++.h>

using namespace std;

double F(int x, int n)
{
    double result = 0;
    for(int i=1; i<=n; i++)
    {
        result = result + pow(-1,i)*pow(x,i)/tgamma(i+1);
    }
    return result;
}

int main()
{
    int x,n;
    cout << "Enter x and n: ";
    cin >> x >> n;
    cout << endl;
    cout << "F(x,n) is: " << F(x,n);
}
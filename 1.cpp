#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    double combinations;
    cout << "Enter your n: ";
    cin >> n;
    cout << endl << "Enter your k: ";
    cin >> k;
    cout << endl;
    if((k>n) || (n<0 || k<0))
    {
        cout << "ERROR!!, enter correct n and k";
    }
    else
    {
        combinations = tgamma(n+1)/(tgamma(k+1)*tgamma(n-k+1));
        cout << tgamma(n+1) << endl;
        cout << tgamma(k+1) << endl;
        cout << tgamma(n-k+1) << endl;
        cout << combinations;
    }
}
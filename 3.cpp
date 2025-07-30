#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,e;
    cout << "Enter 5 numbers: ";
    cin >> a >> b >> c >> d >> e;
    int minimum = min({a,b,c,d,e});
    cout << "The minimum number is : " << minimum << endl;
}
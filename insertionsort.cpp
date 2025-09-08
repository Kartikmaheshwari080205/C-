#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int n, vector<int>& A)
{
    vector<int> temp;
    for(int a : A)
    {
        auto it = lower_bound(temp.begin(), temp.end(), a);
        temp.insert(it, a);
    }
    A = temp;
    return;
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

    InsertionSort(n, A);
    for(int a : A)
    {
        cout << a << " ";
    }
    cout << endl;
}
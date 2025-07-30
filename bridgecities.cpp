#include <bits/stdc++.h>
using namespace std;

bool isSafe(int index, vector<int>& A, vector<int>& B, vector<int>& included)
{
    for(int j : included)
    {
        if((A[index] < A[j] && B[index] > B[j]) ||  (A[index] > A[j] && B[index] < B[j]))
        {
            return false;
        }
    }
    return true;
}

int Backtrack(int index, vector<int>& A, vector<int>& B, vector<int> included)
{
    if(index < 0)
    {
        return 0;
    }
    int exclude = Backtrack(index - 1, A, B, included);
    int include = 0;
    if(isSafe(index, A, B, included))
    {
        included.push_back(index);
        include = 1 + Backtrack(index - 1, A, B, included);
    }
    return max(exclude, include);
}

int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    vector<int> A(n), B(n);
    cout << "Enter cities on north bank: ";
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    cout << "Enter cities on south bank: ";
    for(int i=0; i<n; i++)
    {
        cin >> B[i];
    }
    vector<int> included;
    cout << "Maximum number of bridges constructed can be: " << Backtrack(n - 1, A, B, included) << endl;
}
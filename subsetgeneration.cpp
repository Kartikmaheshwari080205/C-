//Bitstrings Generation

#include<bits/stdc++.h>

using namespace std;

void SubsetGeneration(int n, vector<int>& A)
{
    for(int i=0; i<(1 << n); i++)
    {
        cout << "Subset " << i+1 << ": { ";
        for(int j=0; j<n; j++)
        {
            if(i & (1 << j))
            {
                cout << A[j] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    vector<int> set(n);
    cout << endl << "Enter the elements of the set: ";
    for(auto& element : set)
    {
        cin >> element;
    }
    SubsetGeneration(n, set);
}
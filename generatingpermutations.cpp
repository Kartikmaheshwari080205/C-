#include<bits/stdc++.h>

using namespace std;

void GeneratePermutations(int n, vector<int>& A)
{
    sort(A.begin(), A.end());
    do
    {
        for(auto& element : A)
        {
            cout << element << " ";
        }
        cout << endl;
    }while(next_permutation(A.begin(), A.end()));
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
    GeneratePermutations(n, set);
}
#include<bits/stdc++.h>
using namespace std;

void QuickSort(vector<int> &A)
{
    int n = A.size();
    if(n <= 1)
    {
        return;
    }
    int pivot = A[0];
    vector<int> left, right;
    for(int i=1; i<n; i++)
    {
        if(A[i] <= pivot)
        {
            left.push_back(A[i]);
        }
        else
        {
            right.push_back(A[i]);
        }
    }
    QuickSort(left);
    QuickSort(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    A = left;
    return;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    QuickSort(A);
    cout << "Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
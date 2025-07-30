#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>& A, int left, int mid, int right)
{
    int l = mid - left + 1, r = right - mid;
    vector<int> L(l), R(r);
    for(int i=0; i<l; i++)
    {
        L[i] = A[left + i];
    }
    for(int i=0; i<r; i++)
    {
        R[i] = A[mid + 1 + i];
    }
    int i=0, j=0, k=left;
    while(i < l && j < r)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < l)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < r)
    {
        A[k] = R[j];
        j++;
        k++;
    }
    return;
}

void MergeSort(vector<int>& A, int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start) / 2;
        MergeSort(A, start, mid);
        MergeSort(A, mid+1, end);
        Merge(A, start, mid, end);
    }
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
    MergeSort(A, 0, n-1);
    cout << "Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
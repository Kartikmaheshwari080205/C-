//Counting Sort

#include<bits/stdc++.h>

using namespace std;

void CountingSort(int n, int arr[])
{
    int maxElement = *max_element(arr, arr + n);
    vector<int> count(maxElement + 1, 0);
    for(int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }
    for(int i=1; i <= maxElement; i++)
    {
        count[i] += count[i-1];
    }
    int result[n];
    for(int i = n-1; i>=0; i--)
    {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    copy(result, result + n, arr);
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << endl << "Enter array elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    CountingSort(n, arr);
    cout << "Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
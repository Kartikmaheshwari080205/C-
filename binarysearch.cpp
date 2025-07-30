#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter your array size: ";
    cin >> n;
    int arr[n];
    cout << endl << "Enter array elements: ";
    for(int i=0; i<n; i++)
    {
        cin >>  arr[i];
    }
    sort(arr, arr+n);
    int x;
    cout << endl << "Enter the element to search for: ";
    cin >> x;
    
    int k=0;
    for(int i = n/2; i>=1; i/=2)
    {
        while(k+i < n && arr[k+i] <= x)
        {
            k = k+i;
        }
    }
    if(arr[k] == x)
    {
        cout << "Value " << x << " found at index " << k << endl;
    }
    else
    {
        cout << "Value " << x << " not found in the array." << endl;
    }
}
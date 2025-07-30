//Kadane's Algorithm

#include<bits/stdc++.h>

using namespace std;

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

    int best = 0;
    int sum = 0;
    int start = 0;
    int currentStart = 0;
    int end = 0;
    for(int k=0; k<n; k++)
    {
        if(arr[k] > sum+arr[k])
        {
            sum = arr[k];
            currentStart = k;
        }
        else
        {
            sum = sum + arr[k];
        }
        if(sum > best)
        {
            best = sum;
            start = currentStart;
            end = k;
        }
    }
    cout << "Maximum subarray sum: " << best << endl;
    cout << "Subarray with maximum sum : ";
    for(int i=start; i<=end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int size = 1e6;
    vector<bool> prime(size, true);
    prime[0] = prime[1] = false;
    vector<int> result;
    for(int i=2; i<size; i++)
    {
        if(prime[i])
        {
            result.push_back(i);
            if(result.size() == n)
            {
                break;
            }
            for(int j=i*2; j<size; j+=i)
            {
                prime[j] = false;
            }
        }
    }
    cout << "{";
    for(int r : result)
    {
        cout << r << ", ";
    }
    cout << endl;
}
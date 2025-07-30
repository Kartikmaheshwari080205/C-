//Dynamic Programming

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter the sum need to be produced: ";
    cin >> n;
    int c;
    cout << endl << "Enter the number of types of coins: ";
    cin >> c;
    vector<int> coins(c);
    cout << endl << "Enter the possible coin values: ";
    for(auto& element : coins)
    {
        cin >> element;
    }
    vector<int> value(n+1, INT_MAX);
    value[0] = 0;
    for(int i=1; i<=n; i++)
    {
        for(auto element : coins)
        {
            if(i-element >= 0)
            {
                value[i] = min(value[i], value[i-element] + 1);
            }
        }
    }
    if(value[n] == INT_MAX)
    {
        cout << "Sum not possible with the given denominations" << endl;
    }
    else
    {
        cout << "The minimum number of coins required is: " << value[n] << endl;
    }
}
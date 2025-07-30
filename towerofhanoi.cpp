#include<bits/stdc++.h>

using namespace std;

void TowerofHanoi(int n, char source, char auxiliary, char destination)
{
    if(n==1)
    {
        cout << "Move disc 1 from " << source << " to " << destination << endl;
    }
    else
    {
        TowerofHanoi(n-1, source, destination, auxiliary);
        cout << "Move disc " << n << " from " << source << " to " << destination << endl;
        TowerofHanoi(n-1, auxiliary, source, destination);
    }
}

int main()
{
    int n;
    cout << "Enter the number of discs: ";
    cin >> n;
    cout << endl;
    if(n==0)
    {
        cout << "Enter nonzero number of discs" << endl;
    }
    else
    {
        int count = pow(2, n) - 1;
        cout << "The number of movements required for tower of " << n << " discs is: " << count << endl;
        TowerofHanoi(n, 'A', 'B', 'C');
    }
}
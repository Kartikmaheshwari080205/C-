#include<bits/stdc++.h>
using namespace std;

bool isValid(string& s)
{
    int low = 0, high = 0;
    for(char c : s)
    {
        if(c == '(')
        {
            low++;
            high++;
        }
        else if(c == ')')
        {
            low--;
            high--;
        }
        else if(c == '*')
        {
            low--;
            high++;
        }
        if(high < 0)
        {
            return false;
        }
        if(low < 0)
        {
            low = 0;
        }
    }
    return low == 0;
}

int main()
{
    string s;
    cin >> s;
    cout << (isValid(s) ? "YES" : "NO") << endl;
}
#include<bits/stdc++.h>
using namespace std;

int MaxSubsequenceLength(int n, string s, int k)
{
    string pattern = to_string(k);
    if(k >= 0 && k <= 9)
    {
        pattern = '0' + pattern;
    }
    int m = 2;
    int i=0, j=0;
    int result = 0;
    while(i < n)
    {
        if(s[i] == pattern[j])
        {
            j++;
            if(j == m)
            {
                result += 2;
                j = 0;
            }
        }
        i++;
    }
    return result;
}

int MaxGoodString(string s)
{
    int n = s.size();
    int result = 0;
    for(int i=0; i<100; i++)
    {
        result = max(result, MaxSubsequenceLength(n, s, i));
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << MaxGoodString(s) << endl;
}
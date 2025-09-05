#include<bits/stdc++.h>
using namespace std;

int MaxSubstringLength(string& s)
{
    int n = s.size();
    unordered_set<char> set;
    int result = 0, left = 0;
    for(int right = 0; right < n; right++)
    {
        while(set.count(s[right]))
        {
            set.erase(s[left++]);
        }
        set.insert(s[right]);
        result = max(result, right - left + 1);
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << MaxSubstringLength(s) << endl;
}
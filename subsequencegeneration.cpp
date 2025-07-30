#include<bits/stdc++.h>
using namespace std;

void Backtrack(string& s, int index, int end, string& current, vector<string>& result)
{
    if(index == end)
    {
        if(!current.empty())
        {
            result.push_back(current);
        }
        return;
    }
    Backtrack(s, index+1, end, current, result);
    current += s[index];
    Backtrack(s, index+1, end, current, result);
    current.pop_back();
}

vector<string> GenerateSubsequences(string s)
{
    vector<string> result;
    string current = "";
    Backtrack(s, 0, s.size(), current, result);
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    string s;
    cin >> s;
    vector<string> result = GenerateSubsequences(s);
    for(string c : result)
    {
        cout << c << endl;
    }
}
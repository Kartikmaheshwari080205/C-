#include<bits/stdc++.h>
using namespace std;

string ReplaceChar(string& s, vector<pair<char, char>> queries)
{
    vector<char> alphabets(26);
    for(int i=0; i<26; i++)
    {
        alphabets[i] = 'a' + i;
    }
    for(auto& query : queries)
    {
        char a = query.first, b = query.second;
        alphabets[a - 'a'] = b;
        for(auto& alphabet : alphabets)
        {
            if(alphabet == a)
            {
                alphabet = b;
            }
        }
    }
    string result;
    for(char c : s)
    {
        result += alphabets[c - 'a'];
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<pair<char, char>> queries(q);
    for(int i=0; i<q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    cout << ReplaceChar(s, queries) << endl;
}
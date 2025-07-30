#include<bits/stdc++.h>
using namespace std;

void StoM(string&s, vector<vector<string>>& result)
{
    vector<string> words;
    string temp = "";
    for(char c : s)
    {
        if(c == ' ')
        {
            if(!temp.empty())
            {
                words.push_back(temp);
                temp = "";
            }
        }
        else
        {
            temp += c;
        }
    }
    if(!temp.empty())
    {
        words.push_back(temp);
        temp = "";
    }
    int N = result.size(), x = result[0].size();
    int row = 0, col = 0;
    int change = 1;
    for(const string& word : words)
    {
        result[row][col] = word;
        row += change, col ++;
        if(row == N-1)
        {
            change = -1;
        }
        else if(row == 0)
        {
            change = 1;
        }
    }
}

void MtoS(vector<vector<string>>& result, string& s)
{
    int N = result.size(), x = result[0].size();
    s.clear();
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<x; j++)
        {
            if(result[i][j] != " ")
            {
                s += result[i][j] + " ";
            }
        }
    }
    if(!s.empty())
    {
        s.pop_back();
    }
}

int main()
{
    string s;
    getline(cin, s);
    int N, n;
    cin >> N >> n;
    int x = count(s.begin(), s.end(), ' ') + 1;
    vector<vector<string>> result(N, vector<string>(x, " "));
    StoM(s, result);
    MtoS(result, s);
    if(n == 1)
    {
        cout << s;
    }
    else
    {
        StoM(s, result);
        MtoS(result, s);
        cout << s;
    }
}
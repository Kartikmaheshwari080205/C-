#include<bits/stdc++.h>
using namespace std;

vector<string> ParseArticle(int n, int width, vector<string>& A)
{
    string asterisk(width+2, '*');
    vector<string> result;
    result.push_back(asterisk);
    string current = "*";
    int currentwidth = 0;
    for(int i=0; i<n; i++)
    {
        string word = A[i];
        int length = word.size();
        if(currentwidth + length + 1 <= width)
        {
            if(currentwidth > 0)
            {
                current += " ";
                currentwidth++;
            }
            current += word;
            currentwidth += length;
        }
        else
        {
            string text = current.substr(1);
            string paddingLeft((width - currentwidth) / 2, ' ');
            string paddingRight((width - currentwidth + 1) / 2, ' ');
            current = "*" + paddingLeft + text + paddingRight + "*";
            result.push_back(current);
            current = "*" + word;
            currentwidth = length;
        }
    }
    if(currentwidth > 0)
    {
        string text = current.substr(1);
        string paddingLeft((width - currentwidth) / 2, ' ');
        string paddingRight((width - currentwidth + 1) / 2, ' ');
        current = "*" + paddingLeft + text + paddingRight + "*";
        result.push_back(current);
    }
    result.push_back(asterisk);
    return result;
}

int main()
{
    int n, width;
    cin >> n >> width;
    vector<string> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    vector<string> result = ParseArticle(n, width, A);
    for(auto& r : result)
    {
        cout << r << endl;
    }
}
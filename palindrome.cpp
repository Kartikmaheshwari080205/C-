#include<bits/stdc++.h>
#include<chrono>
using namespace std;

unordered_set<int> bfspalindromes, bruteforcepalindromes;

bool isPalindrome(int n)
{
    if(n >= 0 && n <= 9)
    {
        return true;
    }
    string s = to_string(n);
    int left = 0, right = s.size() - 1;
    while(left <= right)
    {
        if(s[left++] != s[right--])
        {
            return false;
        }
    }
    return true;
}

void BruteForcePalindromes(int n)
{
    int result = 0;
    for(int i=0; i<=n; i++)
    {
        if(isPalindrome(i))
        {
            result++;
            bruteforcepalindromes.insert(i);
        }
    }
    cout << "There are " << result << " palindromes from 0 to " << n << endl;
}

void BFS(int n)
{
    int maxlen = to_string(n).size();
    int result = 0;
    queue<string> q;
    q.push("");
    for(int i=0; i<=min(9, n); i++)
    {
        q.push(to_string(i));
    }
    while(!q.empty())
    {
        string s = q.front();
        q.pop();
        if((s.size() >= 2 && s[0] != '0') || (s.size() == 1))
        {
            result++;
            bfspalindromes.insert(stoi(s));
        }
        for(char c='0'; c<='9'; c++)
        {
            string t = c + s + c;
            if(stoll(t) <= n && t.size() <= maxlen)
            {
                q.push(t);
            }
        }
    }
    cout << "There are " << result << " palindromes from 0 to " << n << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    auto start = chrono::high_resolution_clock::now(); 
    BruteForcePalindromes(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> timetaken = end - start;
    cout << "Time taken: " << timetaken.count() << " seconds to brute force" << endl;
    start = chrono::high_resolution_clock::now();
    BFS(n);
    end = chrono::high_resolution_clock::now();
    timetaken = end - start;
    cout << "Time taken: " << timetaken.count() << " seconds to bfs" << endl;
}
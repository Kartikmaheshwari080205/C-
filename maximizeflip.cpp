#include<bits/stdc++.h>
using namespace std;

long long MaximizeFlip(int n, vector<int>& A)
{
    long long result = 0;
    unordered_set<string> visited;
    queue<vector<bool>> q;
    vector<bool> initial(n, false);
    q.push(initial);
    while(!q.empty())
    {
        vector<bool> current = q.front();
        q.pop();
        string s;
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            if(current[i] == true)
            {
                s += '1';
                sum += A[i];
            }
            else
            {
                s += '0';
            }
        }
        visited.insert(s);
        result = max(result, sum);
        for(int i=2; i<n; i++)
        {
            if(s[i] == s[i-1] && s[i] == s[i-2])
            {
                int parity = s[i] - '0';
                vector<bool> next = current;
                next[i] = next[i-1] = next[i-2] = !parity;
                string nexts = s;
                nexts[i] = nexts[i-1] = nexts[i-2] = (!parity) + '0';
                if(!visited.count(nexts))
                {
                    q.push(next);
                }
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    cout << MaximizeFlip(n, A) << endl;
}
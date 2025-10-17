#include<bits/stdc++.h>
using namespace std;

int MinExecutionTime(int n, vector<char>& A, int k)
{
    unordered_map<char, int> frequency;
    unordered_map<char, int> index;
    for(char a : A)
    {
        frequency[a]++;
        if(!index.count(a))
        {
            index[a] = -k;
        }
    }
    int current = 1;
    while(!frequency.empty())
    {
        vector<pair<int, char>> candidate;
        for(auto& [c, count] : frequency)
        {
            if(current - index[c] > k)
            {
                candidate.push_back({index[c], c});
            }
        }
        if(candidate.empty())
        {
            cout << "null ";
        }
        else
        {
            sort(candidate.begin(), candidate.end(), [&](pair<int, char>& a, pair<int, char>& b){
                if(a.first == b.first)
                {
                    if(frequency[a.second] == frequency[b.second])
                    {
                        return a.second < b.second;
                    }
                    return frequency[a.second] > frequency[b.second];
                }
                return a.first < b.first;
            });
            char toexecute = candidate[0].second;
            frequency[toexecute]--;
            index[toexecute] = current;
            if(frequency[toexecute] == 0)
            {
                frequency.erase(toexecute);
            }
            cout << toexecute << " ";
        }
        current++;
    }
    cout << endl;
    return current - 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<char> A(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    
    cout << MinExecutionTime(n, A, k) << endl;
}
#include<bits/stdc++.h>
using namespace std;

int CollectCandies(int n, int m, vector<vector<int>>& A)
{
    map<int, pair<int, int>> candies;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j] == 1)
            {
                if(!candies.count(i))
                {
                    candies[i] = {j, j};
                }
                else
                {
                    candies[i].first = min(candies[i].first, j);
                    candies[i].second = max(candies[i].second, j);
                }
            }
        }
    }
    int currentrow = 0, currentindex = 0;
    int total = 0;
    for(auto& candy : candies)
    {
        int row = candy.first;
        int first = candy.second.first;
        int last = candy.second.second;
        total += (row - currentrow);
        int distfirst = abs(currentindex - first);
        int distlast = abs(currentindex - last);
        total += min(distfirst, distlast);
        total += (last - first);
        currentrow = row;
        currentindex = (distfirst < distlast) ? last : first;
    }
    return total;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << CollectCandies(n, m, A) << endl;
}
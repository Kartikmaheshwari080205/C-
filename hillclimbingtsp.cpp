#include<bits/stdc++.h>
using namespace std;

int GetValue(string state, unordered_map<char, unordered_map<char, int>>& adj)
{
    int result = 0;
    for(int i=0; i<state.size() - 1; i++)
    {
        result += adj[state[i]][state[i+1]];
    }
    return result;
}

pair<string, int> GlobalBest(string& state, unordered_map<char, unordered_map<char, int>>& adj)
{
    unordered_map<string, int> values;
    queue<string> q;
    q.push(state);
    values[state] = GetValue(state, adj);
    string beststate = state;
    int bestvalue = values[state];
    while(!q.empty())
    {
        string curr = q.front();
        q.pop();
        for(int i=0; i<curr.size(); i++)
        {
            for(int j=i+1; j<(int)curr.size(); j++)
            {
                string neigh = curr;
                swap(neigh[i], neigh[j]);
                if(values.find(neigh) == values.end())
                {
                    int val = GetValue(neigh, adj);
                    values[neigh] = val;
                    q.push(neigh);
                    if(val < bestvalue)
                    {
                        bestvalue = val;
                        beststate = neigh;
                    }
                }
            }
        }
    }
    return {beststate, bestvalue};
}

pair<string, int> HillClimb(string state, unordered_map<char, unordered_map<char, int>>& adj)
{
    unordered_map<string, int> values;
    values[state] = GetValue(state, adj);
    while(true)
    {
        string beststate = state;
        int bestvalue = values[state];
        for(int i=1; i<state.size(); i++)
        {
            string neighbour = state;
            swap(neighbour[i-1], neighbour[i]);
            if(values.find(neighbour) == values.end())
            {
                int val = GetValue(neighbour, adj);
                values[neighbour] = val;
                if(val < bestvalue)
                {
                    bestvalue = val;
                    beststate = neighbour;
                }
            }
        }
        if(beststate == state)
        {
            return {state, values[state]};
        }
    }
    return {state, values[state]};
}

int main()
{
    int n;
    cin >> n;
    unordered_map<char, unordered_map<char, int>> adj;
    for(int i=0; i < n*(n-1)/2; i++)
    {
        char a, b;
        int w;
        cin >> a >> b >> w;
        adj[a][b] = w;
        adj[b][a] = w;
    }

    string state;
    cin >> state;
    auto hillclimb = HillClimb(state, adj);
    auto best = GlobalBest(state, adj);
    cout << "Local Best State: " << hillclimb.first << " Cost: " << hillclimb.second << endl;
    cout << "Global Best State: " << best.first << " Cost: " << best.second << endl;
}
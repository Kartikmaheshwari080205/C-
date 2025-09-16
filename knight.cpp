#include<bits/stdc++.h>
using namespace std;

int MinMoves(int n, int m, int x1, int y1, int x2, int y2)
{
    vector<pair<int, int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    q.push({x1 - 1, y1 - 1});
    dp[x1 - 1][y1 - 1] = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dp[nx][ny] == INT_MAX)
            {
                dp[nx][ny] = dp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dp[x2 - 1][y2 - 1] == INT_MAX ? -1 : dp[x2 - 1][y2 - 1];
}

int main()
{
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    cout << MinMoves(n, m, x1, y1, x2, y2) << endl;
}
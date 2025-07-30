#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

bool canPlace(const string& word, const vector<vector<char>>& grid, int row, int col, int dx, int dy)
{
    int n = word.length();
    int endRow = row + dx * (n - 1);
    int endCol = col + dy * (n - 1);
    if(endRow < 0 || endRow >= 10 || endCol < 0 || endCol >= 10)
    {
        return false;
    }
    for(int i = 0; i < n; i++)
    {
        int r = row + i * dx;
        int c = col + i * dy;
        if(grid[r][c] != '.' && grid[r][c] != word[i])
        {
            return false;
        }
    }
    return true;
}

void placeWord(string& word, vector<vector<char>>& grid, int row, int col, int dx, int dy)
{
    for(int i=0; i < word.size(); i++)
    {
        int r = row + i * dx;
        int c = col + i * dy;
        grid[r][c] = word[i];
    }
}

void removeWord(const string& word, vector<vector<char>>& grid, int row, int col, int dx, int dy, const vector<vector<char>>& prev)
{
    for (int i=0; i < word.size(); i++)
    {
        int r = row + i * dx;
        int c = col + i * dy;
        grid[r][c] = prev[r][c];
    }
}

bool backtrack(vector<string>& words, int idx, vector<vector<char>>& grid)
{
    if(idx == words.size())
    {
        return true;
    }
    string word = words[idx];
    for(int row = 0; row < 10; row++)
    {
        for(int col = 0; col < 10; col++)
        {
            for(int dir = 0; dir < 8; dir++)
            {
                int dx = directions[dir].first, dy = directions[dir].second;   
                if(canPlace(word, grid, row, col, dx, dy))
                {
                    vector<vector<char>> prev = grid;
                    placeWord(word, grid, row, col, dx, dy);  
                    if(backtrack(words, idx + 1, grid))
                    {
                        return true;
                    }
                    removeWord(word, grid, row, col, dx, dy, prev);
                }
            }
        }
    }
    return false;
}

vector<vector<char>> generateWordSearch(vector<string>& words)
{
    vector<vector<char>> grid(10, vector<char>(10, '.'));    
    for(string& word : words)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
    }
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });
    backtrack(words, 0, grid);
    srand(time(nullptr));
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(grid[i][j] == '.')
            {
                grid[i][j] = 'A' + (rand() % 26);
            }
        }
    }
    return grid;
}

int main()
{
    int n;
    cout << "Enter the number of words: ";
    cin >> n;
    cout << "Enter words: ";
    vector<string> words(n);
    for(int i=0; i<n; i++)
    {
        cin >> words[i];
    }
    auto result = generateWordSearch(words);
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
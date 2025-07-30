#include<bits/stdc++.h>

using namespace std;

void Transpose(vector<vector<int>>&a)
{
    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<3; j++)
        {
            swap(a[i][j], a[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> matrix(3, vector<int>(3));
    cout << "Enter Matrix elements: ";
    for(auto& row : matrix)
    {
        for(auto& element : row)
        {
            cin >> element;
        }
    }
    cout << "Matrix before transpose -> " << endl;
    for(const auto& row : matrix)
    {
        for(const auto& element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    Transpose(matrix);
    cout << "Matrix after transpose -> " << endl;
    for(const auto& row : matrix)
    {
        for(const auto& element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}
#include<bits/stdc++.h>

using namespace std;

float Determinant(vector<vector<int>>&a)
{
    return (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])) - (a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])) + (a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]));
}

void Cofactor(vector<vector<int>>&a, vector<vector<float>>&b)
{
    b[0][0] = a[1][1] * a[2][2] - a[1][2] * a[2][1];
    b[0][1] = a[1][2] * a[2][0] - a[1][0] * a[2][2];
    b[0][2] = a[1][0] * a[2][1] - a[1][1] * a[2][0];
    b[1][0] = a[0][2] * a[2][1] - a[0][1] * a[2][2];
    b[1][1] = a[0][0] * a[2][2] - a[0][2] * a[2][0];
    b[1][2] = a[0][1] * a[2][0] - a[0][0] * a[2][1];
    b[2][0] = a[0][1] * a[1][2] - a[0][2] * a[1][1];
    b[2][1] = a[0][2] * a[1][0] - a[0][0] * a[1][2];
    b[2][2] = a[0][0] * a[1][1] - a[0][1] * a[1][0];
}

void Transpose(vector<vector<float>>&b)
{
    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<3; j++)
        {
            swap(b[i][j], b[j][i]);
        }
    }
}

void Inverse(vector<vector<int>>&a, vector<vector<float>>&b)
{
    for(auto& row : b)
    {
        for(auto& element : row)
        {
            element = element/Determinant(a);
        }
    }
}

int main()
{
    vector<vector<int>> matrix(3, vector<int>(3));
    vector<vector<float>> inverse(3, vector<float>(3));
    cout << "Enter Matrix elements: ";
    for(auto& row : matrix)
    {
        for(auto& element : row)
        {
            cin >> element;
        }
    }
    cout << "Matrix: " << endl;
    for(const auto& row : matrix)
    {
        for(const auto& element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    if(Determinant(matrix) == 0)
    {
        cout << "The determinant of the given matrix is 0. The inverse matrix does not exists." << endl;
    }
    else
    {
        Cofactor(matrix, inverse);
        Transpose(inverse);
        Inverse(matrix, inverse);
        cout << "Inverse Matrix: " << endl;
        for(const auto& row : inverse)
        {
            for(const auto& element : row)
            {
                cout << element << " ";
            }
            cout << endl;
        }
    }
}
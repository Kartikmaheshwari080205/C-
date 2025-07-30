#include<bits/stdc++.h>
using namespace std;

float Discriminant(float A, float B, float C)
{
    return (B*B - 4*A*C);
}

int main()
{
    float A, B, C;
    cout << "Enter your values of A, B and C: ";
    cin >> A >> B >> C;
    cout << endl;

    if(A == 0)
    {
        cout << "Not a Quadratic Equation" << endl;
    }
    else
    {
        if(Discriminant(A, B, C) < 0)
        {
            cout << "Imaginary roots" << endl;
        }
        else if(Discriminant(A, B, C) == 0)
        {
            cout << "Equal roots: ";
            cout << B*(-1)/(2*A) << endl;
        }
        else
        {
            cout << "Distinct roots: ";
            cout << (B*(-1) - sqrt(Discriminant(A, B, C))) / (2*A) << " and " << (B*(-1) + sqrt(Discriminant(A, B, C))) / (2*A) << endl;
        }
        cout << "Discriminant: " << Discriminant(A, B, C) << endl;
        cout << "Sum of roots: " << B*(-1) / A << endl;
        cout << "Product of roots: " << C / A << endl;
    }
}
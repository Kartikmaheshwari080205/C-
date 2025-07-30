#include<bits/stdc++.h>
using namespace std;

int SolutionChecker(int a1, int b1, int c1, int a2, int b2, int c2)
{
    float epsilon = 1e-6;
    if(fabs(a1*b2 - a2*b1) > epsilon)
    {
        return 1;
    }
    if(fabs(a1*c2 - a2*c1) > epsilon || fabs(b1*c2 - b2*c1) > epsilon)
    {
        return 0;
    }
    return -1;
}

int main()
{
    float a1, a2, b1, b2, c1, c2;
    cout << "Enter your coefficients: ";
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    cout << endl;

    if(SolutionChecker(a1, b1, c1, a2, b2, c2) == 1)
    {
        float y = (a2*c1 - a1*c2)/(a1*b2 - a2*b1);
        float x = (c1*(-1) - b1*y)/a1;
        cout << "(" << x << "," << y << ")" << endl;
    }
    else if(SolutionChecker(a1, b1, c1, a2, b2, c2) == 0)
    {
        cout << "No Solution" << endl;
    }
    else if(SolutionChecker(a1, b1, c1, a2, b2, c2) == -1)
    {
        cout << "Infinite Solutions" << endl;
    }
}
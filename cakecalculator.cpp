#include<bits/stdc++.h>
using namespace std;

vector<int> CakeCalculator(int flour, int sugar)
{
    int cakes = min(flour / 100, sugar / 50);
    flour -= cakes * 100;
    sugar -= cakes * 50;
    return {cakes, flour, sugar};
}

int main()
{
    int flour, sugar;
    cout << "Enter amount of flour: ";
    cin >> flour;
    cout << "Enter amount of sugar: ";
    cin >> sugar;
    auto result = CakeCalculator(flour, sugar);
    cout << "Number of cakes: " << result[0] << endl;
    cout << "Remaining flour: " << result[1] << endl;
    cout << "Remaining sugar: " << result[2] << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int MinWaste(int flour, int sugar, int eggs)
{
    int minwaste = INT_MAX;
    int flourx = flour / 100;
    int sugary = sugar / 50;
    int eggy = eggs / 20;
    int x = min({flourx, sugary, eggy});
    for(int i=0; i<=x; i++)
    {
        int floury = (flour - i * 100) / 50;
        int sugary = (sugar - i * 50) / 100;
        int eggy = (eggs - i * 20) / 30;
        int j = min({floury, sugary, eggy});
        if(j < 0)
        {
            continue;
        }
        int remainingf = flour - i * 100 - j * 50;
        int remainings = sugar - i * 50 - j * 100;
        int remaininge = eggs - i * 20 - j * 30;
        cout << i << " " << j << " " << remainingf + remainings + remaininge << endl;
        minwaste = min(minwaste, remainingf + remainings + remaininge);
    }
    return minwaste;
}

int main()
{
    int flour, sugar, eggs;
    cin >> flour >> sugar >> eggs;

    cout << MinWaste(flour, sugar, eggs) << endl;
}
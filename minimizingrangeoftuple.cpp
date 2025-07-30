#include<bits/stdc++.h>
using namespace std;

vector<int> MinimizeRange(int n, vector<int>& A, vector<int>& B, vector<int>& C)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    int i=0, j=0, k=0;
    int mina = 0, minb = 0, minc = 0;
    int minrange = INT_MAX;
    while(i < n && j < n && k < n)
    {
        int minnum = min({A[i], B[j], C[k]});
        int maxnum = max({A[i], B[j], C[k]});
        int range = maxnum - minnum;
        if(range < minrange)
        {
            mina = A[i];
            minb = B[j];
            minc = C[k];
        }
        if(A[i] == minnum)
        {
            i++;
        }
        else if(B[j] == minnum)
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return {mina, minb, minc};
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> B[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> C[i];
    }

    vector<int> result = MinimizeRange(n, A, B, C);
    cout << result[0] << " " << result[1] << " " << result[2] << endl << "The minimum range of the given arrays is: " << *max_element(result.begin(), result.end()) - *min_element(result.begin(), result.end()) << endl;
}
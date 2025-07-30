//sorting

#include<bits/stdc++.h>

using namespace std;

vector<char> FindCommonElements(int a, int b, vector<char>& A, vector<char>& B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<char> commonelements;
    int i=0, j=0;
    while(i<a && j<b)
    {
        if(A[i] == B[j])
        {
            commonelements.push_back(A[i]);
            ++i;
            ++j;
        }
        else if(A[i] < B[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    return commonelements;
}

int main()
{
    int a,b;
    cout << "Enter the size of list A: ";
    cin >> a;
    vector<char> listA(a);
    cout << endl << "Enter the elements of list A: ";
    for(auto& element : listA)
    {
        cin >> element;
    }
    cout << endl << "Enter the size of list B: ";
    cin >> b;
    vector<char> listB(b);
    cout << endl << "Enter the elements of list B: ";
    for(auto& element : listB)
    {
        cin >> element;
    }

    if(a > 0 && b > 0)
    {
        vector<char> commonElements = FindCommonElements(a, b, listA, listB);
        cout << endl << "Common elements: ";
        for(auto& element : commonElements)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Enter valid size for lists." << endl;
    }
}
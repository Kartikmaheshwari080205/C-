#include<bits/stdc++.h>
using namespace std;

void MakeEqualLength(string& s, string& t)
{
    int n1 = s.size(), n2 = t.size();
    if(n1 < n2)
    {
        s = string(n2 - n1, '0') + s;
    }
    else if(n2 < n1)
    {
        t = string(n1 - n2, '0') + t;
    }
    return;
}

string Add(string a, string b)
{
    MakeEqualLength(a, b);
    int carry = 0;
    string result = "";
    for(int i = a.size() - 1; i>=0 ; i--)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if(carry)
    {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}

string Substract(string a, string b)
{
    MakeEqualLength(a, b);
    string result = "";
    int borrow = 0;
    for(int i = a.size() - 1; i>=0; i--)
    {
        int sub = (a[i] - '0') - (b[i] - '0') - borrow;
        if(sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result.push_back(sub + '0');
    }
    reverse(result.begin(), result.end());
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

string KaratSuba(string s, string t)
{
    MakeEqualLength(s, t);
    int n = s.size();
    if(n == 1)
    {
        return to_string((s[0] - '0') * (t[0] - '0'));
    }

    int mid = n/2;
    string a = s.substr(0, mid), b = s.substr(mid);
    string c = t.substr(0, mid), d = t.substr(mid);

    string ac = KaratSuba(a, c), bd = KaratSuba(b, d);
    string ab_cd = KaratSuba(Add(a, b), Add(c, d));
    string ad_bc = Substract(Substract(ab_cd, ac), bd);

    ac += string(2 * (n - mid), '0');
    ad_bc += string(n - mid, '0');

    string result = Add(Add(ac, ad_bc), bd);
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

int main()
{
    string a, b;
    cout << "Enter number 1: ";
    cin >> a;
    cout << "Enter number 2: ";
    cin >> b;

    cout << "The product of the numbers is: " << KaratSuba(a, b) << endl;
}
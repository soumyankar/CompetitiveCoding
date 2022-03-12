#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string s_reversed=s;
    reverse(s_reversed.begin(), s_reversed.end());
    if(s == s_reversed)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
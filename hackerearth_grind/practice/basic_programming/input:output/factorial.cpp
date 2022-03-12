#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i;
    long long int ans=1;
    for(i=1;i<=n;i++)
        ans = ans * i;

    cout << ans << "\n";
}

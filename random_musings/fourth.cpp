#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    long long int n,k,i,ans=0;
    cin >> n;
    cin >> k;
    long long int a[n];
    for(i=0;i<n;i++)
        cin >> a[i];

    while(k!=0)
    {
        ans+=a[ans%n];
        k--;
    }

    cout << ans << "\n";
    return 0;
}
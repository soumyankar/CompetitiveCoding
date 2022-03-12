#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,k,modulo;
    cin >> n >> k;
    long long int ans[k];
    long long int i;
    long long int strength = 0;
    for(i=0;i<k;i++)
        ans[i] = 0;
    long long int a[n];
    for(i=0;i<n;i++)
        cin >> a[i];

    for(i=0;i<n;i++)
    {
        modulo = a[i] % k;
        ans[modulo] ++;
    }

    for(i=0;i<k;i++)
    {
        if(ans[i]>1)
            strength+= ans[i]*(ans[i]-1);
    }

    cout << strength << "\n";
}
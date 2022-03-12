#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,r,k;
    int i,count=0;
    cin >> l >> r >> k;
    for(i=l;i<=r;i++)
    {
        if(i%k == 0)
            count++;
    }

    cout << count << "\n";
}
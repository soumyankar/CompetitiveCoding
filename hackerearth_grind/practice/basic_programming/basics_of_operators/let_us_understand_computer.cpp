#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Compute a power of two less than or equal to `n`
long long int findPreviousPowerOf2(long long int n)
{
    // initialize result by 1
    long long int k = 1;
    // double `k` and divide `n` in half till it becomes 0
    while (n >>= 1) {
        k = k << 1;    // double `k`
    }
    return k;
}


int main()
{
    int t;
    cin >> t;
    while(t--!=0)
    {
        long long int n,i=1;
        cin >> n;
        if(n==3)
        {
            cout << "2" << "\n";
            continue;
        }
        long long int ans=0;
        while(i<=sqrt(n))
        {
            i=i*2;
            if(n/i>=i/2)
                ans=n-n/i;
            else
                ans=(n-(i/2))+1;
        }
        cout << ans << "\n";
    }
    return 0;
}
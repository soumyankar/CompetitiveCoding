#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,l;
    cin >> l;
    cin >> n;
    while(n--!=0)
    {
        int w,h;
        cin >> w >> h;
        if(w < l || h < l)
        {
            cout << "UPLOAD ANOTHER" << "\n";
            continue;
        }
        if(w >= l && h >= l && w==h)
        {
            cout << "ACCEPTED" << "\n";
            continue;
        }
        cout << "CROP IT" << "\n";
        continue;
    }
}

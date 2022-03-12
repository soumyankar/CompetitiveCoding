#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main()
{
    int n,m;
    cin >> n;
    cin >> m;
    int a[n];
    int b[m];
    unordered_map <int,int> umap;
    int i;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        umap[a[i]]++;
    }
    for(i=0;i<m;i++)
        cin >> b[i];

    for(i=0;i<m;i++)
    {
        int curr=b[i];
        auto it = umap.find(curr);
        if(it != umap.end())
        {
            if(it->second!=0)
            {
                it->second = it->second - 1;
                continue;
            }
        }
        cout<<"No"<<endl;
        return 0;
    }
    cout <<"Yes"<<endl;
    return 0;
}
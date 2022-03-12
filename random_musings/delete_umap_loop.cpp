#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map <int,int> umap;
    umap.insert({1,5});
    umap.insert({2,5});
    umap.insert({3,5});
    umap.insert({4,10});
    umap.insert({5,50});
    umap.insert({1,10});
    umap.insert({2,15});
    umap.insert({6,45});

    int max_t = 15;
    for(auto it=umap.begin();it!=umap.end();)
    {
        if(it->second < max_t)
            it = umap.erase(it);
        else
            it++;
    }

    for(auto &x: umap)
        cout<< x.first << " " << x.second << "\n";

    return 0;
}
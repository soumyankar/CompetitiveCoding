#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    int maxSize;
    list <pair<int,int> > cache;
    unordered_map<int, list<pair<int,int> >::iterator> pos;
    LRUCache(int capacity) {
        maxSize=capacity;
    }
    
    int get(int key) {
        if(pos.find(key)!=pos.end())
        {
            auto curr=pos[key];
            int v=(*curr).second;
            cache.erase(curr);
            cache.push_front({key, v});
            pos[key]=cache.begin();
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(pos.find(key)!=pos.end())
        {
            cache.erase(pos[key]);
            pos.erase(key);
        }
        if(pos.size()==maxSize)
        {
            pos.erase(cache.back().first); //least used element
            cache.pop_back();
        }
        cache.push_front({key,value});
        pos[key]=cache.begin();
    }
};

int main()
{
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->get(1);    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->get(2);    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache->get(1);    // return -1 (not found)
    lRUCache->get(3);    // return 3
    lRUCache-> get(4);    // return 4
}

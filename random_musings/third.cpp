#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <functional>
#include <vector>

using namespace std;
template<typename T>
void print_queue(T q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}
int main()
{
    int q;
    cin >> q;
    vector<int> v;
    while(q!=0)
    {
        q--;
        // cout <<"queu1\n";
        // print_queue(pq);
        // cout<<"queu2\n";
        // print_queue(pq2);
        int curr,x,k,func,i=0;
        cin >> func;
        if(func==1)
        {
            cin >> curr;
            v.push(curr);
            sort(v.begin(), v.end());
            continue;
        }
        if(func==2)
        {
            cin >> x;
            cin >> k;
            if(v[v.size()-1]>=x)
            {
                if(v.size()<k)
                {
                    cout<<"-1\n";
                    continue;
                }
                cout<<v[v.size()-k]<<"\n";
                continue;
            }
            for(i=0;i<v.size();i++)
            {
                if(v[i]>=x)
                {
                    if(i<k)
                    {
                        cout<<"-1\n";
                        break;
                    }
                }
            }
        }

    }
    return 0;
}
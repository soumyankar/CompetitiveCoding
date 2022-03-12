#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    void trap(vector<int>& height) {
        int i=0,j,ans=0,water_trap=0;
        int len=height.size();
        while(i<len)
        {
            if(height[i]>0)
            {
                water_trap=0;
                for(j=i+1;j<len;j++)
                {
                    if(height[j]>=height[i])
                    {
                        cout<<"i="<<i<<endl;
                        cout<<"j="<<j<<endl;
                        cout<<"water_trap="<<water_trap<<endl;
                        ans+=water_trap;
                        i=j-1;
                        break;
                    }
                    water_trap+=height[i]-height[j];
                }
            }
            i++;
        }
        cout<<ans;
        // return ans;
    }
};

int main()
{
    Solution my_sol;
    static const int arr[] = {4,2,0,3,2,5};
    vector<int> ip(arr, arr + sizeof(arr) / sizeof(arr[0]) );
    my_sol.trap(ip);
}
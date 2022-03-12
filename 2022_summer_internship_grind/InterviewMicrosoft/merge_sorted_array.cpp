#include <iostream>

using namespace std;

int main()
{
    int nums1[]={1,2,3};
    int m=3;
    int nums2[]={2,5,6};
    int n=3;
    int nums3[m+n];
    int pn1=0,pn2=0,pn3=0;
    while(pn1<m && pn2<n)
    {
        if(nums1[pn1] <= nums2[pn2])
        {
            nums3[pn3++]=nums1[pn1++];
            continue;
        }
        if(nums2[pn2] < nums1[pn1])
            nums3[pn3++]=nums2[pn2++];
    }
    for(int i=0;i<m+n;i++)
        cout<<nums3[i]<<" ";
    cout<<endl;
    if(pn1!=m-1)
    {
        for(int i=pn1;i<m;i++)
            nums3[pn3++]=nums1[pn1++];
    }
    if(pn2!=n-1)
    {
        for(int i=pn2;i<n;i++)
            nums3[pn3++]=nums2[pn2++];
    }

    for(int i=0;i<m+n;i++)
        cout<<nums3[i]<<" ";
}
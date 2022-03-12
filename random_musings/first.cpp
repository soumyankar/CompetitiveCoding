#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
  int a[10];
  int i;
  for(i=0;i<10;i++)
    cin>>a[i];

  int k=3,j=0,curr;
  while(k!=0)
  {
    curr=a[j];
    j=curr;
    k--;
  }
  cout << curr <<endl;
}
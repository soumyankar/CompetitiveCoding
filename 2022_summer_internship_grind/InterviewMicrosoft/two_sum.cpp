#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int swap(const void* x, const void* y)
{
    const int* i = (int*)x;
    const int* j = (int*)y;

    if(*i >= *j)
        return 1;
    else
        return -1;

    return 0;
}

int main()
{
    int n = 5,i;
    int a[n];
    for(i=0;i<5;i++)
        cin >> a[i];
    qsort(a, n, sizeof(int), swap);
    for(i=0;i<n;i++)
        cout << a[i] << " ";

    cout << endl;
}
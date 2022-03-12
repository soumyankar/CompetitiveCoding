#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partitioning(int a[], int l, int h)
{
    int i,j;
    i = l;
    j = h;
    int pivot = a[l];
    while(i<j)
    {
        do{
            i++;
        }while(a[i]<=pivot);

        do{
            j--;
        }while(a[j]>pivot);

        if(a[i] < a[j])
            swap(a, i, j);
    }
    swap(a, l, j);
    return j;
}

void quick_sort(int a[], int l, int h)
{
    if(l<h)
    {
        int j = partitioning(a, l, h);
        quick_sort(a, l, j);
        quick_sort(a, j+1, h);
    }
}

int main()
{
    int n = 5,i;
    int a[n+1];
    for(i=0;i<5;i++)
        cin >> a[i];
    a[n] = 999999;lsl
    cout << endl << "------" << endl;
    quick_sort(a, 0, n);
    for(i=0;i<n;i++)
        cout << a[i] << " ";

    cout << endl;
}
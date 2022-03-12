#include <stdio.h>

int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int last = a[n-1];
    if(last%10 == 0)
        printf("Yes\n");
    else
        printf("No\n");
}
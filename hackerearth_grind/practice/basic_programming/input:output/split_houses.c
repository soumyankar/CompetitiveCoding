#include <stdio.h>

int main()
{
    int n,i;
    scanf("%d", &n);
    char a[n];
    for(i=0;i<n;i++)
        scanf(" %c",&a[i]);

    int longest_houses=0,temp=0;
    for(i=1;i<n;i++)
    {
        if(a[i]=='H')
        {
            if(a[i-1]=='H')
            {
                printf("NO\n");
                return 0;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(a[i]!='H')
            a[i]='B';
    }

    printf("YES\n");
    for(i=0;i<n;i++)
    {
        printf("%c",a[i]);
    }
}
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    long long int ans=1;
    for(i=0;i<n;i++)
    {
        ans = ans * a[i];
        ans = ans % (1000000000 + 7 ); // Module 10^9 + 7
    }

    printf("%lld\n", ans);
}
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t!=0)
    {
        int g,p;
        scanf("%d %d", &g, &p);
        int n;
        scanf("%d", &n);
        int a[n][2];
        int i,j;
        for(i=0;i<n;i++)
            scanf("%d %d", &a[i][0], &a[i][1]);
        int q1=0,q2=0;
        for(i=0;i<n;i++)
        {
            if(a[i][0]==1)
                q1++;
            if(a[i][1]==1)
                q2++;
        }

        int p1=q1*g+q2*p;
        int p2=q1*p+q2*g;
        if(p1>p2)
            printf("%d\n",p2);
        if(p2>=p1)
            printf("%d\n",p1);
        t--;
    }
}
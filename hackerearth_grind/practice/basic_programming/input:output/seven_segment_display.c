#include <stdio.h>

int getMatchSticks(int n)
{
    if(n==0)
        return 6;
    if(n==1)
        return 2;
    if(n==2)
        return 5;
    if(n==3)
        return 5;
    if(n==4)
        return 4;
    if(n==5)
        return 5;
    if(n==6)
        return 6;
    if(n==7)
        return 3;
    if(n==8)
        return 7;
    if(n==9)
        return 6;
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t!=0)
    {
        int n,i;
        scanf("%d",&n);
        int total_sticks = 0;
        if(n==0)
            total_sticks=6;
        else
        {
            while(n>0)
            {
                total_sticks += getMatchSticks(n%10);
                n /= 10;
            }
        }
        int ones=0;
        if(total_sticks%2 == 0)
        {
            ones=total_sticks/2;
            for(i=0;i<ones;i++)
                printf("1");
            printf("\n");
            t--;
            continue;
        }
        else
        {
            ones=total_sticks/2-1;
            for(i=0;i<ones;i++)
                printf("1");
            printf("7\n");
        }
        t--;
    }
}
#include <stdlib.h>
#include <stdio.h>
#define maxint(a,b) \
  ({int _a = (a), _b = (b); _a > _b ? _a : _b; })

int p[] = {2,3,5,1,4};
int total_bottles=5;
int cache[5][5]={0};

int maxProfit(int begin, int end)
{
    if(begin>end)
        return 0;
    if(cache[begin][end] != 0 )
        return cache[begin][end];
    int current_year = total_bottles - (end - begin +1) +1;
    return cache[begin][end] = maxint(
        maxProfit(begin+1,end) + current_year*p[begin],
        maxProfit(begin,end-1) + current_year*p[end]
        );
}

int main()
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            printf("%d ",cache[i][j]);
        printf("\n");
    }
    int profit = maxProfit(0,4);
    printf("%d\n",profit);
    return 0;
}
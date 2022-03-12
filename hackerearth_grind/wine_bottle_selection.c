#include <stdio.h>
#define maxint(a,b) \
  ({int _a = (a), _b = (b); _a > _b ? _a : _b; })

int p[] = {2,3,5,1,4};

int maxProfit(int year, int begin, int end)
{
    if(begin>end)
        return 0;
    else
    {
        return maxint(
            maxProfit(year+1,begin+1,end)+year*p[begin],
            maxProfit(year+1,begin,end-1)+year*p[end]
            );
    }
}

int main()
{
    int profit = maxProfit(1,0,4);
    printf("%d\n",profit);
    return 0;
}
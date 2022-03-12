#include <stdio.h>

int main()
{
    int i,n,j;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    int slice = 2;
    int best_sum = 0;
    int current_sum =0;
    int best_index = 0;
    for(i=0;i<n;i++)
    {
        current_sum=a[i];
        if((n-i-1)>slice)
        {
            best_index=i;
            for(j=i+1;j<i+slice+1;j++)
                current_sum+=a[j];
            slice++;
        }
        if(current_sum>best_sum)
            best_sum = current_sum;
    }
    printf("%d\n", best_sum);
    printf("%d\n", best_index);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int i=0;
    ptr=(int *)malloc(i*sizeof(int));
    for(i=1;i<=5;i++)
    {
        ptr=(int*)realloc(ptr, i*sizeof(int));
        scanf(" %d", &ptr[i]);
    }

    for(i=0;i<5;i++)
        printf("%d\n",ptr[i]);

    return 0;
}
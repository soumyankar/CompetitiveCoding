#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;
int main()
{
    int *ptr = malloc(sizeof(int));
    int n = 0;
    bool flag = true;
    while(flag)
    {
        int in;
        scanf("%d", ptr);
        // ptr = &in;
        printf("The number is = %d\n", *ptr);
        n++;
        if(n==3)
            flag=false;
    }
    return 0;
}
#include <stdio.h>

int main()
{
    char s[20];
    scanf("%s", s);
    int i,z=0,o=0;
    for(i=0;i<20;i++)
    {
        if(s[i]=='z' || s[i]=='Z')
            z++;
        if(s[i]=='o' || s[i]=='O')
            o++;
    }
    if(z*2!=o)
        printf("No\n");
    else
        printf("Yes\n");
}
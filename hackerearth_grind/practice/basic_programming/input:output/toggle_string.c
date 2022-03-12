#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[100];
    scanf("%s",s);
    int i;
    for(i=0;i<100;i++)
    {
        if(isupper(s[i]) > 0)
        {
            s[i]=tolower(s[i]);
            continue;
        }
        if(isupper(s[i]) == 0)
            s[i]=toupper(s[i]);
    }

    printf("%s\n",s);
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("# of arguments = %d\n", argc);
    int i;
    printf("The arguments are -->\n");
    for(i=1;i<argc;i++)
        printf("%s\n", argv[i]);

    return 0;
}
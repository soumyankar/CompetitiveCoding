#include <stdio.h>

int isVowel(char c)
{
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return 0;
    return 1;
}
// DDXDDD-DD
// 012345678
int main()
{
    char a[9];
    scanf("%s", a);
    int i;
    int first_digit = (int)a[0]-48;
    int second_digit = (int)a[1]-48;
    char letter = a[2];
    int third_digit = (int)a[3]-48;
    int fourth_digit = (int)a[4]-48;
    int fifth_digit = (int)a[5]-48;
    int sixth_digit = (int)a[7]-48;
    int seventh_digit = (int)a[8]-48;

    if((first_digit+second_digit)%2!=0)
    {
        printf("invalid\n");
        return 0;
    }
    if(isVowel(letter)!=1)
    {
        printf("invalid\n");
        return 0;
    }
    if((third_digit+fourth_digit)%2!=0)
    {
        printf("invalid\n");
        return 0;
    }
    if((fourth_digit+fifth_digit)%2!=0)
    {
        printf("invalid4\n");
        return 0;
    }
    if((sixth_digit+seventh_digit)%2!=0)
    {
        printf("invalid\n");
        return 0;
    }
    printf("valid\n");
    return 0;
}
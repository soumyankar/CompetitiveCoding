#include <stdio.h>
#include <math.h>

long long int firstDigit(long long int n)
{
    while(n>10)
        n/=10;

    return n;
}

long long int lastDigit(long long int n)
{
    return n%10;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    long long int i;
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    long long int new_number=0;
    for(i=0;i<n/2;i++)
        new_number=(firstDigit(a[i])*pow(10,n-i-1))+new_number;

    for(i=n/2;i<n;i++)
        new_number=(lastDigit(a[i])*pow(10,n-i-1))+new_number;

    if(new_number%11==0)
        printf("OUI");
    else
        printf("NON");
}
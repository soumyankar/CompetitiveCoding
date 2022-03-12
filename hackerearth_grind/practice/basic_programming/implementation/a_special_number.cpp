#include <iostream>

using namespace std;

long long int sumOfDigits(int n)
{
    long long int ans=0;
    while(n!=0)
    {
        ans+=n%10;
        n/=10;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while(t--!=0)
    {
        long long int n,flag,i;
        cin >> n;
        for(i=n; ;i++)
        {
            flag = sumOfDigits(i) % 4;
            if(flag == 0)
            {
                cout << i << "\n";
                break;
            }
        }
    }
}
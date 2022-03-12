// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<string>
#include <algorithm>
using namespace std;

string solution(int A, int B, int C) {
    // write your code in C++14 (g++ 6.2.0)
    // Define the ans string
    string ans;
    // We begin the iteration by checking if anny of the A,B,Cs are nnot yet 0. In other words, we still have characters to append.
    while(A!=0 || B!=0 || C!=0)
    {
        // Check if A is greatest number.
        if(A>=B && A>=C)
        {
            int len=ans.length();
            // Check if previous char is 'a' or otherwise previous to previous char is 'a'. This helps us understand if we are going to violate the 'aaa' rule.
            if(len>=2)
            {
                if(ans[len-2]!='a' || ans[len-1]!='a')
                {
                    ans+='a';
                    A--;
                }
            }
            else if(len<2)
            {
                ans+='a';
                A--;
            }
            else
            {
                if(B>C)
                {
                    ans+='b';
                    B=B-1;
                }
                else if(C>0)
                {
                    ans+='c';
                    C=C-1;
                }
                // If all of the checks fail, that meanns that B and C have been entirely deplted and we should return.
                else 
                {
                    return ans;
                }
            }
        }
        // Now we repeat more or less the smae approach for B.
        else if(B>=A && B>=C)
        {
            int len=ans.length();
            if(len>=2)
            {
                if(ans[len-2]!='b' || ans[len-1]!='b')
                {
                    ans+='b';
                    B--;
                }
            }
            else if(len<2)
            {
                ans+='b';
                B--;
            }
            else{
                if(C>A)
                {
                    ans+='c';
                    C--;
                }
                else if(A>0)
                {
                    ans+='a';
                    A--;
                }
                else {
                return ans;
                }
            }
        }
        // Finally to check the same conditions for C
        else {
            int len=ans.length();
        if(len>=2)
        {
            if(ans[len-2]!='c' || ans[len-1]!='c')
            {
                ans+='c';
                C--;
            }
        }
        else if(len<2)
        {
            ans+='c';
            C--;
        }
        // Check if the other letter counts have been delpted
        else {
            if(A>B)
            {
                ans+='a';
                A--;
            }
            else if(B>0)
            {
                ans+='b';
                B--;
            }
            else{
                return ans;
            }
            }

            }
        }
        return ans;
}

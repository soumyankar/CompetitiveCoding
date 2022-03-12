#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wildcardPatternMatch(string s,string p)
    {
        bool match_matrix[s.length()+1][p.length()+1];
        match_matrix[0][0]=true;
        int i,j;

        // Must first fill in the 0-th Row
        for(i=1;i<=p.length();i++)
        {
            if(p[i-1]=='*')
                match_matrix[0][i]=true;
        }

        // Must start fillinng in this 2d mmatrix in bottom-up fashion
        for(i=1;i<=s.length();i++)
        {
            for(j=1;j<=p.length();j++)
            {
                // Case1: pattern matches strinng char
                if(p[j-1]=='*')
                {
                    if(match_matrix[i][j-1] ==true || match_matrix[i-1][j]==true)
                        match_matrix[i][j]=true;
                }
                if(p[j-1]=='?' || s[i-1]==p[j-1])
                {
                    if(match_matrix[i-1][j-1]==true)
                        match_matrix[i][j]=true;
                }
            }
        }
        return match_matrix[s.length()][p.length()];
    }
};

int main()
{
    Solution my_sol;
    cout<< my_sol.wildcardPatternMatch("aab","c*a*b") << "\n";

    return 0;
}
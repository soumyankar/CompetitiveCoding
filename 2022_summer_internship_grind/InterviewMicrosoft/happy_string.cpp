class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
            // write your code in C++14 (g++ 6.2.0)
    // Define the ans string
        // Changing parameters to smaller case for better writinng ability
        int a=A;
        int b=B;
        int c=C;
        string ans="";
            // We begin the iteration by checking if anny of the A,B,Cs are nnot yet 0. In other words, we still have characters to append.
        // Check if A is greatest number.
        while(a!=0 || b!=0 || c!=0){
            // Check if previous char is 'a' or otherwise previous to previous char is 'a'. This helps us understand if we are going to violate the 'aaa' rule.
            if(a>=b && a>=c){                  // Max value is a
                if(ans.size()>=2 && (ans[ans.size()-2]!='a' || ans[ans.size()-1]!='a')){
                    ans+='a';
                    a--;
                } else if(ans.size()<2){
                    ans+='a';
                    a--;
                }
                else{                                // Choosing Max from b and c
                    if(b>c){
                        ans+='b';
                        b--;
                    } else if(c>0){
                        ans+='c';
                        c--;
                    } else                            // If both b and c becomes 0 then we return
                        return ans;
                }
                  // If all of the checks fail, that meanns that B and C have been entirely deplted and we should return.
            } else if(b>=a && b>=c){
                if(ans.size()>=2 && (ans[ans.size()-2]!='b' || ans[ans.size()-1]!='b')){
                    ans+='b';
                    b--;
                } else if(ans.size()<2){
                    ans+='b';
                    b--;
                }
                else{
                    if(c>a){
                        ans+='c';
                        c--;
                    } else if(a>0){
                        ans+='a';
                        a--;
                    } else
                        return ans;
                }
            } else {
                if(ans.size()>=2 && (ans[ans.size()-2]!='c' || ans[ans.size()-1]!='c')){
                    ans+='c';
                    c--;
                } else if(ans.size()<2){
                    ans+='c';
                    c--;
                }else{
                    if(a>b){
                        ans+='a';
                        a--;
                    } else if(b>0){
                        ans+='b';
                        b--;
                    }  else
                        return ans;
                }
            }
        }
        return ans;
    }
};
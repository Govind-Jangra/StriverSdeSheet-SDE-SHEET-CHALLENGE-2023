// https://leetcode.com/problems/count-and-say/


#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string t=countAndSay(n-1);
        string ans="";
        int c=1;
        char old=t[0];
        for(int i=1;i<t.size();i++){
            if(t[i]!=t[i-1]){
                ans+=to_string(c)+t[i-1];
                old=t[i];
                c=1;

            }
            else c++;
        }
         ans+=to_string(c)+old;
         return ans;
    }
};
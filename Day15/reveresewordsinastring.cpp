// https://leetcode.com/problems/reverse-words-in-a-string/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string t="";
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=' ') t+=s[i];
            else {
                if(t!="")
                ans=t+" "+ans;
                t="";
            }
            i++;
        }
        if(t!="") ans=t+" "+ans;
        ans.erase(ans.size()-1,1);
        return ans;
    }
};
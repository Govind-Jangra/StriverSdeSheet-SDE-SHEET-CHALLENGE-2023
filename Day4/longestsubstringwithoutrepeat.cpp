// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,n=(int)s.size();
       unordered_map<char,int> m;
       
       for(int i=0,j=0;j<n;j++){
           if(m[s[j]]>0){
               i=max(i,m[s[j]]);
           }

           ans=max(ans,j-i+1);
           m[s[j]]=j+1;
       }
       return ans;

    }
};
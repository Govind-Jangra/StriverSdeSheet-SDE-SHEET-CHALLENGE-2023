// https://leetcode.com/problems/longest-common-prefix/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string prev=s[0];
        int n=s.size();
        for(int i=1;i<n;i++){
            string temp="";
            int x=0;
            while(x<s[i].size() && x<prev.size() && prev[x]==s[i][x]){
                temp+=prev[x];
                x++;
            }
            prev=temp;
        }
        return prev;
    }
};
// https://leetcode.com/problems/palindrome-partitioning/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool ispalindrome(string s,int st,int end){
        while(st<end){
            if(s[st++]!=s[end--]) return 0;
        }
        return 1;
    }
    void solve(int i,string s,vector<string> &temp,vector<vector<string>> &ans){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int idx=i;idx<s.size();idx++){
            if(ispalindrome(s,i,idx)){
                temp.push_back(s.substr(i,idx-i+1));
                solve(idx+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,temp,ans);
        return ans;
    }
};
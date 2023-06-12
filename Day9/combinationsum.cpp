// https://leetcode.com/problems/combination-sum/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     void solve(int i,int n,vector<int> &a,vector<int> &temp, vector<vector<int>> &ans){
        if(i==a.size()|| n==0){
            
           if(n==0)
            ans.push_back(temp);
            
            return;
        }
        
        // for(int i=0;i<a.size();i++){
        //     if(n>=a[i]){
        
        if(n>=a[i]){
                temp.push_back(a[i]);
                solve(i,n-a[i],a,temp,ans);
                temp.pop_back();
        } else return;
     solve(i+1,n,a,temp,ans);
            // }
        // }
    }
    vector<vector<int>> combinationSum(vector<int>& A, int n) {
        vector<vector<int>> ans;
        sort(A.begin(),A.end());
        
        vector<int> temp;
        solve(0,n,A,temp,ans);
        return ans;
    }
};
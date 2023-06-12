// https://leetcode.com/problems/subsets-ii/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int i,int n,vector<int> temp,vector<int>& nums
    , vector<vector<int>> &ans){
       
            ans.push_back(temp);
          
        for(int idx=i;idx<n;idx++){
            if(idx!=i && nums[idx]==nums[idx-1]) continue;
            temp.push_back(nums[idx]);
        solve(idx+1,n,temp,nums,ans);
        temp.pop_back();
        }
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        vector<int> temp;
        solve(0,nums.size(),temp,nums,ans);
        return  ans;
    }
};
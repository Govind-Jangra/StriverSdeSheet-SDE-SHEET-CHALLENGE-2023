// https://leetcode.com/problems/two-sum/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<pair<int,int>>nums;
    for(int i=0;i<arr.size();i++){
        nums.push_back({arr[i],i});
    }
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i].first+nums[j].first==target){
                ans.push_back(nums[i].second);
                ans.push_back(nums[j].second);
                return ans;
            }
            else if(nums[i].first+nums[j].first>target)
            j--;

            else
            i++;
        }
            return ans;
    }
};
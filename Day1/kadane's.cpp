// https://leetcode.com/problems/maximum-subarray/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
   
        int curr=nums[0];
        int sum=nums[0];
        if(curr<0) curr=0;
        for(int i=1;i<nums.size();i++){
            curr+=nums[i];
            if(curr>sum) sum=curr;
            if(curr<0) curr=0;

        }
        return sum;
    }
};
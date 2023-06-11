// https://leetcode.com/problems/max-consecutive-ones/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int c=nums[0]==1?1:0;
        int ans=c;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1 && nums[i-1]==1) c++;
            else c=nums[i]==1?1:0;
            ans=max(ans,c);
        }
        return ans;
    }
};
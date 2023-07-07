// https://leetcode.com/problems/maximum-product-subarray/



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p1=nums[0];
        int p2=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int t=max({nums[i],nums[i]*p1,nums[i]*p2});
            p2=min({nums[i],nums[i]*p1,nums[i]*p2});
            p1=t;
            ans=max(ans,p1);
        }
        return ans;
    }
};
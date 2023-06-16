// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int i=0,j=nums.size()-1;
        while(i<=j){
            int m=(i+j)/2;
            if(nums[m]==target) return m;
            if(nums[i]<=nums[m]){
             

                if(nums[i]<=target &&nums[m]>=target) j=m-1;
                else i=m+1;
            }

            else{
             

                 if(nums[m]<=target && target<=nums[j]) i=m+1;
                else j=m-1;
            }
        }
      return -1;
        
    }
};
// https://leetcode.com/problems/single-element-in-a-sorted-array/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int n=nums.size();
        while(i<=j){
            int m=(i+j)/2;
            int first=m;
            if(m+1<n && nums[m]==nums[m+1]) first=m;
            else if(m-1>=0 && nums[m]==nums[m-1]) first=m-1;
            else return nums[m];

            if(first%2==0) i=m+1;
            else j=m-1;
        }
        return -1;
    }
};
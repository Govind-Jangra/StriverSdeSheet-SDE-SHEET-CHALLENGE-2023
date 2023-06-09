// https://leetcode.com/problems/majority-element/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=-1;
        int freq=0;
        for(int i=0;i<nums.size();i++){
            if(freq==0){ maj=nums[i];
            freq++;
            }
            else{
                if(maj==nums[i]){
                    freq++;
                }
                else{
                    freq--;
                    if(freq==0) maj=nums[i];
                }
            }
        }
        return maj;
    }
};
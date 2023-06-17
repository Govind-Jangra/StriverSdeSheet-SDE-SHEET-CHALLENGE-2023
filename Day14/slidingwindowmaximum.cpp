// https://leetcode.com/problems/sliding-window-maximum/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        vector<int> ans;
        
        for(int i=0;i<k;i++){
            st.insert(nums[i]);
        }
        auto it=st.end();
        it--;
        ans.push_back(*it);
        
        for(int i=k;i<nums.size();i++){
            st.insert(nums[i]);
                auto it2=st.find(nums[i-k]);
                st.erase(it2);
                auto it1=st.rbegin();
        
        ans.push_back(*it1);
        }
        return ans;
    }
};
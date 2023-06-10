// https://leetcode.com/problems/longest-consecutive-sequence/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i:nums){
            st.insert(i);

        }
        int ans=0;
        int c=0;
        for(auto i:nums){
            if(st.count(i-1)==0){
                int curr=i;
                 c=1;
                while(st.count(curr+1)>0){
                    curr++;;
                    c++;
                }
            }
            ans=max(ans,c);
        }
        return ans;
    }
};
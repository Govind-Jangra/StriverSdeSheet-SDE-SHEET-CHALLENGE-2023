// https://leetcode.com/problems/next-greater-element-i/


#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int maxx=nums2[0];
        for(int i=1;i<nums2.size();i++) maxx=max(maxx,nums2[i]);
         stack<int> s;
         
         vector<int> next(maxx+1,0);
        for(int i=0;i<nums2.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else {
                while(!s.empty() && nums2[s.top()]<nums2[i]){
                   
                    next[nums2[s.top()]]=nums2[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            
            next[nums2[s.top()]]=-1;
            s.pop();
        }
      vector<int> ans(nums1.size());
      for(int i=0;i<nums1.size();i++){
          ans[i]=next[nums1[i]];
      }
    return ans;
    }
};
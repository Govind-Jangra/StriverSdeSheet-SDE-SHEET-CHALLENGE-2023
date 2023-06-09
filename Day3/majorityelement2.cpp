// https://leetcode.com/problems/majority-element-ii/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
          int f1=0,m1=0,f2=0,m2=1;
          for(auto i:nums){
              if(i==m1) f1++;

              else if(i==m2) f2++;

              else if(f1==0) {
                  f1=1;
                  m1=i;
              }

              else if(f2==0){
                  f2=1;
                  m2=i;
              }
              else{
                  f1--;
                  f2--;
              }
          }
          vector<int> ans;
          int c1=0,c2=0;
          for(auto i:nums){
              if(i==m1) c1++;
              if(i==m2) c2++;
          }
          if(c1>n/3) ans.push_back(m1);
           if(c2>n/3) ans.push_back(m2);
           return ans;

    }
};
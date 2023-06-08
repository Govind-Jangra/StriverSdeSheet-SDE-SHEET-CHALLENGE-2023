// https://leetcode.com/problems/merge-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int c=m-1;
        for(int i=m+n-1;i>=n;i--){
            nums1[i]=nums1[c--];
        }
        // for(auto i:nums1){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int i=n,j=0;
         c=0;
        while(i<m+n || j<n){
            if(i<m+n && j<n && nums1[i]<nums2[j]){
                nums1[c++]=nums1[i];
                i++;
            }
            else if(i<m+n && j<n && nums1[i]>=nums2[j]){
                  nums1[c++]=nums2[j];
                j++;
            }
            else if(i<m+n){
                nums1[c++]=nums1[i];
                i++;
            }
            else if(j<n){
                nums1[c++]=nums2[j];
                j++;
            }
        }

    }
};
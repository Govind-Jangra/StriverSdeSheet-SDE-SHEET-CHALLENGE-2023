// https://leetcode.com/problems/trapping-rain-water/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        int ans=0;
        int i=0,j=n-1;
        int lmax=0,rmax=0;
        while(i<=j){
            if(a[i]<=a[j]){
                if(a[i]>=lmax) lmax=a[i];
                ans+=lmax-a[i];
                i++;
            }
            else{
                 if(a[j]>=rmax) rmax=a[j];
                ans+=rmax-a[j];
                j--;
            }
        }
        return ans;
    }

};
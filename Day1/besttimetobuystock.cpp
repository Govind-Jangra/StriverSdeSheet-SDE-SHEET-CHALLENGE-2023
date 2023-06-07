// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    int maxProfit(vector<int>& arr) {
        int ans=0,minn=INT_MAX;
        for(int i=0;i<arr.size();i++){
            minn=min(minn,arr[i]);
            ans=max(ans,arr[i]-minn);
        }
        return ans;
    }
};
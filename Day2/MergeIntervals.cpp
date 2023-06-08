// https://leetcode.com/problems/merge-intervals/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        ans.push_back(a[0]);
        int index=0;
        for(int i=1;i<a.size();i++){
            if(ans[index][1]>=a[i][0]){
                ans[index][1]=max(a[i][1],ans[index][1]);
            }
            else{
                index++;
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        for(int i=1;i<n;i++){
            a[i]+=a[i-1];
        }
        unordered_map<int,int> m;
        int ans=0;

        for(int i=0;i<n;i++){
            if(a[i]==0) ans=max(ans,i+1);
            if(m.find(a[i])==m.end()){
                
                m[a[i]]=i;
            }
            else ans=max(i-m[a[i]],ans);
        }
        return ans;
    }
};
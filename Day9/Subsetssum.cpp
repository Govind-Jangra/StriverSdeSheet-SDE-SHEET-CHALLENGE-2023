// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int i,int sum,vector<int> arr, int N,vector<int>& ans){
        if(i==N){
            ans.push_back(sum);
            return;
        }
        solve(i+1,sum+arr[i],arr,N,ans);
        solve(i+1,sum,arr,N,ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        solve(0,0,arr,N,ans);
        return ans;
    }
};
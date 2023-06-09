// https://leetcode.com/problems/unique-paths/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int solve(int i,int j,int n,int m,vector<vector<int>> &dp){
    //     if(i==n-1 && j==m-1) return 1;
    //     if(i>=n || j>=m) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     return dp[i][j]=solve(i+1,j,n,m,dp)+solve(i,j+1,n,m,dp);
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    //     return solve(0,0,m,n,dp);
    // }



    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, 1));
    //     for (int i = 1; i < m; i++) {
    //         for (int j = 1; j < n; j++) {
    //             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //         }
    //     }
    //     return dp[m - 1][n - 1];
    // } 



int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }


    
};
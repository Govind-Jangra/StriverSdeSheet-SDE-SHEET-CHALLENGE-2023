// https://leetcode.com/problems/edit-distance/


class Solution {
public:
    int solve(int i,int j,string &a,string &b,vector<vector<int>> &dp)
    {
        if(i<0 ) return max(0,1+j);
        if(j<0) return max(0,i+1);
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        if(a[i]==b[j])
         ans=min(ans,solve(i-1,j-1,a,b,dp));
         ans=min(ans,1+solve(i,j-1,a,b,dp));
         ans=min(ans,1+solve(i-1,j,a,b,dp));
         ans=min(ans,1+solve(i-1,j-1,a,b,dp));
         return dp[i][j]=ans;

    }
    int minDistance(string &word1, string &word2) {
        int n=word1.size();

        int m=word2.size();
        vector<vector<int>> dp(n+2,vector<int>(m+2,-1));
     return solve(word1.size()-1,word2.size()-1,word1,word2,dp);   
    }
};
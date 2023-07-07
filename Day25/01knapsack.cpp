// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

 int solve(int i,int W, int wt[], int val[], int n,vector<vector<int>> &dp)
    {
        
        if(i==n-1){
            if(W>=wt[i]) return val[i];
            return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int t=0,nt=0;
        if(W>=wt[i]) t=val[i]+solve(i+1,W-wt[i],wt,val,n,dp);
        nt=solve(i+1,W,wt,val,n,dp);
        return dp[i][W]=max(t,nt);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
       return solve(0,W,wt,val,n,dp);
    }
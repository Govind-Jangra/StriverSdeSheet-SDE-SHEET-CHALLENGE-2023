// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1


class Solution{
		

	public:
	 int solve(int index,int n,int a[],int prev,   vector<vector<int>> &dp){
        if(index==n) return 0;
        if( dp[index][prev+1]!=-1) return  dp[index][prev+1];
        int notetake=solve(index+1,n,a,prev,dp);
        int take=INT_MIN;
       
            if(prev==-1|| a[index]>a[prev]){
            take=a[index]+solve(index+1,n,a,index,dp);
        
        }
        return dp[index][prev+1]=max(take,notetake);
        
    }
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int prev=INT_MIN;
       
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return solve(0,n,a,-1,dp);
	}  
};
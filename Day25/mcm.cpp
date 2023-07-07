// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1


// User function Template for C++

class Solution{
public:
int solve(int i,int j,int arr[], vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int sum=arr[i-1]*arr[k]*arr[j] + solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
        ans=min(ans,sum);
    }
    return dp[i][j]=ans;
}
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,0));
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                  int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int sum=arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j];    
        ans=min(ans,sum);
    }
     dp[i][j]=ans;
            }
        }
        return dp[1][N-1];  
    }
};
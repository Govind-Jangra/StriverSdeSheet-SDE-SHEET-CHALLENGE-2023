// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include<bits/stdc++.h>
using namespace std;
class Solution{

	public:
	int solve(int i,int x,int n,int arr[],vector<int> &dp){
  if(x==0) return 0;
  if(i>=n || x<0) return 1e9;
  if(dp[x]!=-1) return dp[x];
  int t=1+solve(i,x-arr[i],n,arr,dp);
  int nt=solve(i+1,x,n,arr,dp);
  return dp[x]=min(t,nt);

}
	int minCoins(int arr[], int n, int x) 
	{ 
	    // Your code goes here
	    sort(arr,arr+n);
vector<int> dp(x+1,-1);
int ans=solve(0,x,n,arr,dp);
if(ans==1e9) return -1;
else
return ans;
	} 
};
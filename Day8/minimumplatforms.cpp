// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int ans=0;
    	int c=0;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0,j=0;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        ans++;
    	        i++;
    	    }
    	    else{
    	        j++;
    	        ans--;
    	        
    	    }
    	    c=max(ans,c);
    	    
    	}
    	return c;
    }
};

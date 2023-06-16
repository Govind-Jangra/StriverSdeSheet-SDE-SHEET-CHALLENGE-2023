// https://practice.geeksforgeeks.org/problems/aggressive-cows/0
#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> &arr,int c,int limit){
    int cows=1;
    int start=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-start>=limit){
            cows++;
            start=arr[i];
            if(cows>=c) return 1;
        }
    }
   
    return 0;
}
    int solve(int n, int c, vector<int> &arr) {
    sort(arr.begin(),arr.end());
        // Write your code here
        int ans=-1;
int i=1,j=arr[arr.size()-1];
while(i<=j){
    int m=(i+j)/2;
    if(ispossible(arr,c,m)){
        i=m+1;
        ans=m;
    } 
    else j=m-1;
}
return ans;
    }
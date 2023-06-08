// https://leetcode.com/problems/rotate-image/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++){
            int j=0,k=m-1;
            while(j<k){
                swap(a[i][j++],a[i][k--]);
            }
        }
       

        for(int i=0;i<n;i++){
            for(int j=0;j<m-i-1;j++){
                swap(a[i][j],a[n-j-1][m-i-1]);
            }
        }
    }
};
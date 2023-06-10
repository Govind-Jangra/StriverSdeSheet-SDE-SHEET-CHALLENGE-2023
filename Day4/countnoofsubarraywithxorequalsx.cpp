// https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &a, int k)
{
    //    Write your code here.
      int n = a.size(); 
    int xr = 0;
    map<int, int> m; 
    m[xr]++; 
    int ans = 0;
    //x^k==xr using this quation easily find out
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];

      
        int x = xr ^ k;

       
        ans += m[x];

   
        m[xr]++;
    }
    return ans;
}
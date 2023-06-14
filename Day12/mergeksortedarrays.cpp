// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379


#include<bits/stdc++.h>
using namespace std; 
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      vector<int> idx(k,0);
      for(int i=0;i<k;i++){
          pq.push({arr[i][0],i});
      }     
        while(!pq.empty()){
            pair<int,int> x=pq.top();
            pq.pop();
            ans.push_back(x.first);
            
            if(idx[x.second]+1<arr[x.second].size())
            pq.push({arr[x.second][idx[x.second]+1],x.second});
            
            
            idx[x.second]+=1;
        }
        return ans;

}

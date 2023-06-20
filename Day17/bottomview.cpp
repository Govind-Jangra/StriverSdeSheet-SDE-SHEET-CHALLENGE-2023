// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


//Function to return a list containing the bottom view of the given tree.
#include<bits/stdc++.h>
using namespace std;


  struct Node {
      int data;
     Node *left;
      Node *right;
   
  };
class Solution {
  public:
  void solve(Node *root,int hd,int l,map<int,pair<int,int>> &m){
      if(root==NULL) return ;
     if(m.find(hd)==m.end() || l>=m[hd].second){
         m[hd]={root->data,l};
     }
      solve(root->left,hd-1,l+1,m);
     
      solve(root->right,hd+1,l+1,m);
      
      
    
      
  }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int,pair<int,int>> m;
        int n=m.size();
        
        solve(root,0,0,m);
       
        for(auto i:m){
            ans.push_back(i.second.first);
        }
        return ans;
    }
    
};
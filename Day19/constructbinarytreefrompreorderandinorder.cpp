// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode * solve(vector<int>& in,int x,int y,vector<int>& pre,int &p,
    int n,unordered_map<int,int> &m){
        if(p>=n || x>y ) return NULL;
       
        int find=pre[p++];
        int findin;
       
               findin=m[find];
              
       
        TreeNode *root=new TreeNode(find);
        
        
        root->left=solve(in,x,findin-1,pre,p,n,m);
        
      
        root->right=solve(in,findin+1,y,pre,p,n,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int i=0;
        unordered_map<int,int> m;
        int n=pre.size();
        for(int i=0;i<n;i++){
            m[in[i]]=i;
            
        }
        
        return solve(in,0,n-1,pre,i,n,m);
    }
};
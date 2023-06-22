// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
TreeNode * solve(vector<int>& in,int x,int y,vector<int>& postorder,int &p,
    int n,unordered_map<int,int> &m){
        if(p<0 || x>y ) return NULL;
       
        int find=postorder[p--];
        int findin;
       
               findin=m[find];
              
       
        TreeNode *root=new TreeNode(find);
        
         
        root->right=solve(in,findin+1,y,postorder,p,n,m);
        root->left=solve(in,x,findin-1,postorder,p,n,m);
        
     
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& postorder) {
        int i=0;
        unordered_map<int,int> m;
        int n=postorder.size();
        for(int i=0;i<n;i++){
            m[in[i]]=i;
            
        }
        i=n-1;
        return solve(in,0,n-1,postorder,i,n,m);
    }
};
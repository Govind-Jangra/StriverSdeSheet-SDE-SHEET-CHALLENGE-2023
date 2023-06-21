// https://leetcode.com/problems/balanced-binary-tree/
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
    bool solve(TreeNode* root,int &h){
        if(root==NULL) return 1;
        int lh=0,rh=0;
        bool l=solve(root->left,lh);
        bool r=solve(root->right,rh);
        h=max(1+lh,1+rh);
      
        return abs(lh-rh)<=1 &l&r;
    }
    bool isBalanced(TreeNode* root) {
        int height=0;
        return solve(root,height);
    }
};
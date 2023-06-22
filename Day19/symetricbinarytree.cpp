// https://leetcode.com/problems/symmetric-tree/

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}a
 * };
 */
class Solution {
public:
    bool solve(TreeNode* a,TreeNode* b){
        if(a==NULL && b==NULL) return 1;
        if(a==NULL || b==NULL) return 0;
        if(a->val!=b->val) return 0;
        return solve(a->left,b->right) & solve(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return 1;
        return solve(root->left,root->right);
    }
};
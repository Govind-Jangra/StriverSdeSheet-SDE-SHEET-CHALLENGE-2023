// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
       if(p->val<root->val && q->val>root->val) return root;
       else if(p->val>root->val && q->val<root->val) return root;
       else if(p->val==root->val || q->val==root->val) return root;
       if(p->val<root->val ) return lowestCommonAncestor(root->left,p,q);
       return lowestCommonAncestor(root->right,p,q);
       
    }
};
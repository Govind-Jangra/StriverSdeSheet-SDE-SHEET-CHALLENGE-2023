// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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

    // TreeNode* insert(TreeNode* root,int k){
    //     if(root==NULL) {
    //         return new TreeNode(k);
    //     }
    //     if(root->val<k){
    //         root->right=insert(root->right,k);
    //     }
    //     else root->left=insert(root->left,k);
    //     return root;
    // }
    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     TreeNode* ans=new TreeNode(preorder[0]);
    //     for(int i=1;i<preorder.size();i++){
    //         ans=insert(ans,preorder[i]);
    //     }
    //     return ans;
    // }


    int idx = 0;
    TreeNode *bstFromPreorder(vector<int> &preorder, int parent = INT_MAX)
    {
        if (idx == preorder.size() || preorder[idx] > parent)
            return NULL;
        int curr = preorder[idx++];
        TreeNode *root = new TreeNode(curr);
        root->left = bstFromPreorder(preorder, curr);
        root->right = bstFromPreorder(preorder, parent);
        return root;
    }
};
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
// pair<TreeNode*, TreeNode*> solve(TreeNode* root) {
//     if (root == NULL) return { NULL, NULL };
//     if (root->left == NULL && root->right == NULL) return { root, root };
//     auto l = solve(root->left);
//     auto r = solve(root->right);
//     if (root->left && root->right) {
//         root->right = l.first;
//         l.second->right = r.first;
//         root->left = NULL;  // Set root->left to NULL
//         r.second->right = NULL;
//         return { root, r.second };
//     }
//     else if (root->left) {
//         root->right = l.first;
//         root->left = NULL;  // Set root->left to NULL
//         return { root, l.second };
//     }
//     else {
//         root->right = r.first;
//         root->left = NULL;  // Set root->left to NULL
//         return { root, r.second };
//     }
// }

// void flatten(TreeNode* root) {
//     auto ans = solve(root);
// }


        TreeNode * prev = NULL;
  public:
    void flatten(TreeNode * root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }
};
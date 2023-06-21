// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
  vector<vector<int>> ans;

void solve(TreeNode *root, int l)
{
    if(root == NULL) return;
    if(ans.size() == l)
        ans.push_back(vector<int>());
    
    ans[l].push_back(root->val);
    solve(root->left, l + 1);
    solve(root->right, l + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    solve(root, 0);
    return  ans;
}
};
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    void solve(TreeNode* root,map<int,
    map<int,multiset<int>>> &m,
    int hd,int l){
        if(root==NULL) return ;
        m[hd][l].insert(root->val);
        solve(root->left,m,hd-1,l+1);
        solve(root->right,m,hd+1,l+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        solve(root,m,0,0);
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> temp;
            for(auto it:i.second){
                for(auto x:it.second)
                temp.push_back(x);

            }
            ans.push_back(temp);
        }
        return ans;
    }
};
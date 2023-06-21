// https://leetcode.com/problems/diameter-of-binary-tree/
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
int Diameter(TreeNode* root,int &height){
       if(root==NULL){
           
           return 0;
       }
       
       int ldiameter=Diameter(root->left,height);
       int rdiameter=Diameter(root->right,height);
      
       height=max(height,ldiameter+rdiameter);
       return 1+max(ldiameter,rdiameter);
   }
    int diameterOfBinaryTree(TreeNode* root) {
         int height=0;
        int ans= Diameter(root,height);
        return height;
    }
};
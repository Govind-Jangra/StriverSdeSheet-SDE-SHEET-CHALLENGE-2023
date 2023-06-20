// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
 *     TreeNode() : val(0), left(NULL), right(NULL) {}
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int> inorderTraversal(TreeNode* root) {
       TreeNode* currentNode = root;
        vector<int> ans;
    while (currentNode != NULL) {
        if (currentNode->left == NULL) {
            // Process the current node
            ans.push_back(currentNode->val);
            currentNode = currentNode->right;
        } else {
            // Find the rightmost node in the left subtree
            TreeNode* rightmost = currentNode->left;
            while (rightmost->right != NULL && rightmost->right != currentNode) {
                rightmost = rightmost->right;
            }

            if (rightmost->right == NULL) {
                // Establish the temporary link
                rightmost->right = currentNode;
                currentNode = currentNode->left;
            } else {
                // Remove the temporary link and process the current node
                rightmost->right = NULL;
                ans.push_back(currentNode->val);
                currentNode = currentNode->right;
            }
        }
    }
    return ans;
    }
    
};
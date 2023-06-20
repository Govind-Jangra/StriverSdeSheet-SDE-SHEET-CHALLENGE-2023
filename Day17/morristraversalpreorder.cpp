// https://www.codingninjas.com/codestudio/problems/preorder-traversal_3838888?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int data;
     TreeNode *left;
      TreeNode *right;

  };
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
     TreeNode* currentNode = root;
    vector<int> ans;
    while (currentNode != NULL) {
        if (currentNode->left == NULL) {
            // Process the current node
            ans.push_back(currentNode->data);
            currentNode = currentNode->right;
        } else {
            // Find the rightmost node in the left subtree
            TreeNode* rightmost = currentNode->left;
            while (rightmost->right != NULL && rightmost->right != currentNode) {
                rightmost = rightmost->right;
            }

            if (rightmost->right == NULL) {
                // Establish the temporary link and process the current node
                rightmost->right = currentNode;
                ans.push_back(currentNode->data);
                currentNode = currentNode->left;
            } else {
                // Remove the temporary link
                rightmost->right = NULL;
                currentNode = currentNode->right;
            }
        }
    }
    return ans;
}
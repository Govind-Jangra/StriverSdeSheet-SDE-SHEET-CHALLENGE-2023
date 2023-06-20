// https://leetcode.com/problems/binary-tree-postorder-traversal/
#include <bits/stdc++.h> 
using namespace std;
  class BinaryTreeNode
    {
    public :
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
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
void allTraversal(BinaryTreeNode *root, vector<int> &pre, vector<int> &in, vector<int> &post) {
    stack<pair<BinaryTreeNode*, int>> st;
    st.push({root, 1});
    if (root == NULL) return;

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        } else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        } else {
            post.push_back(it.first->data);
        }
    }
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode *root){
    // Write your code here.
    vector<int> pre, in, post;
    allTraversal(root, pre, in, post);
    return { in,pre ,post};
}
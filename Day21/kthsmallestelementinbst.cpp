// https://leetcode.com/problems/kth-smallest-element-in-a-bst/


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
    // void solve(TreeNode* root, int &k,int &ans){
    //     if(root==NULL) return ;
    //     solve(root->left,k,ans);
    //     k--;
    //     if(k==0) {
    //         ans=root->val;
    //         return;
    //     }
    //     solve(root->right,k,ans);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     int ans=0;
    //     solve(root,k,ans);
    //     return ans;
    // }

    struct TreeNodeWithCount {
        int val;
        int count;
        TreeNodeWithCount* left;
        TreeNodeWithCount* right;
        TreeNodeWithCount(int x) : val(x), count(1), left(nullptr), right(nullptr) {}
    };
    
    TreeNodeWithCount* buildTreeWithCount(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNodeWithCount* rootWithCount = new TreeNodeWithCount(root->val);
        rootWithCount->left = buildTreeWithCount(root->left);
        rootWithCount->right = buildTreeWithCount(root->right);
        if (rootWithCount->left != nullptr) rootWithCount->count += rootWithCount->left->count;
        if (rootWithCount->right != nullptr) rootWithCount->count += rootWithCount->right->count;
        return rootWithCount;
    }
    
    int kthSmallest(TreeNodeWithCount* rootWithCount, int k) {
        if (k <= 0 || k > rootWithCount->count) return -1;
        if (rootWithCount->left != nullptr) {
            if (rootWithCount->left->count >= k) return kthSmallest(rootWithCount->left, k);
            if (rootWithCount->left->count == k-1) return rootWithCount->val;
            return kthSmallest(rootWithCount->right, k-1-rootWithCount->left->count);
        } else {
            if (k == 1) return rootWithCount->val;
            return kthSmallest(rootWithCount->right, k-1);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        TreeNodeWithCount* rootWithCount = buildTreeWithCount(root);
        return kthSmallest(rootWithCount, k);
    }
    
};
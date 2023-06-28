// https://www.codingninjas.com/studio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos


#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void solve(BinaryTreeNode<int> * root,int x,int &k){
    if(root==NULL) return;
    if(root->data<x) solve(root->right,x,k);
    if(root->data>=x){
        k=root->data;
        solve(root->left,x,k);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
      int ans=-1;
    solve(node,x,ans);
    return ans;
}
// https://www.codingninjas.com/studio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> * root,int x,int& k){
    if(root==NULL) return;
    if(root->val>x) solve(root->left,x,k);
    else if(root->val<=x){
        k=root->val;
        solve(root->right,x,k);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans=0;
    solve(root,X,ans);
    return ans;
}
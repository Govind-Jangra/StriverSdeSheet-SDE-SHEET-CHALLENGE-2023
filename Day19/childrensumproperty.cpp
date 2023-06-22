// https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website



#include <bits/stdc++.h> 

using namespace std;

    template<typename T>
    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL ) return;
    int l=0,r=0;
    if(root->left==NULL && root->right==NULL){
        root->data+=1e6+2;
    }
    changeTree(root->left);
    changeTree(root->right);
    if(root->left && root->right){
        l=root->left->data;
        r=root->right->data;
        root->data=l+r;

    }
    else if(root->left){
         root->data=root->left->data;
       
    }
    else if(root->right){
        root->data=root->right->data;
       
    }
}  
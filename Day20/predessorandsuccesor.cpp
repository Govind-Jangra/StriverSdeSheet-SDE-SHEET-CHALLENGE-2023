// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

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


struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void succc(Node* root, Node*& pre, Node*& suc, int k){
        if(root==NULL) return ;
        
        //  succc(root->right,pre,suc,k);
        //  if(root->key>k) suc=root; 
        // //  succ=root;
        // succc(root->left,pre,suc,k);
        if(root->key<=k) succc(root->right,pre,suc,k);
        else{
            suc=root;
            succc(root->left,pre,suc,k);
        }
        
        
       
    }
     void preee(Node* root, Node*& pre, Node*& suc, int k){
        if(root==NULL) return ;
        // preee(root->left,pre,suc,k);
        
        // if(root->key<k) pre=root;
        //  preee(root->right,pre,suc,k);
        
        if(root->key>=k){
            preee(root->left,pre,suc,k);
        }
        else{
            pre=root;
            preee(root->right,pre,suc,k);
        }
         
         
        
        
        
       
    }
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        preee(root,pre,suc,key);
        succc(root,pre,suc,key);
        // Your code goes here
        
    //   if(!root)return ;
       
    //   if(root->key >= key)
    //     findPreSuc(root->left,pre,suc,key);
        
    //     if(root->key<key){
    //         pre = root;
    //     }
    //     if(root->key>key){
    //         if(!suc)
    //         suc = root;
    //         return ;
    //     }
        
    //     findPreSuc(root->right,pre,suc,key);
        

    }
};
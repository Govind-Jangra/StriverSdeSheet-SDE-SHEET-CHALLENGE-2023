// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

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
    int data;
    Node* left, * right;
}; 

class Solution {
public:
   void left(Node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    ans.push_back(root->data);
    
    if(root->left)
    left(root->left,ans);
    
    else{
        left(root->right,ans);
    }
}
void leaf(Node* root,vector<int> &ans){
     if(root==NULL){
        return;
    }
    leaf(root->left,ans);
     if(root->left==NULL && root->right==NULL){
       
    ans.push_back(root->data);
  
    }
    leaf(root->right,ans);
   
}
void right(Node* root,stack<int> &s){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    
    s.push(root->data);
    
    if(root->right)
    right(root->right,s);
    else
    right(root->left,s);
    
 
}
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
      if(root!=NULL){
          ans.push_back(root->data);
      }
        
        left(root->left,ans);
        if(root->left || root->right)
        leaf(root,ans);
     stack<int> s;
        right(root->right,s);
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};
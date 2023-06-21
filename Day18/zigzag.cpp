// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
    	stack<TreeNode*> curr;
    	stack<TreeNode*> next;
    	bool lefttoright=1;
    	
    	if(root!=NULL){
    	    curr.push(root);
    	}
    	while(!curr.empty() || !next.empty()){
            vector<int> a;
    	    if(lefttoright){
    	        while(!curr.empty()){
    	            TreeNode* temp=curr.top();
    	            curr.pop();
    	            a.push_back(temp->val);
    	            if(temp->left){
    	                next.push(temp->left);
    	            }
    	            if(temp->right){
    	                next.push(temp->right);
    	            }
    	        }
    	    }
    	    else{
    	        while(!next.empty()){
    	            TreeNode* temp=next.top();
    	            next.pop();
    	            a.push_back(temp->val);
    	             if(temp->right){
    	                curr.push(temp->right);
    	            }
    	            if(temp->left){
    	                curr.push(temp->left);
    	            }
    	            
    	        }
    	    }
    	    
    	    lefttoright=!lefttoright;
    	    
    	    
    	    
    	    
    	    
    	    ans.push_back(a);
    	    
    	    
    	    
    	    
    	}
    	return ans;
    }
};
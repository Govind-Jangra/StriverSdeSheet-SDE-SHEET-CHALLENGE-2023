// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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




class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public: 
    void solve(Node* root,Node* next){
    if(root==NULL) return;
    root->next=next;
    solve(root->left,root->right);
    solve(root->right,root->next==NULL?NULL:root->next->left);
    }
    Node* connect(Node* root) {
        solve(root,NULL);
        return root;
    }
};
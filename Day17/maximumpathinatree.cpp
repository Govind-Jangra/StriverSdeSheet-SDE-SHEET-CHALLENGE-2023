// https://leetcode.com/problems/maximum-width-of-binary-tree/
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
 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        int ans = 0;

        while(!q.empty()) {
            
            int c=q.front().second;
            int size=q.size();
            int left,right;
            for(int i=0;i<size;i++){
                auto temp=q.front().first;
                int count=q.front().second-c;
                q.pop();
                if(i==0){
                    left=count;

                }
                if(i==size-1) right=count;
                if(temp->left){
                    q.push({temp->left,(long)2*count+1});
                }
                if(temp->right){
                    q.push({temp->right,(long)2*count+2});
                }
            }
            ans=max(ans,right-left+1);
        }

        return ans;
    }
};
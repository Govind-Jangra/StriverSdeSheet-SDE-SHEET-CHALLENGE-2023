// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x=q.front();
            q.pop();
            if(x==NULL){
                s+="$";
                continue;
            }
            else{
            s+=to_string(x->val);
            s+=",";
            }
            
                q.push(x->left);
            
            
           
                q.push(x->right);
           
            
        }
            
            
            return s;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
         if(s.size()==0) return NULL;
        int i=0;
        string x="";
        while(s[i]!=','){
            x+=s[i++];
        }
        i++;
        int y=stoi(x);
        TreeNode * ans=new TreeNode(y);
        TreeNode *root=ans;
        queue<TreeNode*> q;
        q.push(ans);
        while(!q.empty() && i<s.size()){
            TreeNode* temp=q.front();
            q.pop();
            //root->left
            if(s[i]=='$'){
                temp->left==NULL;
                i++;

            }
            else{
                x="";
                 while(s[i]!=','){
            x+=s[i++];
        }
        i++;
         y=stoi(x);
         TreeNode* newn=new TreeNode(y);
         temp->left=newn;
         q.push(newn);
            }
            //root->right
            if(s[i]=='$'){
                temp->right==NULL;
                i++;

            }
            else{
                x="";
                 while(s[i]!=','){
            x+=s[i++];
        }
        i++;
         y=stoi(x);
         TreeNode* newn=new TreeNode(y);
         temp->right=newn;
         q.push(newn);
            }
        }
        
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
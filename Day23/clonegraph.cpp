// https://leetcode.com/problems/clone-graph/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
     unordered_map<Node*,Node*>m;
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        Node* ans=new Node(node->val);
        m[node]=ans;
        for (auto i:node->neighbors){
            if (m.count(i)) ans->neighbors.push_back(m[i]);
            else
                ans->neighbors.push_back(cloneGraph(i));
        }
        return ans;
    }
};
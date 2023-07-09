// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

 
struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
    
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};
class Solution {
public:

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int i=0,j=0;
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> arr;
        
        int n=nums.size();
        int m=queries.size();
        for(int i=0;i<m;i++){
            arr.push_back({queries[i][1],{i,queries[i][0]}});
        }
        sort(arr.begin(),arr.end());
        vector<int> ans(m);
       for(auto it:arr){
         while(i<n && nums[i]<=it.first) trie.insert(nums[i++]);
         
           if(i==0){
             ans[it.second.first]=-1;

           }
           else ans[it.second.first]=trie.findMax(it.second.second);
         
       }
    return ans;
       
    }
};
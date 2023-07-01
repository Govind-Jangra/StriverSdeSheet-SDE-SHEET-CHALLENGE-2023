// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
       vector<int> ans;
        int arr[V+1]={0};
        queue<int> s;
        s.push(0);
    arr[0]=1;
            while(!s.empty()){
                int temp=s.front();
                s.pop();
                // if(arr[temp]==0){
                ans.push_back(temp);
                // arr[temp]=1;
                // }
                
                for(int j=0;j<adj[temp].size();j++){
                    if(arr[adj[temp][j]]==0){
                        s.push(adj[temp][j]);
                        arr[adj[temp][j]]=1;
                    }
                }
                
                
            }
        
        return ans;
    }
};
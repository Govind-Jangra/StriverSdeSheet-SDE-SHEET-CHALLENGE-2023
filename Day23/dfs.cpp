// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int st,vector<int> adj[],int visited[],vector<int> &ans){
        visited[st]=1;
        ans.push_back(st);
        for(auto i: adj[st]){
            if(visited[i]==0){
                dfs(i,adj,visited,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        visited[0]=1;
        vector<int> ans;
        int start=0;
        dfs(start,adj,visited,ans);
        return ans;
    }
};
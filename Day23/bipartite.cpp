// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
bool solve(int node,int color[],vector<int> adj[]){
      
        for(auto i:adj[node]){
            if(color[i]==-1){
                color[i]=1-color[node];
               if(!solve(i,color,adj)) return 0;
            }
            else if(color[i]==color[node]) return 0;
        
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
            adj[i].push_back(graph[i][j]);
            adj[graph[i][j]].push_back(i);
            }
        }
       int color[V];
   for(int i=0;i<V;i++){
       color[i]=-1;
   }
 
           for(int i=0;i<V;i++)
           {
               
               if(color[i]==-1){
                   
                   color[i]=0;
                   if(!solve(i,color,adj)) return 0;
               }
           }
        
        return 1;
    }
};
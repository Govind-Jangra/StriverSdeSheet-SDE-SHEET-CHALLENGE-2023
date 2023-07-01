// https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        //using bfs khan's algorithm
         vector<int> adj[V];
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	    }
     
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	   
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    int count=0;
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
	        count++;
	   
	        for(auto i:adj[x]){
	         
	            if(--indegree[i]==0){
	                q.push(i);
	            }
	        }
	        
	    }
	  
	   if(count==V){
	       return 1;
	   }
	   return 0;
    }
};
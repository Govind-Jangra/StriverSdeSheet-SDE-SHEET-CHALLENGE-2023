// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1



class Solution
{
	public:
	
	void dfs(int node,vector<int> &vis,stack<int> &s,vector<int> adj[]){
	    
	   
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,s,adj);
	        }
	    }
	    s.push(node);
	    
	}
	void revdfs(int node,vector<int> &vis,vector<int> adj[]){
	    
	  
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            revdfs(it,vis,adj);
	        }
	    }
	    //s.push(node);
	    
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        
        vector<int> vis(V,0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,s,adj);
            }
        }
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it: adj[i]){
                transpose[it].push_back(i);
            }
        }
        
        int ans=0;
        while(!s.empty()){
            
            int x=s.top();
            s.pop();
            if(!vis[x]){
                ans+=1;
                revdfs(x,vis,transpose);
            }
            
        }
        return ans;
    }
};
// https://practice.geeksforgeeks.org/problems/topological-sort/1


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    //using bfs khan's algorithm
	    int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
	        ans.push_back(x);
	        for(auto i:adj[x]){
	         
	            if(--indegree[i]==0){
	                q.push(i);
	            }
	        }
	        
	    }
	    return ans;
	}
};
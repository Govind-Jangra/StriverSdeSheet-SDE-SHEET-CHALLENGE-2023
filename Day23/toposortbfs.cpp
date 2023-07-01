// https://practice.geeksforgeeks.org/problems/topological-sort/1


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topo(int x,vector<int> adj[],int vis[],vector<int> &ans){
	    vis[x]=1;
	    for(auto i:adj[x]){
	        if(vis[i]==0) topo(i,adj,vis,ans);
	    }
	    ans.push_back(x);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    int vis[V]={0};
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            topo(i,adj,vis,ans);
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};
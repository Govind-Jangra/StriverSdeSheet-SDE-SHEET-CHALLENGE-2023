// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //brute force
        int  parent[V];
        int settree[V];
        int key[V];
       for(int i=0;i<V;i++){
           parent[i]=-1;
           settree[i]=0;
           key[i]=INT_MAX;
       }
       parent[0]=-1;
       key[0]=0;
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0}); // {key[i],i}
       while(!pq.empty())
       {
           int u=pq.top().second;
            pq.pop();
               settree[u]=1;
              
               for(auto it:adj[u]){
                   
                   int wt=it[1];
                 
                   int v=it[0];
                   if(settree[v]==0 && key[v]>wt){
                       parent[v]=u;
                       
                       pq.push({wt,v});
                       key[v]=wt;
                   }
               }
           
       }
            for(int i=0;i<V;i++){
             ans+=key[i];
            }
        return ans;
    }
};
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        dist[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // dist,node
        
        pq.push({0,s});
        while(!pq.empty()){
            int d=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            for(auto it: adj[prev]){
                int nextdist=it[1];
                int next=it[0];
                if(dist[next]> dist[prev]+nextdist){
                    pq.push({dist[prev]+nextdist,next});
                    dist[next]=dist[prev]+nextdist;
                }
            }
        }
        return dist;
    }
};
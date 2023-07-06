// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU


    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
         vector<int> dist(V,1e8);
        dist[S]=0;
        
        V--;
        while(V--){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        
         for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                if(dist[u]+wt<dist[v]){
                    return{-1};
                }
            }
            
            return dist;
        
    }
};
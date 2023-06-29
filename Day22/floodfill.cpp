// https://leetcode.com/problems/flood-fill/


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int x) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int old=grid[sr][sc];
        vector<vector<int>> vis(n,vector<int>(m,0));
        grid[sr][sc]=x;
        vis[sr][sc]=1;
        
        q.push({sr,sc});
        vector<vector<int>>ans(n,vector<int>(m,0));
      
        while(!q.empty()){
            int r=q.front().first;
             int c=q.front().second;
           
            
             q.pop();
             int rw[4]={-1,1,0,0};
             int cw[4]={0,0,-1,1};
             for(int i=0;i<4;i++){
                 int row=r+rw[i];
                 int col=c+cw[i];
                 if(row<n && row>=0 && col<m && col>=0 && vis[row][col]==0 && grid[row][col]==old){
                    grid[row][col]=x;
                     q.push({row,col});
                     vis[row][col]=1;
                 }
             }
                 
             }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               ans[i][j]=grid[i][j];
            }
        
        }
      
        return ans;
    }
};
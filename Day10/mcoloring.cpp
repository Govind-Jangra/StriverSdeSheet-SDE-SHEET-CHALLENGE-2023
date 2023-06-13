// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.

bool check(vector<int> graph[], vector<int>&assign, int node, int color){
        for(auto adj: graph[node]){
            if(assign[adj] == color){
                return false;
            }
        }
        return true;
    }

    bool color(vector<int> graph[], vector<int> &assign, int n, int m, int node){
       
        if(node == n-1){
          
            for(int i=1; i<=m; i++){
                
                if(check(graph, assign, node, i)){
                    assign[node] = i;
                    return true;
                }
            }
            
            return false;
        };
    
       
        for(int i=1; i<=m; i++){
            if(check(graph,assign, node, i)){
                assign[node] = i;
                if(color(graph, assign, n, m, node+1))return true;
                assign[node] = -1;
            }
            
        }
        return false;
    }
    bool graphColoring(bool graphMat[101][101], int m, int n) {
        vector<int> graph[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graphMat[i][j] == 1){
                    graph[i].push_back(j);
                }
            }
        }
        vector<int> assign(n, -1);
        
        if(color(graph, assign, n, m, 0)){
           
            return true;
        }
     return false;   
    }
};
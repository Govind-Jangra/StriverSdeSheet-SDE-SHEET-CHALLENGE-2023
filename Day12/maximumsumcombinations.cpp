// https://www.interviewbit.com/problems/maximum-sum-combinations/


#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &A, vector<int> &B, int K) {
    int N=A.size();
   sort(A.begin(),A.end());
sort(B.begin(),B.end());

vector<int>ans;
priority_queue<pair<int,pair<int,int>>>pq;
set<pair<int,int>>s;

pq.push({A[N-1]+B[N-1],{N-1,N-1}});
s.insert({N-1,N-1});

while(K--){
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    ans.push_back(pq.top().first);
    pq.pop();
    
    if(s.find({x-1,y}) == s.end()){
        pq.push({A[x-1]+B[y],{x-1,y}});
        s.insert({x-1,y});
    }
    if(s.find({x,y-1}) == s.end()){
        pq.push({A[x]+B[y-1],{x,y-1}});
        s.insert({x,y-1});
    }
}
return ans;
}

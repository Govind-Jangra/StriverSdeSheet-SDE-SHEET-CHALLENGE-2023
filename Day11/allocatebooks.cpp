// https://www.interviewbit.com/problems/allocate-books/


#include<bits/stdc++.h>

using namespace std;
bool ispossible(vector<int> &A, int B,int limit){
    int student=1;
    int pages=0;
    for(auto i:A){
        if(i>limit) return 0;
        if(pages+i>limit){
            pages=i;
            student++;
            if(student>B) return 0;
        }
        else pages+=i;
    }
    return 1;
}
int books(vector<int> &A, int B) {
    if(B>A.size()+1) return -1;
    int l=A[0];
    int h=0;
    for(auto i:A){
        l=min(l,i);
        h+=i;
    }
    
    while(l<=h){
        int m=(l+h)>>1;
        if(ispossible(A,B,m)){
            h=m-1;
        }
        else l=m+1;
    }
    return l;
}

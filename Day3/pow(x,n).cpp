// https://leetcode.com/problems/powx-n/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0) return 1;
        if(n==1) return x;
        if(n==-1) return 1/x;

        double left=myPow(x,n/2);
        double curr=1;
        if(n%2 && n>0) curr=x;
        else if(n%2 && n<0) curr=1/x; 

        return left*left*curr;
    }
};
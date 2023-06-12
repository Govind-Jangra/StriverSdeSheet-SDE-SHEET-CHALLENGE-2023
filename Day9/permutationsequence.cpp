// https://leetcode.com/problems/permutation-sequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> arr;
        for(int i=1;i<n;i++){
            fact*=i;
            arr.push_back(i);
        }
        arr.push_back(n);
        k--;
        string ans="";
        while(arr.size()>0){
            int x=arr[k/fact];
            ans+=to_string(x);
            arr.erase(arr.begin()+k/fact);
            k=k%fact;
            if(arr.size()>0)
            fact=fact/arr.size();
        }
        return ans;
    }
};
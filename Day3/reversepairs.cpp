// https://leetcode.com/problems/reverse-pairs/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void merge(vector<long long>&arr, long long low, long long mid, long long high, long long int&count){
   int l = low, r = mid + 1;
        while(l <= mid && r <= high){
            if((long)arr[l] > (long) 2 * arr[r]){
                count += (mid - l + 1);
                r++;
            }else{
                l++;
            }
        }
       
        sort(arr.begin() + low, arr.begin() + high + 1);
        

}

void mergesort(vector<long long>&a, long long low, long long high, long long int&c){
    if(low>=high){
        return;
    }
    long long mid = (low+ high)/2;
    mergesort(a, low, mid, c);
    mergesort(a, mid+1, high, c);
    return merge(a,low, mid, high, c);
}

    int reversePairs(vector<int>& arr) {
        int N=arr.size();
       long long int count = 0;
        vector<long long>ans;
        for(long long i=0; i<N; i++ ){
            ans.push_back(arr[i]);
        }
        mergesort(ans, 0, N-1, count);
        return count;
    }
};
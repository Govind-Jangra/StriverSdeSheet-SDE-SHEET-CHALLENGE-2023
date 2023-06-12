// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<bits/stdc++.h>
using namespace std;
struct Item{
    int value;
    int weight;
};



class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
     static bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double ans=0.0;
// for(int i=0;i<n;i++){
//       cout<<arr[i].value<<" "<<arr[i].weight<<" ";
//     }
        for(int i=0;i<n;i++){
            if(W>=arr[i].weight){
                W-=arr[i].weight;
                ans+=arr[i].value;
                
            }
            else{
                
                ans+=((double)W/(double)arr[i].weight)*(arr[i].value);
               
                break;
            }
        }
        return ans;
}
        
};
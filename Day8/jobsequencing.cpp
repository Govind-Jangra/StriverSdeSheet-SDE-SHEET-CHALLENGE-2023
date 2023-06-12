// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
#include<bits/stdc++.h>
using namespace std;
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


class Solution 
{
    public:
   struct mycomp{
      bool operator()(Job &a,Job &b)
      {
          return a.profit<b.profit;
      }
    };
   
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       
        sort(arr,arr+n,[&](Job a, Job b)
        {
            return a.dead>b.dead;
        });
        priority_queue<Job,vector<Job>,mycomp>pq;
        int ans =0; int jobs=0;
        for(int i=0;i<n;i++)
        {   int slot_time = 0;
            if(i==n-1) slot_time = arr[i].dead;
            else
            {
                slot_time = arr[i].dead-arr[i+1].dead;
            }
            pq.push(arr[i]);
            while(slot_time>0&&!pq.empty())
            {
                Job xx =pq.top();
                slot_time--;
                ans += xx.profit;
                pq.pop();
                jobs ++;
            }
            
        }
        return {jobs,ans};
    } 
};
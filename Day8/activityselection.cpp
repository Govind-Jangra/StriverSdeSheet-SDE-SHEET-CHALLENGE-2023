// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include<bits/stdc++.h>
using namespace std;
struct job{
    int a;
    int b;
};
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
     static int compare(job x,job y){
            return x.b<y.b;
        }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        job time[n];
       for(int i=0;i<n;i++){
        time[i].a=start[i];
        time[i].b=end[i];
       }
       sort(time,time+n,compare);
        int  ans=1;
        int prev=time[0].b;
        for(int i=1;i<n;i++){
            if(time[i].a>prev){
                ans++;
                prev=time[i].b;
            }
        }
        return ans;
    }
};
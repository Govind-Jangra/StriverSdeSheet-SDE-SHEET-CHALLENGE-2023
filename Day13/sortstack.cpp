// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
using namespace std;
void insert(stack<int> &s,int temp){
    if(s.size()==0 || s.top()<=temp){
        s.push(temp);
        return;
    }
    int x=s.top();
    s.pop();
    insert(s,temp);
    s.push(x);
}
void sorthelp(stack<int> &s){
   if(s.size()==1)return;
   int val = s.top();s.pop();
   sorthelp(s);
   stack<int>st;
   while(s.size()>0 and s.top()>val)st.push(s.top()),s.pop();
   s.push(val);
   while(!st.empty())s.push(st.top()),st.pop();
   return;
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	sorthelp(stack);
}
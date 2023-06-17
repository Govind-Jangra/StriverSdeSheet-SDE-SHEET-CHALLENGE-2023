// https://leetcode.com/problems/min-stack/

#include<bits/stdc++.h>

using namespace std;
class MinStack {
public:
stack<long long> s;
long long minn;
    MinStack() {
        
    }
    
    void push(long long val) {
       if(s.empty()){
           minn=val;
           s.push(val);
       }
       else {
           if(val<minn){
               s.push(2*val-minn);
               minn=val;
           }
           else s.push(val);
       }
    }
    
    void pop() {
        if(s.empty()) return;
        if(s.top()<minn){
            minn=2*minn-s.top();

        }
                    s.pop();
        
    }
    
    int top() {
        if(s.top()<minn){
            return minn;
        }
        return s.top();

    }
    
    int getMin() {
        return minn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
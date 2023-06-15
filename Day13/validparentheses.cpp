// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        

       for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push('(');
        }
        if(s[i]=='['){
            st.push('[');
        }
        if(s[i]=='{'){
            st.push('{');
        }
        if(s[i]==']' ){
            if(!st.empty() && st.top()=='[')
            st.pop();
            else return 0;
        }
        
        if(s[i]=='}'){
            if(!st.empty() && st.top()=='{')
            st.pop();
            else return 0;
        } 
        if(s[i]==')'){
            if(!st.empty() &&  st.top()=='(')
          st.pop();
          else return 0;
        }
        }
        return st.size()==0;
    }
    
};
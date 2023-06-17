// https://www.interviewbit.com/problems/nearest-smaller-element/
#include<bits/stdc++.h>

using namespace std;
vector<int> prevSmaller(vector<int> &A) {
    vector<int> ans(A.size());
    

    stack<int> st;
    
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) st.pop();
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}

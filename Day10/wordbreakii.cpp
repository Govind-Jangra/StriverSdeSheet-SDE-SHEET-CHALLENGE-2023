// https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
using namespace std;


void solve(int i, int n,  string s,  string t,  unordered_set<string>& st, vector<string>& ans) {
    if (i == n) {
        ans.push_back(t.substr(1)); // Remove leading space
        return;
    }

    string temp = "";
    for (int idx = i; idx < n; idx++) {
        temp += s[idx];
        if (st.find(temp) != st.end()) {
            solve(idx + 1, n, s, t + " " + temp, st, ans);
        }
    }
}

vector<string> wordBreak( string& s,  vector<string>& dictionary) {
    vector<string> ans;
    string t = "";
    unordered_set<string> st(dictionary.begin(), dictionary.end());
    solve(0, s.size(), s, t, st, ans);
    return ans;
}
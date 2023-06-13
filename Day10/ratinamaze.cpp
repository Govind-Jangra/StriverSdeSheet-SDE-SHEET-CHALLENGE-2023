// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, int n, int mm, string s, vector<vector<int>>& m, vector<string>& ans) {
        if (i == n - 1 && j == mm - 1) {
            ans.push_back(s);
            return;
        }
        if (i - 1 >= 0 && m[i - 1][j] == 1) {
            m[i - 1][j] = 0;
            solve(i - 1, j, n, mm, s + "U", m, ans);
            m[i - 1][j] = 1;
        }
        if (i + 1 < n && m[i + 1][j] == 1) {
            m[i + 1][j] = 0;
            solve(i + 1, j, n, mm, s + "D", m, ans);
            m[i + 1][j] = 1;
        }
        if (j - 1 >= 0 && m[i][j - 1] == 1) {
            m[i][j - 1] = 0;
            solve(i, j - 1, n, mm, s + "L", m, ans);
            m[i][j - 1] = 1;
        }
        if (j + 1 < mm && m[i][j + 1] == 1) {
            m[i][j + 1] = 0;
            solve(i, j + 1, n, mm, s + "R", m, ans);
            m[i][j + 1] = 1;
        }
    }
    
    vector<string> findPath(vector<vector<int>>& m, int n) {
    
        string t = "";
        vector<string> ans;
           if(m[0][0]==0 ) return ans;
        int mm = m[0].size(); // Number of columns
        m[0][0] = 0; // Mark the starting position as visited
        solve(0, 0, n, mm, t, m, ans);
        return ans;
    }
};

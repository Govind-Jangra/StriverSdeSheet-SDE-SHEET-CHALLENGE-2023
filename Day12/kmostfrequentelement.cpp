// https://leetcode.com/problems/top-k-frequent-elements/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            maxFreq = max(maxFreq, m[nums[i]]);
        }
        
        vector<vector<int>> arr(maxFreq + 1);
        for (auto i : m) {
            arr[i.second].push_back(i.first);
        }
        
        vector<int> ans;
        for (int i = maxFreq; i >= 0; i--) {
            for (auto j : arr[i]) {
                ans.push_back(j);
                k--;
                if (k == 0)
                    break;
            }
            if (k == 0)
                break;
        }
        
        return ans;
    }
};

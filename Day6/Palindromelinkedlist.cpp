// https://leetcode.com/problems/palindrome-linked-list/description/
#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return solve(head);
    }
    
    bool solve(ListNode* p) {
        if (NULL == p) return true;
        bool flag = solve(p->next) & (temp->val == p->val);
        temp = temp->next;
        return flag;
    }
};
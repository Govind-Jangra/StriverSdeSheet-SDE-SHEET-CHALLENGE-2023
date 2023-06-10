// https://leetcode.com/problems/delete-node-in-a-linked-list/description/
#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    void deleteNode(ListNode* node) {
         node->val = node->next->val;
        ListNode* cur = node->next;
        node->next = node->next->next;
        delete cur;
        cur = NULL;
    }
};
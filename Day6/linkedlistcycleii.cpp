// https://leetcode.com/problems/linked-list-cycle-ii/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return head;
        
		
        ListNode *fast = head;
        ListNode *slow = head;
        
		
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
		
            if(fast == slow){
                fast=head;
                
                    while(1){
                        if(fast==slow) return slow;
                         fast = fast->next;
            slow = slow->next;
            
                    }
            }
                
        }
        

        return NULL;
    }
};
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode *prev=NULL;
        ListNode *currptr=head;
        ListNode *nxtptr;
        ListNode *tmp=head;
        int i=0;
        while(tmp!=NULL && i<k)
        {
            tmp=tmp->next;
            i++;
        }
        if(i<k)
        {
           return head; 
        }
        int count=0;
        while(currptr!=NULL && count<k)
        {
            nxtptr=currptr->next;
            currptr->next=prev;
            prev=currptr;
            currptr=nxtptr;
            count++;
        }
        if(nxtptr!=NULL)
             head->next=reverseKGroup(nxtptr,k);
        return prev;

    }
};
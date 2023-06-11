// https://leetcode.com/problems/rotate-list/description/
#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL) return head;
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0) return head;
        k=n-k-1;
        temp=head;
        while(k--){
            temp=temp->next;
        }
        ListNode* t=temp->next;
        ListNode* t2=temp;
        
        
        while(temp->next) temp=temp->next;
        temp->next=head;
        t2->next=NULL;
        return t;
    }
};
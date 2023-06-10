// https://leetcode.com/problems/add-two-numbers/description/
#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s=l1->val+l2->val;
        int rr=s%10;
        ListNode* ans=new ListNode(rr);
       ListNode * final=ans;
        int c=s>=10?1:0;
        l1=l1->next;
        l2=l2->next;
        while(l1 && l2){
           
            int sum=l1->val+l2->val+c;
            int r=sum%10;
            ListNode* temp=new ListNode(r);
            ans->next=temp;
            ans=ans->next;
             c=sum/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            
            int sum=l1->val+c;
            int r=sum%10;
            ListNode* temp=new ListNode(r);
            ans->next=temp;
             ans=ans->next;
             c=sum/10;
            l1=l1->next;
        //    cout<<"h";
        }
        while( l2){
            
            int sum=l2->val+c;
            int r=sum%10;
            ListNode* temp=new ListNode(r);
            ans->next=temp;
             ans=ans->next;
            c=sum/10;
            
            l2=l2->next;
        }
        if(c==1){
            ListNode* temp=new ListNode(1);
            ans->next=temp;
             ans=ans->next;
        }
        ans->next=NULL;
        
        return final;
    }
};
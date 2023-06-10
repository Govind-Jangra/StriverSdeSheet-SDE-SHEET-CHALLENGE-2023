// https://leetcode.com/problems/merge-two-sorted-lists/description/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * root=new ListNode(0);
        ListNode* head=root;
        while(list1 && list2){
            if(list1->val<list2->val){
                ListNode* temp=new ListNode(list1->val);
                root->next=temp;
                root=root->next;
                list1=list1->next;
            }
            else{
                
                ListNode* temp=new ListNode(list2->val);
                root->next=temp;
                root=root->next;
                list2=list2->next;
            
            }
        }
        while(list1){
            ListNode* temp=new ListNode(list1->val);
                root->next=temp;
                root=root->next;
                list1=list1->next;
        }
        while(list2){
            ListNode* temp=new ListNode(list2->val);
                root->next=temp;
                root=root->next;
                list2=list2->next;
        }
        return head->next;
    }
};
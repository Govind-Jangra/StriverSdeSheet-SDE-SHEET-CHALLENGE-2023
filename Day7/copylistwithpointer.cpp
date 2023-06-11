// https://leetcode.com/problems/copy-list-with-random-pointer/description/
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(head){
            Node* t=head->next;
            head->next=new Node(head->val);
            head->next->next=t;
            head=head->next->next;
        }
        head=temp;
        while(head){
            if(head->random)
            head->next->random=head->random->next;
            head=head->next->next;
        }
       
        Node* ans=new Node(0);
        head=temp;
        Node* final=ans;
        while(head){
            ans->next=head->next;
            ans=ans->next;
            head->next=ans->next;
            head=head->next;
        }
    return final->next;
    }
};
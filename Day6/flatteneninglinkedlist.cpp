// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


/*  Function which returns the  root of 
    the flattened linked list. */
    Node* solve(Node* list1,Node* list2){
         Node * root=new Node(0);
        Node* head=root;
        list1->next=NULL;
        list2->next=NULL;
        while(list1 && list2){
            if(list1->data<=list2->data){
               
                root->bottom=list1;
                root=root->bottom;
                list1=list1->bottom;
            }
            else{
                

                root->bottom=list2;
                root=root->bottom;
                list2=list2->bottom;
            
            }
        }
        while(list1){

                root->bottom=list1;
                root=root->bottom;
                list1=list1->bottom;
        }
        while(list2){
            
                root->bottom=list2;
                root=root->bottom;
                list2=list2->bottom;
        }
        return head->bottom;
    }
Node *flatten(Node *root)
{
   // Your code here
   if(root->next)
   Node* second=flatten(root->next);
   Node* ans=root;
   if(root->next)
   ans =solve(root,root->next);
   return ans;
}

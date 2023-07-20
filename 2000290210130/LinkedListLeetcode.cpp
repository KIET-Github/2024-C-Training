1. Reverse linked list-

Given the head of a singly linked list, reverse the list, and return the reversed list.

Solution-

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
    ListNode* reverseList(ListNode* head) {
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* nex;
        while(current!=NULL){
            nex=current->next;
            current->next=prev;
            prev=current;
            current=nex;
        }
        
        return prev;
    }
};

2. Middle of the linked list

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Solution-

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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        int x=(count/2);
        for(int i=1;i<=x;i++){
            head=head->next;
        }
        return head;
        
    }
};

3. Merge two sorted arrays

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Solution-

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res;
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val <= list2->val){
            res=list1;
            res->next=mergeTwoLists(list1->next,list2);
           
        }
        else{
            res=list2;
            res->next=mergeTwoLists(list1,list2->next);
            
        }
        return res;
    }
};

4. Remove nth node from the end of the list

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Solution-

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==1 && n==1){
            head=NULL;
            return head;
        }
        int x=count-n;
        temp=head;
        for(int i=1;i<x;i++){
            temp=temp->next;
        }
        if(n==1){
            temp->next=NULL;
        }
        if(count==n && n>1){
            head=temp->next;
            return head;
        }
        if(n>1)
        temp->next=temp->next->next;
        return head;
    }
};

5. Delete node in a linked list

There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that deleting the node does not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.

Solution-

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
       ListNode* temp=node->next;
       node->val=node->next->val;
       node->next=node->next->next;
       delete temp;

    }
}; 
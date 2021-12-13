/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head){
    struct ListNode *prev=NULL, *tmp;
    while(head!=NULL){
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }
    return prev;
}


bool isPalindrome(struct ListNode* head){
    struct ListNode *fast=head, *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    slow = reverse(slow);
    while(slow != NULL){
        if(head->val != slow->val)
            return false;
        head = head->next;
        slow = slow->next;
    }
    
    return true;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return NULL;
        
    struct ListNode* tmp;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while(cur != NULL){
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}

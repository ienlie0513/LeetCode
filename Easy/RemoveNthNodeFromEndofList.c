/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *arr[30], *cur=head;
    int i=0;
    while(cur != NULL){
        arr[i++] = cur;
        cur = cur->next;
    }
    
    if(i == 1){
        head = NULL;
    }
    else if(n == 1){
        arr[i-2]->next = NULL;   
    }
    else{
        arr[i-n]->val = arr[i-n+1]->val;
        arr[i-n]->next = arr[i-n+1]->next;
    }
    
    return head;
}

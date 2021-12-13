/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    int list[100001], i=0, j=0;
    while(head!=NULL){
        list[i++] = head->val;
        head = head->next;
    }
    
    i--;
    while(j<i){
        if(list[i] != list[j])
            return false;
        i--;
        j++;
    }
    return true;
}

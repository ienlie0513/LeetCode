/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l2 == NULL)
        return l1;
    else if(l1 == NULL)
        return l2;
    
    struct ListNode *ans;
    struct ListNode *current;
    
    if(l1->val <= l2->val){
        ans = l1;
        l1 = l1->next;
    }
    else{
        ans = l2;
        l2 = l2->next;
    }
    
    current = ans;
    
    while(l1){
        if(l2 == NULL){
            current->next = l1;
            return ans;
        }
        struct ListNode *temp;
        if(l1->val < l2->val){
            temp = l1;
            l1 = l1->next;
        }
        else{
            temp = l2;
            l2 = l2->next;
        }
        current->next = temp;
        current = current->next;
    }
    current->next = l2;
    return ans;
}

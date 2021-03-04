/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head1 = l1, *head2 = l2, *prev=NULL;
    int carry = 0;
    while(l1 && l2){
        l1->val += l2->val + carry;
        carry = l1->val / 10;
        l1->val %= 10;
        l2->val = l1->val;
        if(!l1->next && !l2->next)
            prev = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 && carry){
        l1->val += carry;
        carry = l1->val / 10;
        l1->val %= 10;
        if(!l1->next)
            prev = l1;
        l1 = l1->next;
    }
    if(carry && prev){
        struct ListNode* c = (struct ListNode*)malloc(sizeof(struct ListNode));
        c->val = carry;
        c->next = NULL;
        prev->next = c;
    }
    if(!l2)
        return head1;
    while(l2 && carry){
        l2->val += carry;
        carry = l2->val / 10;
        l2->val %= 10;
        if(!l2->next)
            prev = l2;
        l2 = l2->next;
    }
    if(carry){
        struct ListNode* c = (struct ListNode*)malloc(sizeof(struct ListNode));
        c->val = carry;
        c->next = NULL;
        prev->next = c;
    }
    return head2;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode* tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int left_size = numsSize/2;
    int right_size = 0;
    tree->val = nums[left_size];
    if(numsSize%2==1)
        right_size = left_size;
    else
        right_size = left_size-1;
    if(left_size == 0){
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
    if(right_size == 0){
        struct TreeNode* leaf = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        leaf->val = nums[0];
        leaf->left = NULL;
        leaf->right = NULL;
        tree->left = leaf;
        tree->right = NULL;
        return tree;
    }
    int left_arr[left_size];
    int right_arr[right_size];
    for(int i=0; i<numsSize; i++){
        if(i<left_size)
            left_arr[i] = nums[i];
        else if(i>left_size)
            right_arr[i-left_size-1] = nums[i];
    }
    tree->left = sortedArrayToBST(left_arr, left_size);
    tree->right = sortedArrayToBST(right_arr, right_size);
    return tree;
}

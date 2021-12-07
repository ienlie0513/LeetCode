/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    struct TreeNode *stack[100];
    int *nodes = (int *)malloc(sizeof(int)*100);
    
    int top = 0;
    *returnSize = 0;
    while(root || top){
        while(root){
            stack[top++] = root;
            root = root->left;
        }
        
        if(top){
            root = stack[top-1];
            nodes[(*returnSize)++] = root->val;
            top--;
        }
        
        root = root->right; 
    }
    return nodes;
}

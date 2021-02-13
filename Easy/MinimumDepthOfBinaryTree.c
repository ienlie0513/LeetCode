/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    int left=0, right=0;
    if(root->left)
        left = minDepth(root->left);
    if(root->right)
        right = minDepth(root->right);
    
    if(right == 0)
        return left+1;
    if(left == 0)
        return right+1;

    return left>right?right+1:left+1;
}

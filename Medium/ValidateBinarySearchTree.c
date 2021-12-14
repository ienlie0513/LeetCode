/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool valid(struct TreeNode* root, long long int max, long long int min){
    if(root == NULL)
        return true;
    
    if(root->val>=max || root->val<=min)
        return false;
    
    return valid(root->left, root->val, min) && valid(root->right, max, root->val);
}

bool isValidBST(struct TreeNode* root){
    return valid(root, LONG_MAX, LONG_MIN);
}

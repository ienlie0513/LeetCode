/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSubSymmetric(struct TreeNode* left, struct TreeNode* right){
    if(left == NULL && right == NULL)
        return true;
    if(left->val != right->val)
        return false;
    
    if((left->left == NULL && right->right) || (left->left && right->right == NULL))
        return false;
    if((left->right == NULL && right->left) || (left->right && right->left == NULL))
        return false;
        
    return isSubSymmetric(left->left, right->right) && isSubSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL || (root->right == NULL && root->left == NULL))
        return true;
    if(root->right == NULL || root->left == NULL)
        return false;
    
    return isSubSymmetric(root->left, root->right);
}

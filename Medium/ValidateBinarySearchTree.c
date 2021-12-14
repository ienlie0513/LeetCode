/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxVal(struct TreeNode* root){
    if(root->left == NULL && root->right == NULL)
        return root->val;
    
    if(root->left == NULL){
        int right = maxVal(root->right);
        return right>root->val ? right: root->val;
    }
    if(root->right == NULL){
        int left = maxVal(root->left);
        return left>root->val ? left: root->val;
    }
    
    int left = maxVal(root->left);
    int right = maxVal(root->right);
    
    if(left>right && left>root->val)
        return left;
    if(right>left && right>root->val)
        return right;
    
    return root->val;
}

int minVal(struct TreeNode* root){
    if(root->left == NULL && root->right == NULL)
        return root->val;
    
    if(root->left == NULL){
        int right = minVal(root->right);
        return right<root->val ? right: root->val;
    }
    if(root->right == NULL){
        int left = minVal(root->left);
        return left<root->val ? left: root->val;
    }
    
    int left = minVal(root->left);
    int right = minVal(root->right);
    
    if(left<right && left<root->val)
        return left;
    if(right<left && right<root->val)
        return right;
    
    return root->val;
}


bool isValidBST(struct TreeNode* root){
    if(root == NULL)
        return true;

    // max from left child < me
    if(root->left != NULL && maxVal(root->left) >= root->val)
        return false;
    // min from right child > me
    if(root->right != NULL && minVal(root->right) <= root->val)
        return false;
    
    return isValidBST(root->left) && isValidBST(root->right);
}

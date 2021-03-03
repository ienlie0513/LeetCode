/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int treeHeight(struct TreeNode* root){
    if(root == NULL)
        return 0;
    if(root->right == NULL && root->left == NULL)
        return 1;
    int left = treeHeight(root->left);
    int right = treeHeight(root->right);
    if(left-right>1||left-right<-1||left==-1||right==-1)
        return -1;
    
    return left>right?left+1:right+1;
}


bool isBalanced(struct TreeNode* root){
    if(root == NULL)
        return true;
    int left = treeHeight(root->left);
    int right = treeHeight(root->right);
    if(left-right>1||left-right<-1||left==-1||right==-1)
        return false;
    return true;
}

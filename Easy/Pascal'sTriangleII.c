

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex+1;
    int *ans = (int *)malloc(sizeof(int)*(rowIndex+1));
    
    ans[0] = 1;
    int left, right=1;
    for(int i=1;i<=rowIndex;i++){
        for(int j=1; j<i; j++){
            left = right;
            right = ans[j];
            ans[j] = left + right;
        }
        ans[i] = 1;
    }
    
    return ans;
}

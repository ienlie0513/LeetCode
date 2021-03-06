

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex+1;
    int *ans = (int *)malloc(sizeof(int)*(rowIndex+1));
    int temp[34], left, right = 1;
    for(int i=0; i<34; i++)
        temp[i] = 1;
    for(int i=0; i<rowIndex+1; i++){
        for(int j=1; j<i; j++){
            left = right;
            right = temp[j];
            temp[j] = left + right;
        }
    }
    for(int i=0; i<rowIndex+1; i++){
        ans[i] = temp[i];
    }
    return ans;
}

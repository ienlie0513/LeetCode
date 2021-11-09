

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    *returnSize = matSize*matColSize[0];
    int* ans = (int*)malloc(sizeof(int)*(*returnSize));
    
    int i=0, j=0, dir=0, k=0;
    while(i<matSize && j<matColSize[0]){
        ans[k] = mat[i][j];
        k++;
        if(dir == 0){
            if(j==(matColSize[0]-1)){
                i++;
                dir = !dir;
            }
            else if(i==0){
                j++;
                dir = !dir;
            }
            else{
                i--;
                j++;
            }
        }
        else{
            if(i==(matSize-1)){
                j++;
                dir = !dir;
            }
            else if(j==0){
                i++;
                dir = !dir;
            }
            else{
                i++;
                j--;
            }
        }
    }
    
    return ans;
}

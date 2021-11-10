

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize = matrixSize*matrixColSize[0];
    int* ans = (int*)malloc(sizeof(int)*(*returnSize));
    
    int left=0, right=matrixColSize[0]-1, up=1, down=matrixSize-1;
    int i=0, j=0, k=1, dir=0;
    ans[0] = matrix[i][j];
    while(k<(*returnSize)){
        if(dir == 0){
            if(j==right){
                right--;
                dir++;
            }
            else{
                j++;
            }
        }
        if(dir == 1){
            if(i==down){
                down--;
                dir++;
            }
            else{
                i++;
            }
        }
        if(dir == 2){
            if(j==left){
                left++;
                dir++;
            }
            else{
                j--;
            }
        }
        if(dir == 3){
            if(i==up){
                up++;
                dir=0;
                continue;
            }
            else{
                i--;
            }
        }
        ans[k]=matrix[i][j];
        k++;
    }
    
    return ans;
}

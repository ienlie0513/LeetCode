

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}

int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    int **ans = (int **)malloc(sizeof(int*)*matSize);
    for(int i=0; i<matSize; i++){
        ans[i] = (int *)malloc(sizeof(int)*(*matColSize));
    }
        
    int n_line = matSize+*matColSize-1;
    int size = (matSize>*matColSize)?*matColSize:matSize;
    int **tmp = (int **)malloc(sizeof(int*)*n_line);
    int *tsize = (int *)malloc(sizeof(int)*n_line);
    
    int i=matSize-1, j=0, t_i, t_j;
    for(int k=0; k<n_line; k++){
        tmp[k] = (int *)malloc(sizeof(int)*size);
        t_i = i;
        t_j = j;
        
        int t=0;
        while(t_i<matSize && t_j<*matColSize){
            tmp[k][t] = mat[t_i][t_j];
            t_i++;
            t_j++;
            t++;
        }
        tsize[k] = t;
        
        if(i>0)
            i--;
        else
            j++;
    }
    
    for(int k=0; k<n_line; k++){
        qsort(tmp[k], tsize[k], sizeof(int), cmp);
    }
    
    i = matSize-1; 
    j = 0;
    for(int k=0; k<n_line; k++){
        t_i = i;
        t_j = j;
        
        int t=0;
        while(t<tsize[k]){
            ans[t_i][t_j] = tmp[k][t];
            t_i++;
            t_j++;
            t++;
        }
        
        if(i>0)
            i--;
        else
            j++;
    }
        
    return ans;
}

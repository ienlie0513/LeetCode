void element_rotate(int** matrix, int matrixSize, int i, int j){
    int prev = matrix[i][j], t;
    for(int k=0; k<4; k++){
        t = matrix[j][matrixSize-1-i];
        matrix[j][matrixSize-1-i] = prev;
        prev = t;
        t = i;
        i = j;
        j = matrixSize-1-t;
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i=0, j=0;
    while(i<matrixSize/2){
        while(j<matrixSize-i-1){
            element_rotate(matrix, matrixSize, i, j);
            j++;
        }
        j = i+1;
        i++;
    }
}

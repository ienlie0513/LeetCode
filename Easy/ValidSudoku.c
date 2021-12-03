

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int n;
    // row
    for(int i=0; i<boardSize; i++){
        int row_check[9]={0};
        int col_check[9]={0};
        for(int j=0; j<*boardColSize; j++){
            n = board[i][j]-'0'>0 ? board[i][j]-'0': 0;
            if(n){
                if(row_check[n-1] != 0)
                    return false;
                row_check[n-1]++;
            }
            
            n = board[j][i]-'0'>0 ? board[j][i]-'0': 0;
            if(n){
                if(col_check[n-1] != 0)
                    return false;
                col_check[n-1]++;
            }
        }
    }
        
    // sqr
    for(int i=0; i<boardSize; i+=3){
        for(int j=0; j<*boardColSize; j+=3){
            int check[9]={0};
            for(int ii=i; ii<i+3; ii++){
                for(int jj=j; jj<j+3; jj++){
                    n = board[ii][jj]-'0'>0 ? board[ii][jj]-'0': 0;
                    if(n){
                        if(check[n-1] != 0)
                            return false;
                        check[n-1]++;
                    }
                }
            }
        }
    }
    return true;
}

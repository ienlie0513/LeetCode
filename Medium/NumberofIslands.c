void markIslands(char** grid, int gridSize, int* gridColSize, int i, int j){
       
    grid[i][j] = '0';
    if(i>0 && grid[i-1][j] == '1') 
        markIslands(grid, gridSize, gridColSize, i-1, j);
    if(j>0 && grid[i][j-1] == '1') 
        markIslands(grid, gridSize, gridColSize, i, j-1);
    if(i<gridSize-1 && grid[i+1][j] == '1') 
        markIslands(grid, gridSize, gridColSize, i+1, j);
    if(j<(*gridColSize)-1 && grid[i][j+1] == '1') 
        markIslands(grid, gridSize, gridColSize, i, j+1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int cnt = 0;
    
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<*gridColSize; j++){
            if(grid[i][j] == '1'){
                markIslands(grid, gridSize, gridColSize, i, j);
                cnt += 1;
            }
        }
    }
        
    return cnt;
}

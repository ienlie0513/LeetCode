int findTargetSumWays(int* nums, int numsSize, int target){
    int sum=0;
    for(int i=0; i<numsSize; i++)
        sum += nums[i];
    if(sum < target || -sum > target || (sum+target)%2 != 0)
        return 0;
    
    int new_target = (sum+target)/2;
    int **dp = (int **)malloc(sizeof(int*)*(numsSize+1));
    for(int i=0; i<numsSize+1; i++){
        dp[i] = (int *)malloc(sizeof(int)*(new_target+1));
        dp[i][0] = 1;
    }
    for(int i=1; i<new_target+1; i++)
        dp[0][i] = 0;

    for(int i=1; i<numsSize+1; i++){
        for(int j=0; j<new_target+1; j++){
            if(j-nums[i-1] >= 0)
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[numsSize][new_target];    
}

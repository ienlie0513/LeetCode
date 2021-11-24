int numSquares(int n){
    int dp[10000];
    
    for(int i=0; i<=n; i++){
        dp[i] = i;
        for(int j=1; i >= j*j ; j++){
            dp[i] = dp[i]>(dp[i-j*j]+1) ? (dp[i-j*j]+1): dp[i];
        }
    }
    
    return dp[n];
}

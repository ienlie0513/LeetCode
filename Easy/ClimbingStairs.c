int climbStairs(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    
    int prev_1 = 1;
    int prev_2 = 2;
    int ans;
    for(int i=0; i<n-2; i++){
        ans = prev_1 + prev_2;
        prev_1 = prev_2;
        prev_2 = ans;
    }
    return ans;
}

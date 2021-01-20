int reverse(int x){
    if(x==0) return 0;
    
    long long int ans = 0;
    long long int pos_x = x;
    bool ifne = false;
    
    if(pos_x < 0){
        pos_x = -pos_x;
        ifne = true;
    }
    
    while(pos_x > 0){
        ans *= 10;
        int tmp = pos_x % 10;
        ans += tmp;
        if(ans > 2147483648) return 0;
        pos_x /= 10;
    }
    
    if(ifne) ans = -ans;
    
    return ans;
}

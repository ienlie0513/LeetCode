bool isPalindrome(int x){
    if(x < 0) 
        return false;
    
    long int reverse = 0;
    int tmp = x;
    while(tmp > 0){
        reverse = reverse*10 + tmp%10;
        if(reverse >= INT_MAX || reverse <= INT_MIN)
            return false;
        tmp /= 10;
    }
    
    if(x == reverse)
        return true;
    else
        return false;

}

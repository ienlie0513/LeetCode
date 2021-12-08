

int myAtoi(char * s){
    while(*s == ' ')
        *s++;
    
    int sign = 1;
    if(*s == '-'){
        sign = -1;
        *s++;
    }
    else if(*s == '+')
        *s++;
    
    while(*s == '0')
        *s++;
        
    long long int tmp = 0;
    int cnt = 0;
    while(isdigit(*s) && cnt<11){
        tmp = tmp*10 + *s++ -'0';
        cnt++;
    }
    
    if(tmp*sign >= INT_MAX || (cnt>10 && sign==1))
        return INT_MAX;
    if(tmp*sign <= INT_MIN || (cnt>10 && sign==-1))
        return INT_MIN;
    return (int)tmp*sign;
}

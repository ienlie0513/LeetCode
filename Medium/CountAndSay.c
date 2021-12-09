

char * countAndSay(int n){
    if(n == 1)
        return "1\0";
    
    char *s = countAndSay(n-1);
    int cnt, idx=0;
    char prev;
    char *ans = calloc(5000, sizeof(char));
    while(*s != '\0'){
        prev = *s;
        cnt = 0;
        while(*s == prev){
            cnt++;
            *s++;
        }
        ans[idx++] = cnt + '0';
        ans[idx++] = prev;
    }
    
    return ans;
}

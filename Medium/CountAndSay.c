

char * countAndSay(int n){
    char *ans = calloc(18000, sizeof(char));
    char *tmp = calloc(18000, sizeof(char));
    
    int cnt, idx;
    char prev;
    *tmp = '1';
    *ans = '1';
    
    for(int i=2; i<=n; i++){
        idx = 0;
        while(*tmp != '\0'){
            prev = *tmp;
            cnt = 0;
            while(*tmp == prev){
                cnt++;
                *tmp++;
            }
            ans[idx++] = cnt + '0';
            ans[idx++] = prev;
        }
        ans[idx] = '\0';
        strcpy(tmp, ans);
    }
    
    return ans;
}

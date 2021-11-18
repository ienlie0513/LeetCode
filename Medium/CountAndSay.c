char * countAndSay(int n){
    if(n == 1){
        char *ans = (char *)malloc(sizeof(char)*4500);
        for(int i=0; i<4500; i++)
            ans[i] = '\0';
        ans[0] = '1';
        return ans;
    }
    else{
        char *ans = countAndSay(n-1);
        char word[strlen(ans)+1];
        strcpy(word, ans);
        int index = 0;
        int ans_index = 0;
        int i;
        for(i=0; i<strlen(word); i++){
            if(word[i] != word[index]){
                ans[ans_index] = i - index + 48;
                ans[ans_index+1] = word[index];
                index = i;
                ans_index += 2;
            }
        }
        ans[ans_index] = i - index + 48;
        ans[ans_index+1] = word[index];
        return ans;
    }
    return '0';
}

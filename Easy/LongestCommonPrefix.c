char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0)
        return "";
    char *ans = (char *)malloc(sizeof(char)*201);
    for(int i=0; i<201; i++)
        ans[i] = '\0';
    int idx=0;
    
    for(int i=0; i<strlen(strs[0]); i++){
        for(int j=1; j<strsSize; j++){
            if(strs[0][i] != strs[j][i]){
                return ans;
            }
        }
        ans[idx] = strs[0][i];
        idx++;
    }
    return ans;
}

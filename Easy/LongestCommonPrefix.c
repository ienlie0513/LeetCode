

char * longestCommonPrefix(char ** strs, int strsSize){
    for(int i=0; i<strsSize-1; i++){
        int len = strlen(strs[i])>strlen(strs[i+1])? strlen(strs[i+1]): strlen(strs[i]);
        if(!len)
            return "";
        for(int j=0; j<len; j++){
            if(strs[i][j] != strs[i+1][j]){
                strs[i+1][j] = '\0';
                break;
            }
        }
        if(strlen(strs[i+1])>len)
            strs[i+1][len] = '\0';
    }
    return strs[strsSize-1];
}

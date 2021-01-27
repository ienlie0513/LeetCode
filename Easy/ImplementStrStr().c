int strStr(char * haystack, char * needle){
    if(strlen(needle) == 0)
        return 0;
    int j;
    for(int i=0; i<strlen(haystack); i++){
        if(strlen(haystack)-i < strlen(needle))
            return -1;
        for(j=0; j<strlen(needle); j++){
            if(haystack[i+j] != needle[j])
                break;
        }
        if(j == strlen(needle))
            return i;
    }
    return -1;
}

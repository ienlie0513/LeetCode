

int firstUniqChar(char * s){
    int count[26] = {0}, len=strlen(s);
    
    for(int i=0; i<len; i++){
        count[s[i]-'a'] += 1;
    }
    
    for(int i=0; i<len; i++){
        if(count[s[i]-'a'] == 1)
            return i;
    }
    
    return -1;
}

bool closeStrings(char * word1, char * word2){
    if(strlen(word1) != strlen(word2))
        return false;
    
    int w1[26] = {0};
    int w2[26] = {0};
    int i;
    
    for(i=0; i<strlen(word1); i++){
        w1[word1[i]-97] += 1;
        w2[word2[i]-97] += 1;
    }
    
    for(i=0; i<26; i++){
        if(w1[i] == 0 && w2[i] != 0)
            return false;
        else if(w1[i] != 0 && w2[i] == 0)
            return false;            
    }
    
    for(i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(w1[i] !=0 && w1[i] == w2[j]){
                w2[j] = 0;
                break;
            }
        }
    }
        
    for(i=0; i<26; i++){
        if(w2[i]!=0)
            return false;
    }
    
    return true;
}

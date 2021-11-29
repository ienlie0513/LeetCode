

bool buddyStrings(char * s, char * goal){
    if(strlen(s)!=strlen(goal))
        return false;
    
    int idx = -1;
    for(int i=0; i<strlen(s); i++){
        if(s[i] != goal[i]){
            if(idx == -1){
                idx = i;
            }  
            else{
                char t = s[idx];
                s[idx] = s[i];
                s[i] = t;
                if(!strcmp(s, goal))
                    return true;
                else
                    return false;
            }
        }
    }
    
    if(idx == -1){
        int flag[26]={0};
            for(int i=0; i<strlen(s); i++){
                flag[s[i]-'a']++;
                if(flag[s[i]-'a']>1)
                    return true;
            }
    }
    
    
    return false;
}

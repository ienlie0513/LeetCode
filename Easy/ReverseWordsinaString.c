void reverse(char *s, int start, int end){
    char t;
    while(start<end){
        t=s[start];
        s[start] = s[end];
        s[end] = t;
        start++;
        end--;
    }
}

char *reverseWords(char * s){
    int i=0, j=0;
    while(s[i] == ' ')
        i++;
    
    for(; s[i]!='\0' ; i++){
        if(i!=0 && s[i] == ' ' && s[i-1] == ' '){
            continue;
        }
        s[j] = s[i];
        j++;
    }
    if(s[j-1] == ' ')
        s[j-1] = '\0';
    else
        s[j] = '\0';
    
    reverse(s, 0, strlen(s)-1);
    
    int k=0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == ' '){
            reverse(s, k, i-1);
            k = i+1;
        }
    }
    reverse(s, k, strlen(s)-1);
        
    return s;
}
